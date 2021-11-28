
//{{BLOCK(win)

//======================================================================
//
//	win, 256x256@4, 
//	+ palette 256 entries, not compressed
//	+ 78 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 2496 + 2048 = 5056
//
//	Time-stamp: 2021-11-12, 22:02:17
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

const unsigned short winTiles[1248] __attribute__((aligned(4)))=
{
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x1100,0x0000,0x1000,0x0000,0x1000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0001,0x0000,0x0001,0x0000,0x0011,0x0000,
	0x0011,0x0000,0x0110,0x1000,0x1110,0x1100,0x1100,0x1100,
	0x0000,0x0000,0x1110,0x0000,0x0110,0x0000,0x0111,0x0000,
	0x0011,0x1000,0x0001,0x1000,0x0001,0x1100,0x0000,0x1100,

	0x0000,0x0000,0x1000,0x1111,0x1110,0x1111,0x1111,0x0000,
	0x0011,0x0000,0x0001,0x0000,0x0001,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0011,0x0000,0x1111,0x0000,0x1110,0x0001,
	0x1000,0x0011,0x0000,0x0011,0x0000,0x0111,0x0000,0x0110,
	0x0000,0x0000,0x1100,0x0000,0x1100,0x0000,0x1100,0x0000,
	0x1100,0x0000,0x1100,0x0000,0x1100,0x0000,0x1100,0x0000,
	0x0000,0x0000,0x0000,0x1100,0x0000,0x1100,0x0000,0x1100,
	0x0000,0x1100,0x0000,0x1100,0x0000,0x1100,0x0000,0x1100,

	0x0000,0x0000,0x1000,0x0001,0x1000,0x0001,0x0000,0x0011,
	0x0000,0x0011,0x0000,0x0011,0x0000,0x0111,0x0000,0x0110,
	0x0000,0x0000,0x0000,0x0110,0x0000,0x1111,0x0000,0x1111,
	0x0000,0x1111,0x0000,0x1111,0x1000,0x1001,0x1000,0x1001,
	0x0000,0x0000,0x0000,0x1000,0x0000,0x1000,0x0000,0x1100,
	0x0000,0x1100,0x0000,0x1100,0x0001,0x1110,0x0001,0x0110,
	0x0000,0x0000,0x0001,0x0000,0x0001,0x1100,0x0000,0x1110,
	0x0000,0x0111,0x0000,0x0011,0x1000,0x0011,0x1000,0x0001,

	0x0000,0x0000,0x1111,0x0111,0x1111,0x1111,0x0001,0x1100,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x1000,0x0001,0x1000,0x0011,0x1000,
	0x0111,0x1000,0x0110,0x1000,0x1110,0x1000,0x1100,0x1000,
	0x0000,0x0000,0x0111,0x0000,0x0111,0x0000,0x1111,0x0000,
	0x1101,0x0001,0x1101,0x0001,0x1001,0x0011,0x0001,0x0011,
	0x0000,0x0000,0x1000,0x0001,0x1000,0x0001,0x1000,0x0001,
	0x1000,0x0001,0x1000,0x0001,0x1000,0x0001,0x1000,0x0001,

	0x1100,0x1111,0x1000,0x0111,0x0000,0x0011,0x0000,0x0011,
	0x0000,0x0011,0x0000,0x0011,0x0000,0x0011,0x0000,0x0011,
	0x0000,0x1100,0x0000,0x1100,0x0000,0x1100,0x0000,0x1100,
	0x0000,0x1100,0x0000,0x1100,0x0000,0x1000,0x0000,0x1000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0001,0x0000,0x0001,0x0000,0x0011,0x0000,
	0x0000,0x0110,0x0000,0x0110,0x0000,0x0110,0x0000,0x0110,
	0x0000,0x0110,0x0000,0x0111,0x0000,0x0011,0x1000,0x0011,

	0x1100,0x0000,0x1100,0x0000,0x1100,0x0000,0x1100,0x0000,
	0x1100,0x0000,0x1100,0x0000,0x1100,0x0000,0x1000,0x0001,
	0x0000,0x1100,0x0000,0x1100,0x0000,0x1100,0x0000,0x1100,
	0x0000,0x1100,0x0000,0x1100,0x0000,0x1100,0x0000,0x0110,
	0x0000,0x0110,0x0000,0x0110,0x0000,0x1110,0x0000,0x1100,
	0x0000,0x1100,0x0000,0x1100,0x0000,0x1000,0x0000,0x1000,
	0x1000,0x1001,0x1000,0x1001,0x1000,0x0000,0x1100,0x0000,
	0x1100,0x0000,0x1100,0x0000,0x0101,0x0000,0x0111,0x0000,

	0x0001,0x0110,0x0001,0x0110,0x0011,0x0111,0x0011,0x0011,
	0x0011,0x0011,0x0011,0x0011,0x1110,0x0011,0x1110,0x0001,
	0x1000,0x0001,0x1000,0x0001,0x1000,0x0001,0x1000,0x0001,
	0x1000,0x0001,0x1000,0x0011,0x0000,0x0011,0x0000,0x0111,
	0x1100,0x1000,0x1100,0x1000,0x1100,0x1000,0x1100,0x1000,
	0x1100,0x1000,0x1110,0x1000,0x0110,0x1000,0x0111,0x1000,
	0x0001,0x0111,0x0001,0x0110,0x0001,0x1110,0x0001,0x1100,
	0x0001,0x1100,0x0001,0x1000,0x0001,0x0000,0x0001,0x0000,

	0x1000,0x0001,0x1000,0x0001,0x1000,0x0001,0x1001,0x0001,
	0x1001,0x0001,0x1011,0x0001,0x1011,0x0001,0x1111,0x0001,
	0x1000,0x0001,0x1000,0x0001,0x1000,0x0001,0x1000,0x0001,
	0x1000,0x0001,0x1000,0x0001,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x1100,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0011,0x0000,0x0011,0x0000,0x0011,0x0000,0x0000,
	0x0000,0x0000,0x1111,0x1111,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x1111,0x1111,0x0000,0x0000,0x0000,0x0000,
	0x1111,0x0000,0x1110,0x1111,0x1000,0x1111,0x0000,0x0000,
	0x0000,0x0000,0x1111,0x1111,0x0000,0x0000,0x0000,0x0000,
	0x1110,0x0001,0x1111,0x0000,0x0011,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x1111,0x1111,0x0000,0x0000,0x0000,0x0000,
	0x1000,0x0011,0x0000,0x1111,0x0000,0x1100,0x0000,0x0000,
	0x0000,0x0000,0x1111,0x1111,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0111,0x1111,0x0011,0x1111,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x1111,0x1111,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x1000,0x0000,0x1000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x1111,0x1111,0x0000,0x0000,0x0000,0x0000,
	0x0111,0x0000,0x0111,0x0000,0x0011,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x1111,0x1111,0x0000,0x0000,0x0000,0x0000,
	0x1110,0x0001,0x1110,0x0001,0x1100,0x0001,0x0000,0x0000,
	0x0000,0x0000,0x1111,0x1111,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x1110,0x0000,0x1100,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x1111,0x1111,0x0000,0x0000,0x0000,0x0000,
	0x0001,0x1100,0x1111,0x1111,0x1111,0x0111,0x0000,0x0000,
	0x0000,0x0000,0x1111,0x1111,0x0000,0x0000,0x0000,0x0000,
	0x0011,0x1000,0x0001,0x1000,0x0000,0x1000,0x0000,0x0000,
	0x0000,0x0000,0x1111,0x1111,0x0000,0x0000,0x0000,0x0000,
	0x0001,0x0000,0x0001,0x0000,0x0001,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x1111,0x1111,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x1000,0x0001,0x1000,0x0001,0x0000,0x0000,
	0x0000,0x0000,0x1111,0x1111,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x1111,0x0000,0x1000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0111,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0001,0x0000,0x0001,0x0000,0x0001,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0100,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x1001,0x0000,0x1001,0x1000,0x1001,0x0100,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0111,0x0100,0x1000,0x0100,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0010,0x0001,0x0010,0x0001,0x0010,

	0x0000,0x1000,0x0000,0x1000,0x0000,0x1000,0x0000,0x1000,
	0x0000,0x1000,0x0000,0x1000,0x0000,0x1000,0x0000,0x0000,
	0x0000,0x1110,0x0000,0x0001,0x0000,0x0001,0x0000,0x0001,
	0x0000,0x0001,0x0000,0x0001,0x0000,0x1110,0x0000,0x0000,
	0x0001,0x0000,0x0010,0x0000,0x0010,0x0000,0x0010,0x0000,
	0x0010,0x0000,0x0010,0x0000,0x0001,0x0000,0x0000,0x0000,
	0x1101,0x0001,0x0011,0x0010,0x0001,0x0010,0x0001,0x0010,
	0x0001,0x0010,0x0001,0x0010,0x1111,0x0001,0x0001,0x0000,

	0x0001,0x1111,0x0001,0x0000,0x0001,0x0000,0x0001,0x1111,
	0x1001,0x0000,0x1001,0x0000,0x0001,0x1111,0x0000,0x0000,
	0x1000,0x1000,0x1001,0x1000,0x0001,0x0101,0x0001,0x0101,
	0x0001,0x0101,0x0001,0x0010,0x0001,0x0010,0x0000,0x0010,
	0x0000,0x1000,0x0000,0x0000,0x0000,0x0000,0x0000,0x1000,
	0x0000,0x0100,0x0000,0x0100,0x0000,0x1000,0x0000,0x0000,
	0x0111,0x1000,0x1000,0x0100,0x1000,0x0100,0x1111,0x0100,
	0x1000,0x0100,0x1000,0x0100,0x1111,0x1000,0x0000,0x0000,

	0x1111,0x1000,0x1000,0x0000,0x1000,0x0000,0x1000,0x1000,
	0x1000,0x0100,0x1100,0x0100,0x1011,0x1000,0x1000,0x0000,
	0x0111,0x0100,0x1000,0x0100,0x1000,0x0100,0x1111,0x0100,
	0x1000,0x0100,0x1000,0x0100,0x1111,0x0100,0x0000,0x0000,
	0x1010,0x0011,0x0110,0x0100,0x0010,0x0100,0x0010,0x0100,
	0x0010,0x0100,0x0010,0x0100,0x0010,0x0100,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0100,0x0000,0x0100,0x0000,0x0100,0x0000,

	0x1010,0x0011,0x0110,0x0100,0x0010,0x0100,0x0010,0x0100,
	0x0010,0x0100,0x0010,0x0100,0x1110,0x0011,0x0010,0x0000,
	0x1010,0x1001,0x0110,0x0100,0x0010,0x0100,0x0010,0x1100,
	0x0010,0x0100,0x0010,0x0100,0x0010,0x1000,0x0000,0x0000,
	0x0111,0x1000,0x1000,0x0100,0x1000,0x0100,0x1111,0x1000,
	0x0000,0x0000,0x1000,0x0000,0x0111,0x1100,0x0000,0x0000,
	0x0111,0x1100,0x0000,0x0010,0x0000,0x0010,0x0011,0x1100,
	0x0100,0x0000,0x0100,0x0000,0x0011,0x1110,0x0000,0x0000,

	0x0011,0x0000,0x0000,0x0000,0x0000,0x0000,0x0001,0x0000,
	0x0010,0x0000,0x0010,0x0000,0x0001,0x0000,0x0000,0x0000,
	0x0000,0x0100,0x0000,0x0100,0x0000,0x1000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0100,0x0000,0x1000,0x0000,0x0000,
	0x0000,0x1110,0x0000,0x0100,0x0111,0x0100,0x1000,0x0100,
	0x1000,0x0100,0x1000,0x0100,0x0111,0x1000,0x0000,0x0000,
	0x0011,0x1111,0x0000,0x0000,0x0000,0x0000,0x0000,0x1111,
	0x1000,0x0000,0x1000,0x0000,0x0011,0x1111,0x0000,0x0000,

	0x1000,0x1110,0x1001,0x0001,0x1001,0x0000,0x1001,0x0000,
	0x1001,0x0000,0x1001,0x0000,0x1001,0x0000,0x0000,0x0000,
	0x1111,0x0000,0x0001,0x0000,0x0001,0x0000,0x0001,0x0000,
	0x0001,0x0000,0x0001,0x0000,0x1110,0x0000,0x0000,0x0000,
	0x0001,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0001,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0111,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0010,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
};

const unsigned short winMap[1024] __attribute__((aligned(4)))=
{
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0001,0x0002,
	0x0003,0x0004,0x0005,0x0006,0x0007,0x0000,0x0008,0x0009,
	0x000A,0x000B,0x000C,0x000D,0x000E,0x000F,0x000F,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0010,
	0x0011,0x0012,0x0013,0x0014,0x0015,0x0000,0x0016,0x0017,
	0x0018,0x0019,0x0000,0x001A,0x001B,0x001C,0x001D,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x001E,0x001F,
	0x0020,0x0021,0x0022,0x0023,0x0024,0x0020,0x0025,0x0026,
	0x0027,0x0028,0x0029,0x002A,0x002B,0x0027,0x002C,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x002D,0x002E,0x0000,0x0000,
	0x002F,0x0000,0x0000,0x0000,0x0000,0x0030,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0031,0x0032,0x0000,
	0x0000,0x0033,0x002F,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0034,0x0035,0x0036,0x0037,
	0x0038,0x0039,0x003A,0x003B,0x003C,0x003D,0x003E,0x003F,
	0x0040,0x0041,0x0042,0x0043,0x0044,0x0045,0x0046,0x0047,
	0x0048,0x0049,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x004A,
	0x0000,0x004B,0x0000,0x044A,0x004C,0x0000,0x0000,0x004D,
	0x004D,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
};

const unsigned short winPal[256] __attribute__((aligned(4)))=
{
	0x0000,0x7D80,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,

	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
	0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
};

//}}BLOCK(win)
