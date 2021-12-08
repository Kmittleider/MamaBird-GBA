/* Finished basic artwork and animations although I want to make the win/lose/start screens more artsy and pleasant.
I also implemented a cheat (push the down button to receive 10 yarn, but can only receive when total yarnballs is below 10. 
Figred out how to make the worm disappear when collected and gone until the player feeds the baby birds and I rearranged 
the baby birds so they better fit in the nest. Still want to implement the transition screens between levels but didn't 
have time to get around to it. Audio is also applied (I have 7 unique sounds and I even did some sound editting in 
Audacity). Also added the background requirement in my pause state.
 
Again, game mechanics/how to play can be found in the instructions. */

#include <stdlib.h>
#include <stdio.h>
#include "myLib.h"
#include "start.h"
#include "game.h"
#include "pause.h"
#include "win.h"
#include "lose.h"
#include "background.h"
#include "level2Background.h"
#include "instructions.h"
#include "spritesheet.h"
#include "sound.h"
#include "gameSong.h"
#include "startSound.h"
#include "quickChirp.h"
#include "victory.h"
#include "defeat.h"
#include "angryCat.h"
#include "clouds.h"

// Prototypes
void initialize();

// State Prototypes
void goToStart();
void start();
void goToInstructions();
void instructions();
void goToGame();
void game();
void goToPause();
void pause();
void goToLevel2();
void level2();
void goToLevel3();
void level3();
void goToWin();
void win();
void goToLose();
void lose();

// States
enum
{
    START,
    INSTRUCTIONS,
    GAME,
    LEVEL2,
    LEVEL3,
    PAUSE,
    WIN,
    LOSE
};
int state;

//Variables
unsigned short buttons;
unsigned short oldButtons;
int level;
int aniCounter;
//bg2hOff
int bg2hOff;

// shadow oam
OBJ_ATTR shadowOAM[128];

int main()
{
    initialize();

    while (1)
    {
        // Update button variables
        oldButtons = buttons;
        buttons = BUTTONS;

        // State Machine
        switch (state)
        {
        case START:
            start();
            break;
        case INSTRUCTIONS:
            instructions();
            break;
        case GAME:
            game();
            break;
        case LEVEL2:
            level2();
            break;
        case LEVEL3:
            level3();
            break;
        case PAUSE:
            pause();
            break;
        case WIN:
            win();
            break;
        case LOSE:
            lose();
            break;
        }
    }
}

// Sets up GBA
void initialize()
{
    REG_DISPCTL = MODE0 | BG1_ENABLE | BG2_ENABLE | SPRITE_ENABLE; // Bitwise OR the BG(s) you want to use and Bitwise OR SPRITE_ENABLE if you want to use sprites
    // Don't forget to set up whatever BGs you enabled in the line above!
    REG_BG1CNT = BG_CHARBLOCK(0) | BG_SCREENBLOCK(30) | BG_SIZE_SMALL;
    REG_BG2CNT = BG_8BPP | BG_CHARBLOCK(1) | BG_SCREENBLOCK(31) | BG_SIZE_SMALL;

    buttons = BUTTONS;
    oldButtons = 0;

    //call setup functions for sounds and interrupts
    setupSounds();
    setupInterrupts();

    goToStart();
}

// Sets up the start state
void goToStart() {
    REG_BG1CNT = BG_8BPP | BG_CHARBLOCK(0) | BG_SCREENBLOCK(30) | BG_SIZE_SMALL;
    DMANow(3, startPal, PALETTE, 256);
    DMANow(3, startTiles, &CHARBLOCK[0], startTilesLen / 2);
    DMANow(3, startMap, &SCREENBLOCK[30], startMapLen / 2);
    REG_BG1VOFF = 0;
    REG_BG1HOFF = 0;

    stopSound();
    playSoundA(startSound_data, startSound_length, 1);

    state = START;
}

// Runs every frame of the start state
void start() {
    if (BUTTON_PRESSED(BUTTON_START)) {
        stopSound();
        playSoundA(gameSong_data, gameSong_length, 1);
        
        initGame();
        goToGame();
    } else if (BUTTON_PRESSED(BUTTON_A)) {
        pauseSound();
        goToInstructions();
    }
}

//Sets up instructions state
void goToInstructions() {
    REG_BG1CNT |= BG_8BPP;
    DMANow(3, instructionsPal, PALETTE, 256);
    DMANow(3, instructionsTiles, &CHARBLOCK[0], instructionsTilesLen / 2);
    DMANow(3, instructionsMap, &SCREENBLOCK[30], instructionsMapLen / 2);
    REG_BG1VOFF = 0;
    REG_BG1HOFF = 0;
    state = INSTRUCTIONS;
}

//Runs every frame of the instructions state
void instructions() {
    if (BUTTON_PRESSED(BUTTON_START) && level == 1) {
        unpauseSound();
        goToGame();
    } else if (BUTTON_PRESSED(BUTTON_SELECT)) {
        goToStart();
    } else if (BUTTON_PRESSED(BUTTON_START) && level == 2) {
        unpauseSound();
        goToLevel2();
    } else if (BUTTON_PRESSED(BUTTON_START) && level == 3) {
        unpauseSound();
        goToLevel3();
    }
}

// Sets up the game state
void goToGame() {
    REG_BG1CNT = BG_8BPP| BG_CHARBLOCK(0) | BG_SCREENBLOCK(30) | BG_SIZE_WIDE;
    
    //sprites
    DMANow(3, spritesheetTiles, &CHARBLOCK[4], spritesheetTilesLen / 2);
    DMANow(3, spritesheetPal, SPRITEPALETTE, spritesheetPalLen / 2);

    //need tile background
    DMANow(3, backgroundPal, PALETTE, 256);
    DMANow(3, backgroundTiles, &CHARBLOCK[0], backgroundTilesLen / 2);
    DMANow(3, backgroundMap, &SCREENBLOCK[30], backgroundMapLen / 2);

    hideSprites();
    DMANow(3, shadowOAM, OAM, 128 * 4);

    state = GAME;
    level = 1;
}

// Runs every frame of the first level game state
void game() {
    updateGame();
    drawGame();

    if (BUTTON_PRESSED(BUTTON_SELECT)) {
        hideSprites();
        DMANow(3, shadowOAM, OAM, 128 * 4);
        pauseSound();
        goToPause();
    } else if (birdsFed == 3) { //win condition for Level 1
        hideSprites();
        DMANow(3, shadowOAM, OAM, 128 * 4);
        
        stopSound();
        playSoundA(gameSong_data, gameSong_length, 1);

        initLevel2();
        goToLevel2();
    } else if (mamaBirdLife == 0) { //lose condition
        hideSprites();
        DMANow(3, shadowOAM,OAM, 128 * 4);
        pauseSound();
        goToLose();
    } else if (BUTTON_PRESSED(BUTTON_A)) {
        hideSprites();
        DMANow(3, shadowOAM, OAM, 128 * 4);
        pauseSound();
        goToInstructions();
    }
}

void goToLevel2() {
    REG_BG1CNT = BG_8BPP | BG_CHARBLOCK(0) | BG_SCREENBLOCK(30) | BG_SIZE_WIDE;
    
    //sprites
    DMANow(3, spritesheetTiles, &CHARBLOCK[4], spritesheetTilesLen / 2);
    DMANow(3, spritesheetPal, SPRITEPALETTE, spritesheetPalLen / 2);

    //need tile background
    DMANow(3, level2BackgroundPal, PALETTE, 256);
    DMANow(3, level2BackgroundTiles, &CHARBLOCK[0], level2BackgroundTilesLen / 2);
    DMANow(3, level2BackgroundMap, &SCREENBLOCK[30], level2BackgroundMapLen / 2);

    hideSprites();
    DMANow(3, shadowOAM, OAM, 128 * 4);

    state = LEVEL2;
    level = 2;
}

void level2() {
    updateGame();
    drawLevel2();

    if (BUTTON_PRESSED(BUTTON_SELECT)) {
        hideSprites();
        DMANow(3, shadowOAM,OAM, 128 * 4);
        pauseSound();
        goToPause();
    } else if (birdsFed == 6) { //win condition for level 2
        hideSprites();
        DMANow(3, shadowOAM,OAM, 128 * 4);

        stopSound();
        playSoundA(gameSong_data, gameSong_length, 1);

        initLevel3();
        goToLevel3();
    } else if (mamaBirdLife == 0) { //lose condition
        hideSprites();
        DMANow(3, shadowOAM,OAM, 128 * 4);
        pauseSound();
        goToLose();
    } else if (BUTTON_PRESSED(BUTTON_A)) {
        hideSprites();
        DMANow(3, shadowOAM,OAM, 128 * 4);
        pauseSound();
        goToInstructions();
    }
}

void goToLevel3() {
    REG_BG1CNT = BG_8BPP | BG_CHARBLOCK(0) | BG_SCREENBLOCK(30) | BG_SIZE_WIDE;
    
    //sprites
    DMANow(3, spritesheetTiles, &CHARBLOCK[4], spritesheetTilesLen / 2);
    DMANow(3, spritesheetPal, SPRITEPALETTE, spritesheetPalLen / 2);

    //need tile background
    DMANow(3, level2BackgroundPal, PALETTE, 256);
    DMANow(3, level2BackgroundTiles, &CHARBLOCK[0], level2BackgroundTilesLen / 2);
    DMANow(3, level2BackgroundMap, &SCREENBLOCK[30], level2BackgroundMapLen / 2);

    hideSprites();
    DMANow(3, shadowOAM, OAM, 128 * 4);

    state = LEVEL3;
    level = 3;
}

void level3() {
    updateLevel3();
    drawLevel3();

    if (BUTTON_PRESSED(BUTTON_SELECT)) {
        hideSprites();
        DMANow(3, shadowOAM,OAM, 128 * 4);
        pauseSound();
        goToPause();
    } else if (birdsFed == 6) { //win condition for level 3
        hideSprites();
        DMANow(3, shadowOAM,OAM, 128 * 4);
        pauseSound();
        goToWin();
    } else if (mamaBirdLife == 0) { //lose condition
        hideSprites();
        DMANow(3, shadowOAM,OAM, 128 * 4);
        pauseSound();
        goToLose();
    } else if (BUTTON_PRESSED(BUTTON_A)) {
        hideSprites();
        DMANow(3, shadowOAM,OAM, 128 * 4);
        pauseSound();
        goToInstructions();
    }
}

// Sets up the pause state
void goToPause() {
    REG_BG1CNT |= BG_8BPP;
    DMANow(3, cloudsPal, PALETTE, 256);
    DMANow(3, cloudsTiles, &CHARBLOCK[1], cloudsTilesLen / 2);
    DMANow(3, cloudsMap, &SCREENBLOCK[31], cloudsMapLen / 2);
    REG_BG2HOFF = 0;
    REG_BG2VOFF = 0;
    
    DMANow(3, pausePal, PALETTE, 256);
    DMANow(3, pauseTiles, &CHARBLOCK[0], pauseTilesLen / 2);
    DMANow(3, pauseMap, &SCREENBLOCK[30], pauseMapLen / 2);
    REG_BG1VOFF = 0;
    REG_BG1HOFF = 0;

    state = PAUSE;
}

// Runs every frame of the pause state
void pause() {
    aniCounter++;
    if (aniCounter % 5 == 0) {
        bg2hOff++;
        REG_BG2HOFF = bg2hOff;
    }
    
    waitForVBlank();
    if (BUTTON_PRESSED(BUTTON_START) && level == 1) {
        unpauseSound();
        goToGame();
    } else if (BUTTON_PRESSED(BUTTON_SELECT)) {
        goToStart();
    } else if (BUTTON_PRESSED(BUTTON_START) && level == 2) {
        unpauseSound();
        goToLevel2();
    } else if (BUTTON_PRESSED(BUTTON_START) && level == 3) {
        unpauseSound();
        goToLevel3();
    }
}

// Sets up the win state
void goToWin() {
    REG_BG1CNT |= BG_8BPP;
    waitForVBlank();
    DMANow(3, winPal, PALETTE, 256);
    DMANow(3, winTiles, &CHARBLOCK[0], winTilesLen / 2);
    DMANow(3, winMap, &SCREENBLOCK[30], winMapLen / 2);
    REG_BG1VOFF = 0;
    REG_BG1HOFF = 0;

    stopSound();
    playSoundA(quickChirp_data, quickChirp_length, 0);
    playSoundB(victory_data, victory_length, 0);
    state = WIN;
}

// Runs every frame of the win state
void win() {
    if (BUTTON_PRESSED(BUTTON_START)) {
        hideSprites();
        DMANow(3, shadowOAM, OAM, 128 * 4);
        initialize();
    }
}

// Sets up the lose state
void goToLose() {
    REG_BG1CNT |= BG_8BPP;
    DMANow(3, losePal, PALETTE, 256);
    DMANow(3, loseTiles, &CHARBLOCK[0], loseTilesLen / 2);
    DMANow(3, loseMap, &SCREENBLOCK[30], loseMapLen / 2);
    REG_BG1VOFF = 0;
    REG_BG1HOFF = 0;

    stopSound();
    playSoundA(defeat_data, defeat_length, 0);
    playSoundB(angryCat_data, angryCat_length, 0);
    state = LOSE;
}

// Runs every frame of the lose state
void lose() {
    if (BUTTON_PRESSED(BUTTON_START)) {
        hideSprites();
        DMANow(3, shadowOAM, OAM, 128 * 4);
        initialize();
    }
}