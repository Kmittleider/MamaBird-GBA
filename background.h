
//{{BLOCK(background)

//======================================================================
//
//	background, 512x256@8, 
//	+ palette 256 entries, not compressed
//	+ 552 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x32 
//	Total size: 512 + 35328 + 4096 = 39936
//
//	Time-stamp: 2021-12-07, 23:18:11
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BACKGROUND_H
#define GRIT_BACKGROUND_H

#define backgroundTilesLen 35328
extern const unsigned short backgroundTiles[17664];

#define backgroundMapLen 4096
extern const unsigned short backgroundMap[2048];

#define backgroundPalLen 512
extern const unsigned short backgroundPal[256];

#endif // GRIT_BACKGROUND_H

//}}BLOCK(background)
