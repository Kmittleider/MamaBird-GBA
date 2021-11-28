/* Everything related to the basic game play is finished except for the artwork, audio, cheat and parallax 
background. To make the game more user friendly, I want to make the worm disappear when picked up by Mama Bird,
have transition screens between the levels for smoother game play, and other similar things to make the
game more authentic and playable. Game mechanics/how to play can be found in the instructions. In level
one, there is only 1 cat and 3 baby birds to feed. Feed all 3 without hitting the cat and you move on to 
level 2. Level 2 still has only 1 cat to avoid, but you now have to feed double the amount of baby birds.
Feed all 6 and you move on to level 3. Level three now has 2 cats and 6 hungry baby birds. Feed them all
and you win! If at any point you get hit by any of the cats, the game is lost. */

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
    REG_DISPCTL = MODE0 | BG1_ENABLE | SPRITE_ENABLE; // Bitwise OR the BG(s) you want to use and Bitwise OR SPRITE_ENABLE if you want to use sprites
    // Don't forget to set up whatever BGs you enabled in the line above!
    REG_BG1CNT = BG_CHARBLOCK(0) | BG_SCREENBLOCK(30) | BG_SIZE_SMALL;

    buttons = BUTTONS;
    oldButtons = 0;

    goToStart();
}

// Sets up the start state
void goToStart() {
    DMANow(3, startPal, PALETTE, 256);
    DMANow(3, startTiles, &CHARBLOCK[0], startTilesLen / 2);
    DMANow(3, startMap, &SCREENBLOCK[30], startMapLen / 2);
    REG_BG1VOFF = 0;
    REG_BG1HOFF = 0;
    state = START;
}

// Runs every frame of the start state
void start() {
    if (BUTTON_PRESSED(BUTTON_START)) {
        initGame();
        goToGame();
    } else if (BUTTON_PRESSED(BUTTON_A)) {
        goToInstructions();
    }
}

//Sets up instructions state
void goToInstructions() {
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
        goToGame();
    } else if (BUTTON_PRESSED(BUTTON_SELECT)) {
        goToStart();
    } else if (BUTTON_PRESSED(BUTTON_START) && level == 2) {
        goToLevel2();
    } else if (BUTTON_PRESSED(BUTTON_START) && level == 3) {
        goToLevel3();
    }
}

// Sets up the game state
void goToGame() {
    REG_BG1CNT = BG_CHARBLOCK(0) | BG_SCREENBLOCK(30) | BG_SIZE_WIDE;
    
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
        goToPause();
    } else if (birdsFed == 3) { //win condition for Level 1
        hideSprites();
        DMANow(3, shadowOAM, OAM, 128 * 4);
        initLevel2();
        goToLevel2();
    } else if (mamaBirdLife == 0) { //lose condition
        hideSprites();
        DMANow(3, shadowOAM,OAM, 128 * 4);
        goToLose();
    } else if (BUTTON_PRESSED(BUTTON_A)) {
        hideSprites();
        DMANow(3, shadowOAM, OAM, 128 * 4);
        goToInstructions();
    }
}

void goToLevel2() {
    REG_BG1CNT = BG_CHARBLOCK(0) | BG_SCREENBLOCK(30) | BG_SIZE_WIDE;
    
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
        goToPause();
    } else if (birdsFed == 6) { //win condition for level 2
        hideSprites();
        DMANow(3, shadowOAM,OAM, 128 * 4);
        //goToWin();
        initLevel3();
        goToLevel3();
    } else if (mamaBirdLife == 0) { //lose condition
        hideSprites();
        DMANow(3, shadowOAM,OAM, 128 * 4);
        goToLose();
    } else if (BUTTON_PRESSED(BUTTON_A)) {
        hideSprites();
        DMANow(3, shadowOAM,OAM, 128 * 4);
        goToInstructions();
    }
}

void goToLevel3() {
    REG_BG1CNT = BG_CHARBLOCK(0) | BG_SCREENBLOCK(30) | BG_SIZE_WIDE;
    
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
        goToPause();
    } else if (birdsFed == 6) { //win condition for level 3
        hideSprites();
        DMANow(3, shadowOAM,OAM, 128 * 4);
        goToWin();
    } else if (mamaBirdLife == 0) { //lose condition
        hideSprites();
        DMANow(3, shadowOAM,OAM, 128 * 4);
        goToLose();
    } else if (BUTTON_PRESSED(BUTTON_A)) {
        hideSprites();
        DMANow(3, shadowOAM,OAM, 128 * 4);
        goToInstructions();
    }
}

// Sets up the pause state
void goToPause() {
    DMANow(3, pausePal, PALETTE, 256);
    DMANow(3, pauseTiles, &CHARBLOCK[0], pauseTilesLen / 2);
    DMANow(3, pauseMap, &SCREENBLOCK[30], pauseMapLen / 2);
    REG_BG1VOFF = 0;
    REG_BG1HOFF = 0;
    state = PAUSE;
}

// Runs every frame of the pause state
void pause() {
    if (BUTTON_PRESSED(BUTTON_START) && level == 1) {
        goToGame();
    } else if (BUTTON_PRESSED(BUTTON_SELECT)) {
        goToStart();
    } else if (BUTTON_PRESSED(BUTTON_START) && level == 2) {
        goToLevel2();
    } else if (BUTTON_PRESSED(BUTTON_START) && level == 3) {
        goToLevel3();
    }
}

// Sets up the win state
void goToWin() {
    waitForVBlank();
    DMANow(3, winPal, PALETTE, 256);
    DMANow(3, winTiles, &CHARBLOCK[0], winTilesLen / 2);
    DMANow(3, winMap, &SCREENBLOCK[30], winMapLen / 2);
    REG_BG1VOFF = 0;
    REG_BG1HOFF = 0;
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
    DMANow(3, losePal, PALETTE, 256);
    DMANow(3, loseTiles, &CHARBLOCK[0], loseTilesLen / 2);
    DMANow(3, loseMap, &SCREENBLOCK[30], loseMapLen / 2);
    REG_BG1VOFF = 0;
    REG_BG1HOFF = 0;
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