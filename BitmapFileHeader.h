#ifndef BITMAPFILEHEADER_H
#define BITMAPFILEHEADER_H

#include <cstdint>

using namespace std;

// To make the following structs 2 bytes packed
#pragma pack(2)

namespace fractal {

struct BitmapFileHeader {
	char header[2]{'B', 'M'};
	int32_t filesize;
	int32_t reserved{0};
	int32_t dataOffset;
};

}

#endif // BITMAPFILEHEADER_H
