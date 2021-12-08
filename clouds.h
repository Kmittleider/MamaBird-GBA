
//{{BLOCK(clouds)

//======================================================================
//
//	clouds, 256x256@8, 
//	+ palette 256 entries, not compressed
//	+ 124 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 7936 + 2048 = 10496
//
//	Time-stamp: 2021-12-07, 19:13:25
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CLOUDS_H
#define GRIT_CLOUDS_H

#define cloudsTilesLen 7936
extern const unsigned short cloudsTiles[3968];

#define cloudsMapLen 2048
extern const unsigned short cloudsMap[1024];

#define cloudsPalLen 512
extern const unsigned short cloudsPal[256];

#endif // GRIT_CLOUDS_H

//}}BLOCK(clouds)
