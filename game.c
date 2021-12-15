#include "myLib.h"
#include "game.h"
#include "spritesheet.h"
#include "gameSong.h"
#include "meow.h"
#include "quickChirp.h"
#include "purr.h"

// defines gravity strength and player fly strength
#define GRAVITY -32         // acceleration due to gravity (y = xo + x*v - a^2)
#define GRAVITYFACTOR 0.05   // strength of gravity

//defines bounds for cat, worm, and fish movement
#define CATBOUNDRIGHT 247
#define CATBOUNDLEFT 42
#define FISHBOUNDLEFT 319
#define FISHBOUNDRIGHT 500
#define WORMBOUNDLEFT 263
#define WORMBOUNDRIGHT 42
#define WORMBOUNDUP 130
#define WORMBOUNDDOWN 150


//Variables
OBJ_ATTR shadowOAM[128];
ANISPRITE mamaBird;
CAT cat;
CAT2 cat2;
BABYBIRD babyBird[3];
BABYCARDINAL babyCardnial[3];
YARN yarn;
WORM worm;
FISH fish;
YARNTEXT yarnText;
FISHTEXT fishText;
BIRDSFEDTEXT birdsFedText;
FALLINGOBJ fallingObj[OBJCOUNT];


int mamaBirdLife = 1;
int birdsFed = 0;
int blueBirdsFed = 0;
int cardinalsFed = 0;
int collectedYarn = 0;
int collectedFish = 0;
int collectedWorm = 0;
int catDistractionTime = 0;
int cat2DistractionTime = 0;
int babyCollide;
int loseScreen;
int randCol;
int wormDisplay;
int randRow;
int hOff;
int vOff;
int level;

//Mamabird, babybird cat animation states for aniState
enum {MBRIGHT, MBLEFT, MBIDLE};
enum {BCRIGHT, BCLEFT};
enum {YCRIGHT, YCLEFT};
enum {FISHRIGHT, FISHLEFT};

//Initialize level 1
void initGame() {
    initPlayer();
    initCat();
    initBabyBirds();
    initWorms();
    initFish();
    initYarn();
    initFishText();
    initYarnText();
    initBirdsFedText();
    collectedYarn = 0;
    collectedFish = 0;
    collectedWorm = 0;
    blueBirdsFed = 0;
    mamaBirdLife = 1;
    birdsFed = 0;
    level = 1;
}

//Updates level 1
void updateGame() {
    updatePlayer();
    updateFallingObjects();
    for (int i = 0; i < 4; i++)
        updateBabyBirds(&babyBird[i]);
    for (int i = 0; i < 4; i++)
        updateBabyCardinals(&babyCardnial[i]);
    updateCat();
    updateFish();
    updateWorms();
}

void updateLevel3() {
    updatePlayer();
    updateFallingObjects();
    updateCat();
    for (int i = 0; i < 4; i++)
        updateBabyBirds(&babyBird[i]);
    for (int i = 0; i < 4; i++)
        updateBabyCardinals(&babyCardnial[i]);
    updateCat2();
    updateFish();
    updateWorms();
}

//Draws level 1 each frame
void drawGame() {
    drawPlayer();
    drawCat();
    drawFish();
    drawBabyBirds();
    drawWorms();
    drawYarn();
    drawFishText();
    drawYarnText();
    drawBirdsFedText();
    drawBirdsFedAmount();
    drawFishAmount();
    drawYarnAmount();
    drawFallingObjects();
    

    waitForVBlank();
    DMANow(3, shadowOAM, OAM, 128*4);
    REG_BG1HOFF = hOff;
    REG_BG1VOFF = vOff;
}

void initLevel2() {
    initPlayer();
    initCat();
    initBabyBirds();
    initBabyCardinals();
    initWorms();
    initFish();
    initYarn();
    initFishText();
    initYarnText();
    initBirdsFedText();
    collectedYarn = 0;
    collectedFish = 0;
    collectedWorm = 0;
    blueBirdsFed = 0;
    cardinalsFed = 0;
    mamaBirdLife = 1;
    birdsFed = 0;
    level = 2;
}

void drawLevel2() {
    drawPlayer();
    drawCat();
    drawFish();
    drawBabyBirds();
    drawWorms();
    drawYarn();
    drawFishText();
    drawYarnText();
    drawBirdsFedText();
    drawBirdsFedAmount();
    drawFishAmount();
    drawYarnAmount();
    drawFallingObjects();
    drawBabyCardinals();    

    waitForVBlank();
    DMANow(3, shadowOAM, OAM, 128*4);
    REG_BG1HOFF = hOff;
    REG_BG1VOFF = vOff;
}

void initLevel3() {
    initPlayer();
    initCat();
    initCat2();
    initBabyBirds();
    initBabyCardinals();
    initWorms();
    initFish();
    initYarn();
    initFishText();
    initYarnText();
    initBirdsFedText();
    collectedYarn = 0;
    collectedFish = 0;
    collectedWorm = 0;
    blueBirdsFed = 0;
    cardinalsFed = 0;
    mamaBirdLife = 1;
    birdsFed = 0;
    level = 3;
}

void drawLevel3() {
    drawPlayer();
    drawCat();
    drawFish();
    drawBabyBirds();
    drawWorms();
    drawYarn();
    drawFishText();
    drawYarnText();
    drawBirdsFedText();
    drawBirdsFedAmount();
    drawFishAmount();
    drawYarnAmount();
    drawFallingObjects();
    drawBabyCardinals();
    drawCat2();
    

    waitForVBlank();
    DMANow(3, shadowOAM, OAM, 128*4);
    REG_BG1HOFF = hOff;
    REG_BG1VOFF = vOff;
}

//Initialize mamaBird
void initPlayer() {
    mamaBird.width = 16;
    mamaBird.height = 16;
    mamaBird.rdel = 1;
    mamaBird.cdel = 1;

    //place in desired location
    mamaBird.row = 55;
    mamaBird.col = 192;
    mamaBird.aniCounter = 0;
    mamaBird.curFrame = 0;
    mamaBird.numFrames = 4;
    mamaBird.aniState = MBLEFT;
}

//Handle every-frame action of the player
void updatePlayer() {

    if (BUTTON_HELD(BUTTON_UP)) {
        if (mamaBird.row > 0)
            mamaBird.row -= mamaBird.rdel;
            mamaBird.velocity = -1;
            mamaBird.flyTimer = 0;
    } else {
        // checking BELOW if player can move, applying gravity and accounting for velocit    
        if (mamaBird.row - vOff + mamaBird.height - (int) round(mamaBird.velocity * GRAVITYFACTOR) < SCREENHEIGHT) {

            // using acceleration to update the players velocity
            mamaBird.velocity = (int) mamaBird.velocity + (GRAVITY * GRAVITYFACTOR) - 1;
            
            // applies current velocity to players position -- implement complex movement vertically if needed
            // gravity factor sets your gravity strength, i use something like 0.1
            mamaBird.row = (int) mamaBird.row - round(mamaBird.velocity * GRAVITYFACTOR);

        } else {
            mamaBird.velocity = 0; // grounds player if player is on ground    
        }
    }

    if (BUTTON_HELD(BUTTON_LEFT)) {
        if (mamaBird.col > 0) {
            mamaBird.col -= mamaBird.cdel;
            if (hOff > 0 && ((mamaBird.col - hOff) < (SCREENWIDTH / 2)))
                hOff--;
        }
    }

    if (BUTTON_HELD(BUTTON_RIGHT)) {
        if (mamaBird.col < MAPWIDTH - mamaBird.width) {
            mamaBird.col += mamaBird.cdel;
            if (hOff < (MAPWIDTH - SCREENWIDTH) && ((mamaBird.col - hOff) > (SCREENWIDTH / 2)))
                hOff++;
        }
    }

    animateMamaBird();

    if (collision(mamaBird.col, mamaBird.row, mamaBird.width - 4, mamaBird.height - 4, 
        cat.col, cat.row, cat.width, cat.height)) {
            mamaBirdLife = 0;
            loseScreen = 0;
    } else if (collision(mamaBird.col, mamaBird.row, mamaBird.width - 4, mamaBird.height - 4, 
        cat2.col, cat2.row, cat2.width, cat2.height)) {
            mamaBirdLife = 0;
            loseScreen = 1;
        }

    //doesn't allow player to spam click to gain yarn
    if (collision(mamaBird.col, mamaBird.row, mamaBird.width - 4, mamaBird.height - 4, 
        yarn.col, yarn.row, yarn.width, yarn.height)) {
            if (yarn.isColliding == 0 && BUTTON_PRESSED(BUTTON_B)) {
                collectedYarn += 1;
                yarn.isColliding = 1;
                playSoundB(quickChirp_data, quickChirp_length, 0);
            }
    } else {
        yarn.isColliding = 0;
    }

    //doesn't allow player to spam click to gain fish
    if (collision(mamaBird.col, mamaBird.row, mamaBird.width - 4, mamaBird.height - 4, 
        fish.col, fish.row, fish.width, fish.height)) {
            if (fish.isColliding == 0 && BUTTON_PRESSED(BUTTON_B)) {
                collectedFish += 1;
                fish.isColliding = 1;
                playSoundB(quickChirp_data, quickChirp_length, 0);
            }
    } else {
        fish.isColliding = 0;
    }

    //doesn't allow player to spam click to gain worm
    if (collision(mamaBird.col, mamaBird.row, mamaBird.width - 4, mamaBird.height - 4, 
        worm.col, worm.row, worm.width, worm.height) && collectedWorm < 2) {
            if (worm.isColliding == 0  && BUTTON_PRESSED(BUTTON_B)) {
                collectedWorm = 1;
                worm.isColliding = 1;
                playSoundB(quickChirp_data, quickChirp_length, 0);
            }
    } else {
        worm.isColliding = 0;
    }

    //feed baby bird (numbers in second part of collision check are the dimensions of the blue bird nest)
    //makes sure you don't unfairly feed the nests, hence the blueBirdsFed and cardinalsFed, must be 3 each nest
    if (collision(mamaBird.col, mamaBird.row, mamaBird.width - 4, mamaBird.height - 4, 
        190, 78, 20, 4) && collectedWorm > 0 && blueBirdsFed <= 3 && birdsFed < 3) {
            collectedWorm--;
            babyBird[blueBirdsFed].isFed = 1;
            birdsFed++;
            blueBirdsFed++;
            playSoundB(quickChirp_data, quickChirp_length, 0);
    } else if (collision(mamaBird.col, mamaBird.row, mamaBird.width-4, mamaBird.height - 4,
        231, 76, 15, 5) && collectedWorm > 0 && cardinalsFed <= 3 && birdsFed >= 3) {
            collectedWorm--;
            babyCardnial[cardinalsFed].isFed = 1;
            birdsFed++;
            cardinalsFed++;
            playSoundB(quickChirp_data, quickChirp_length, 0);
        }

    //dropping yarn on cat
    if (BUTTON_PRESSED(BUTTON_R) && collectedYarn > 0) {
        collectedYarn--;
        dropFallingObjects(1);
    }

    //dropping fish on cat
    if (BUTTON_PRESSED(BUTTON_L) && collectedFish > 0) {
        collectedFish--;
        dropFallingObjects(2);
    }

    if (BUTTON_PRESSED(BUTTON_DOWN) && collectedYarn < 10)
        collectedYarn += 10;
}

//Handle player animation states
void animateMamaBird() {
    mamaBird.prevAniState = mamaBird.aniState;
    mamaBird.aniState = MBIDLE;

    //Change the animation frame every 7 frames of gameplay
    if (mamaBird.aniCounter % 7 == 0)
        mamaBird.curFrame = (mamaBird.curFrame + 1) % mamaBird.numFrames;

    if (BUTTON_HELD(BUTTON_LEFT) || BUTTON_HELD(BUTTON_UP))
        mamaBird.aniState = MBLEFT;
    if (BUTTON_HELD(BUTTON_RIGHT))
        mamaBird.aniState = MBRIGHT;
    //may need to add just button up

    //if mamaBird is idle, frame is mamabird still
    if (mamaBird.aniState == MBIDLE) {
        mamaBird.curFrame = 0;
        mamaBird.aniCounter = 0;
        mamaBird.aniState = mamaBird.prevAniState;
    } else
        mamaBird.aniCounter++;
}

//Draw Mama bird
void drawPlayer() {
    if (mamaBird.hide) {
        shadowOAM[0].attr0 |= ATTR0_HIDE;
    } else {
        shadowOAM[0].attr0 = (ROWMASK & (mamaBird.row - vOff)) | ATTR0_SQUARE | ATTR0_REGULAR;
        shadowOAM[0].attr1 = (COLMASK & (mamaBird.col - hOff)) | ATTR1_SMALL;
        shadowOAM[0].attr2 = ATTR2_PALROW(0) | ATTR2_TILEID(mamaBird.aniState * 2, mamaBird.curFrame * 2);
    }
}

//drop the objects
void dropFallingObjects(int type) {
    for (int i = 0; i < OBJCOUNT; i++) {
        if (!fallingObj[i].active) {
            fallingObj[i].rdel = 2;
            fallingObj[i].col = mamaBird.col;
            fallingObj[i].row = mamaBird.row;
            fallingObj[i].flag = type;
            if (type == 1) {
                yarn.width = 4;
                yarn.height = 4;
            } else {
                fish.width = 16;
                fish.height = 4;
            }
            fallingObj[i].active = 1;
            break;
        }
    }
}

void updateFallingObjects() {
    for (int i = 0; i < OBJCOUNT; i++) {
        if (fallingObj[i].active) {
            fallingObj[i].row += fallingObj[i].rdel;
            //checks the collision with the first cat
            if (collision(cat.col, cat.row, cat.width, cat.height, 
                fallingObj[i].col, fallingObj[i].row, fallingObj[i].width, fallingObj[i].height)) {
                    if (fallingObj[i].flag == 1) {
                        catDistractionTime = 120;
                        playSoundB(meowSound_data, meowSound_length, 0);
                        updateCat();
                    } else {
                        catDistractionTime = 200;
                        playSoundB(purr_data, purr_length, 0);
                        updateCat();
                    }
                    fallingObj[i].active = 0;
            } //checks collision with the second cat
            else if (collision(cat2.col, cat2.row, cat2.width, cat2.height,
                fallingObj[i].col, fallingObj[i].row, fallingObj[i].width, fallingObj[i].height)) {
                    if (fallingObj[i].flag == 1) {
                        cat2DistractionTime = 120;
                        playSoundB(meowSound_data, meowSound_length, 0);
                        updateCat2();
                    } else {
                        cat2DistractionTime = 200;
                        playSoundB(purr_data, purr_length, 0);
                        updateCat2();
                    }
                    fallingObj[i].active = 0;
                }
            if (fallingObj[i].row > SCREENHEIGHT) {
                fallingObj[i].active = 0;
            }
        }
    }
}

//draws falling object
void drawFallingObjects() {
    for (int i = 0; i < OBJCOUNT; i++) {
        if (!fallingObj[i].active) {
            shadowOAM[i + 20].attr0 = ATTR0_HIDE;
        } else {
            if (fallingObj[i].flag == 1) {
                shadowOAM[i + 20].attr0 = (ROWMASK & (fallingObj[i].row - vOff)) | ATTR0_SQUARE | ATTR0_REGULAR;
                shadowOAM[i + 20].attr1 = (COLMASK & (fallingObj[i].col - hOff)) | ATTR1_TINY;
                shadowOAM[i + 20].attr2 = ATTR2_PALROW(0) | ATTR2_TILEID(9, 1);
            } else {
                shadowOAM[i + 20].attr0 = (ROWMASK & (fallingObj[i].row - vOff)) | ATTR0_WIDE | ATTR0_REGULAR;
                shadowOAM[i + 20].attr1 = (COLMASK & (fallingObj[i].col - hOff)) | ATTR1_TINY;
                shadowOAM[i + 20].attr2 = ATTR2_PALROW(0) | ATTR2_TILEID(10, 0);
            }
        }
    }
}

//Initialize the cat
void initCat() {
    cat.row = 143;
    cat.col = 247;
    cat.rdel = 0;
    cat.cdel = -1;
    cat.width = 23;
    cat.height = 12;
    cat.aniCounter = 0;
    cat.prevAniState = 0;
    cat.curFrame = 0;
    cat.numFrames = 4;
    catDistractionTime = 0;
    cat.aniState = BCLEFT;
}

//Handle every-frame action of the cat
void updateCat() {

    if (catDistractionTime > 0) {
        catDistractionTime--;
        cat.aniCounter = 0;
    } else {
        //move cat
        cat.col += cat.cdel;
        if (cat.col == CATBOUNDLEFT) { //right
            cat.aniState = BCRIGHT;
            cat.cdel = 1;
        }

        if (cat.col == CATBOUNDRIGHT) { //left
            cat.aniState = BCLEFT;
            cat.cdel = -1;
        }

        cat.aniCounter++;
        if (cat.aniCounter % 7 == 0) {
            cat.curFrame++;
            if (cat.curFrame == cat.numFrames)
                cat.curFrame = 0;
        }
    }
}

//Draw Cat
void drawCat() {
    shadowOAM[1].attr0 = (ROWMASK & (cat.row - vOff)) | ATTR0_WIDE | ATTR0_REGULAR;
    shadowOAM[1].attr1 = (COLMASK & (cat.col - hOff)) | ATTR1_MEDIUM;
    shadowOAM[1].attr2 = ATTR2_PALROW(0) | ATTR2_TILEID(cat.aniState * 3, 8 + cat.curFrame * 2);
}

void initCat2() {
    cat2.row = 130;
    cat2.col = 95;
    cat2.rdel = 0;
    cat2.cdel = -1;
    cat2.width = 24;
    cat2.height = 16;
    cat2.aniCounter = 0;
    cat2.prevAniState = 0;
    cat2.curFrame = 0;
    cat2.numFrames = 4;
    cat2DistractionTime = 0;
    cat2.aniState = YCLEFT;
}

void updateCat2() {
    if (cat2DistractionTime > 0) {
        cat2DistractionTime--;
        cat2.aniCounter = 0;
    } else {
        //move cat
        cat2.col += cat2.cdel;
        if (cat2.col == CATBOUNDLEFT) { //right
            cat2.aniState = YCRIGHT;
            cat2.cdel = 1;
        }

        if (cat2.col == CATBOUNDRIGHT) { //left
            cat2.aniState = YCLEFT;
            cat2.cdel = -1;
        }

        cat2.aniCounter++;
        if (cat2.aniCounter % 7 == 0) {
            cat2.curFrame++;
            if (cat2.curFrame == cat2.numFrames)
                cat2.curFrame = 0;
        }
    } 
}

void drawCat2() {
    shadowOAM[19].attr0 = (ROWMASK & (cat2.row - vOff)) | ATTR0_WIDE | ATTR0_REGULAR;
    shadowOAM[19].attr1 = (COLMASK & (cat2.col - hOff)) | ATTR1_MEDIUM;
    shadowOAM[19].attr2 = ATTR2_PALROW(0) | ATTR2_TILEID(cat2.aniState * 3, 16 + cat2.curFrame * 2);
}

//Initialize the fish
void initFish() {
    fish.row = 146;
    fish.col = 352;
    fish.rdel = 0;
    fish.cdel = -1;
    fish.width = 10;
    fish.height = 6;
    fish.swimLeft = 0;
    fish.aniState = 0;
}

//Handle every-frame action of the fish
void updateFish() {
    //move fish
    fish.col += fish.cdel;
    if (fish.col == FISHBOUNDLEFT) { //right
        fish.cdel = 1;
        fish.aniState = FISHRIGHT;
        fish.swimLeft = 0;
    }
    if (fish.col == FISHBOUNDRIGHT)  { //left
        fish.cdel = -1;
        fish.aniState = FISHLEFT;
        fish.swimLeft = 1;
    }
}

//Draw fish
void drawFish() {
    shadowOAM[2].attr0 = (ROWMASK & (fish.row - vOff)) | ATTR0_WIDE | ATTR0_REGULAR;
    shadowOAM[2].attr1 = (COLMASK & (fish.col - hOff)) | ATTR1_TINY;
    if (fish.swimLeft == 0) //right
        shadowOAM[2].attr2 = ATTR2_PALROW(0) | ATTR2_TILEID(8 + fish.aniState * 2, 0);
    else //left
        shadowOAM[2].attr2 = ATTR2_PALROW(0) | ATTR2_TILEID(8 + fish.aniState * 2, 0);
}

//Initialize the baby birds
void initBabyBirds() {
    for (int i = 0; i < 3; i++) {
        if (i < 2) {
            babyBird[i].row = 74;
            babyBird[i].col = 195 + (i * 5);
            babyBird[i].rdel = 1;
            babyBird[i].cdel = 1;
            babyBird[i].width = 7;
            babyBird[i].height = 7;
            babyBird[i].aniCounter = 0;
            babyBird[i].prevAniState = 0;
            babyBird[i].curFrame = 0;
            babyBird[i].isFed = 0;
            babyBird[i].numFrames = 2;
        } else {
            babyBird[i].row = 71;
            babyBird[i].col = 198;
            babyBird[i].rdel = 1;
            babyBird[i].cdel = 1;
            babyBird[i].width = 7;
            babyBird[i].height = 7;
            babyBird[i].aniCounter = 0;
            babyBird[i].prevAniState = 0;
            babyBird[i].curFrame = 0;
            babyBird[i].isFed = 0;
            babyBird[i].numFrames = 2;
        }
    }
}

//Draw baby birds
void drawBabyBirds() {
    for (int i = 0; i < 3; i++) {
        shadowOAM[3 + i].attr0 = (ROWMASK & (babyBird[i].row - vOff)) | ATTR0_SQUARE | ATTR0_REGULAR;
        shadowOAM[3 + i].attr1 = (COLMASK & (babyBird[i].col - hOff)) | ATTR1_TINY;
        
        //if babyBird fed
        if (babyBird[i].isFed == 1)
            shadowOAM[3 + i].attr2 = ATTR2_PALROW(0) | ATTR2_TILEID(7, 0);
        //if not collided, babyBird still hungry
        else 
            shadowOAM[3 + i].attr2 = ATTR2_PALROW(0) | ATTR2_TILEID(5 + babyBird[i].curFrame, 0);
    }
}

void updateBabyBirds(BABYBIRD* babyBird) {
    babyBird->aniCounter++;
    if (babyBird->aniCounter % 10 == 0) {
        babyBird->curFrame++;
        if (babyBird->curFrame == babyBird->numFrames)
            babyBird->curFrame = 0;
    }
}

//initialize the baby cardinals
void initBabyCardinals() {
    for (int i = 0; i < 3; i++) {
        if (i < 2) {
            babyCardnial[i].row = 74;
            babyCardnial[i].col = 231 + (i * 6);
            babyCardnial[i].rdel = 1;
            babyCardnial[i].cdel = 1;
            babyCardnial[i].width = 7;
            babyCardnial[i].height = 7;
            babyCardnial[i].aniCounter = 0;
            babyCardnial[i].prevAniState = 0;
            babyCardnial[i].curFrame = 0;
            babyCardnial[i].numFrames = 2;
            babyCardnial[i].isFed = 0;
        } else {
            babyCardnial[i].row = 71;
            babyCardnial[i].col = 234;
            babyCardnial[i].rdel = 1;
            babyCardnial[i].cdel = 1;
            babyCardnial[i].width = 7;
            babyCardnial[i].height = 7;
            babyCardnial[i].aniCounter = 0;
            babyCardnial[i].prevAniState = 0;
            babyCardnial[i].curFrame = 0;
            babyCardnial[i].numFrames = 2;
            babyCardnial[i].isFed = 0;
        }
    }
}

//Draw baby cardinals
void drawBabyCardinals() {
    for (int i = 0; i < 3; i++) {
        shadowOAM[16 + i].attr0 = (ROWMASK & (babyCardnial[i].row - vOff)) | ATTR0_SQUARE | ATTR0_REGULAR;
        shadowOAM[16 + i].attr1 = (COLMASK & (babyCardnial[i].col - hOff)) | ATTR1_TINY;
        
        //if babyCardinal fed
        if (babyCardnial[i].isFed == 1)
            shadowOAM[16 + i].attr2 = ATTR2_PALROW(0) | ATTR2_TILEID(7, 3);
        //if not collided, babyBird still hungry
        else 
            shadowOAM[16 + i].attr2 = ATTR2_PALROW(0) | ATTR2_TILEID(5 + babyCardnial[i].curFrame, 3);
    }
}

void updateBabyCardinals(BABYCARDINAL* babyCardnial) {
    babyCardnial->aniCounter++;
    if (babyCardnial->aniCounter % 10 == 0) {
        babyCardnial->curFrame++;
        if (babyCardnial->curFrame == babyCardnial->numFrames)
            babyCardnial->curFrame = 0;
    }
}

//Initialise the worms
void initWorms() {
    worm.row = 147;
    worm.col = 58;
    worm.rdel = 1;
    worm.cdel = 1;
    worm.width = 3;
    worm.height = 8;
}

//Handle every-frame action of the worms
void updateWorms() {
    if (wormDisplay > 0) {
        wormDisplay--;
    } else {
        randCol = (rand() % (WORMBOUNDLEFT - WORMBOUNDRIGHT + 1)) + WORMBOUNDRIGHT;
        worm.col = randCol;
        randRow = (rand() % (WORMBOUNDDOWN - WORMBOUNDUP + 1)) + WORMBOUNDUP;
        worm.row = randRow;
        wormDisplay = 300;
    }
}

//draws worms
void drawWorms() {
    shadowOAM[6].attr0 = (ROWMASK & (worm.row - vOff)) | ATTR0_SQUARE | ATTR0_REGULAR;
    shadowOAM[6].attr1 = (COLMASK & (worm.col - hOff)) | ATTR1_TINY;
    if (collectedWorm == 0)
        shadowOAM[6].attr2 = ATTR2_PALROW(0) | ATTR2_TILEID(10, 1);
    else
        shadowOAM[6].attr2 = ATTR2_PALROW(0) | ATTR2_TILEID(11, 1);
}

//initalize 
void initYarn() {
    yarn.row = 135;
    yarn.col = 27;
    yarn.width = 4;
    yarn.height = 4;
}


//draws yarn
void drawYarn() {
    shadowOAM[7].attr0 = (ROWMASK & (yarn.row - vOff)) | ATTR0_SQUARE | ATTR0_REGULAR;
    shadowOAM[7].attr1 = (COLMASK & (yarn.col - hOff)) | ATTR1_TINY;
    shadowOAM[7].attr2 = ATTR2_PALROW(0) | ATTR2_TILEID(9, 1);
}

void initFishText() {
    fishText.row = 4;
    fishText.col = 8;
    fishText.width = 24;
    fishText.height = 8;
}

void drawFishText() {
    shadowOAM[8].attr0 = (ROWMASK & fishText.row) | ATTR0_WIDE | ATTR0_REGULAR;
    shadowOAM[8].attr1 = (COLMASK & fishText.col) | ATTR1_SMALL;
    shadowOAM[8].attr2 = ATTR2_PALROW(0) | ATTR2_TILEID(24, 4);
}

void drawFishAmount() {
    for (int i = 0; i < 2; i++) {
        shadowOAM[9 + i].attr0 = 4 | ATTR0_REGULAR | ATTR0_SQUARE | ATTR0_REGULAR;
        shadowOAM[9 + i].attr1 = (32 + (8 * i)) | ATTR1_TINY;
    }
    shadowOAM[9].attr2 = ATTR2_TILEID(12 +(collectedFish % 100) / 10, 0);
    shadowOAM[10].attr2 = ATTR2_TILEID(12 + (collectedFish % 10), 0);
}

void initYarnText() {
    yarnText.row = 14;
    yarnText.col = 8;
    yarnText.width = 56;
    yarnText.height = 8;
}

void drawYarnText() {
    shadowOAM[11].attr0 = (ROWMASK & yarnText.row) | ATTR0_WIDE | ATTR0_REGULAR;
    shadowOAM[11].attr1 = (COLMASK & yarnText.col) | ATTR1_LARGE;
    shadowOAM[11].attr2 = ATTR2_PALROW(0) | ATTR2_TILEID(24, 0);
}

void drawYarnAmount() {
    for (int i = 0; i < 2; i++) {
        shadowOAM[12 + i].attr0 = 14 | ATTR0_REGULAR | ATTR0_SQUARE | ATTR0_REGULAR;
        shadowOAM[12 + i].attr1 = (64 + (8 * i)) | ATTR1_TINY;
    }
    shadowOAM[12].attr2 = ATTR2_TILEID(12 +(collectedYarn % 100) / 10, 0);
    shadowOAM[13].attr2 = ATTR2_TILEID(12 + (collectedYarn % 10), 0);
}

void initBirdsFedText() {
    birdsFedText.row = 24;
    birdsFedText.col = 8;
    birdsFedText.width = 56;
    birdsFedText.height = 8;
}

void drawBirdsFedText() {
    shadowOAM[14].attr0 = (ROWMASK & birdsFedText.row) | ATTR0_WIDE | ATTR0_REGULAR;
    shadowOAM[14].attr1 = (COLMASK & birdsFedText.col) | ATTR1_LARGE;
    shadowOAM[14].attr2 = ATTR2_PALROW(0) | ATTR2_TILEID(9, 2);
}

void drawBirdsFedAmount() {
    shadowOAM[15].attr0 = 24 | ATTR0_REGULAR | ATTR0_SQUARE | ATTR0_REGULAR;
    shadowOAM[15].attr1 = 64 | ATTR1_TINY;
    shadowOAM[15].attr2 = ATTR2_TILEID(12 + (birdsFed % 10), 0);
}