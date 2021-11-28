#include "myLib.h"

#define MAPHEIGHT 160 //change after background is made
#define MAPWIDTH 512 //change after background is made
#define OBJCOUNT 5 //drops 5 items in sequence 

//Variables
extern OBJ_ATTR shadowOAM[128];
extern int hOff;
extern int vOff;
extern ANISPRITE mamaBird;
extern int mamaBirdLife;
extern int birdsFed;

//Prototypes
void initGame();
void updateGame();
void drawGame();
void initLevel2();
void updateLevel2();
void drawLevel2();
void initPlayer();
void updatePlayer();
void animatePlayer();
void drawPlayer();
void initCat();
void updateCat();
void drawCat();
void initFish();
void updateFish();
void drawFish();
void initBabyBirds();
void updateBabyBirds();
void drawBabyBirds();
void initWorms();
void updateWorms();
void drawWorms();
void wormCollisionCheck();
void initFish();
void updateFish();
void drawFish();
void fishCollisionCheck();
void initYarn();
void updateYarn();
void drawYarn();
void yarnCollisionCheck();
void initFishText();
void initYarnText();
void initBirdsFedText();
void updateFallingObjects();
void drawFishText();
void drawBirdsFedText();
void drawBirdsFedAmount();
void drawFishAmount();
void drawYarnText();
void drawYarnAmount();
void drawFallingObjects();
void initBabyCardinals();
void drawBabyCardinals();
void initCat2();
void drawCat2();
void updateCat2();
void initLevel3();
void drawLevel3();


//struct for first cat
typedef struct {
    int row;
    int col;
    int rdel;
    int cdel;
    int width;
    int height;
    int aniCounter;
    int aniState;
    int prevAniState;
    int curFrame;
    int numFrames;
    int catDistracted;
} CAT;

//struct for second cat
typedef struct {
    int row;
    int col;
    int rdel;
    int cdel;
    int width;
    int height;
    int aniCounter;
    int aniState;
    int prevAniState;
    int curFrame;
    int numFrames;
    int catDistracted;
} CAT2;

//struct for baby birds
typedef struct {
    int row;
    int col;
    int rdel;
    int cdel;
    int width;
    int height;
    int aniCounter;
    int aniState;
    int prevAniState;
    int curFrame;
    int numFrames;
} BABYBIRD;

typedef struct {
    int row;
    int col;
    int rdel;
    int cdel;
    int width;
    int height;
    int aniCounter;
    int aniState;
    int prevAniState;
    int curFrame;
    int numFrames;
} BABYCARDINAL;

//struct for fish
typedef struct {
    int row;
    int col;
    int rdel;
    int cdel;
    int width;
    int height;
    int aniCounter;
    int aniState;
    int prevAniState;
    int curFrame;
    int numFrames;
    int visibleFrames;
    int isColliding;
} FISH;

//struct for falling fish
typedef struct {
    int row;
    int col;
    int rdel;
    int cdel;
    int width;
    int height;
    int aniCounter;
    int aniState;
    int prevAniState;
    int curFrame;
    int numFrames;
    int visibleFrames;
    int isColliding;
    int flag;
    int active;
} FALLINGOBJ;

//struct for worms
typedef struct {
    int row;
    int col;
    int rdel;
    int cdel;
    int width;
    int height;
    int aniCounter;
    int aniState;
    int prevAniState;
    int curFrame;
    int numFrames;
    int isColliding;
} WORM;

//struct for yarn
typedef struct {
    int row;
    int col;
    int width;
    int height;
    int curFrame;
    int numFrames;
    int isColliding;
} YARN;

typedef struct {
    int row;
    int col;
    int width;
    int height;
} FISHTEXT;

typedef struct {
    int row;
    int col;
    int width;
    int height;
} YARNTEXT;

typedef struct {
    int row;
    int col;
    int width;
    int height;
} BIRDSFEDTEXT;