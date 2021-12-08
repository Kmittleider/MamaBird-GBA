
//{{BLOCK(level2Background)

//======================================================================
//
//	level2Background, 512x256@8, 
//	+ palette 256 entries, not compressed
//	+ 552 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x32 
//	Total size: 512 + 35328 + 4096 = 39936
//
//	Time-stamp: 2021-12-07, 23:17:54
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_LEVEL2BACKGROUND_H
#define GRIT_LEVEL2BACKGROUND_H

#define level2BackgroundTilesLen 35328
extern const unsigned short level2BackgroundTiles[17664];

#define level2BackgroundMapLen 4096
extern const unsigned short level2BackgroundMap[2048];

#define level2BackgroundPalLen 512
extern const unsigned short level2BackgroundPal[256];

#endif // GRIT_LEVEL2BACKGROUND_H

//}}BLOCK(level2Background)
