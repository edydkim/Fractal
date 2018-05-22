#include <fstream>

#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

using namespace std;
using namespace fractal;

namespace fractal {

Bitmap::Bitmap(int width, int height): m_width(width), m_height(height), m_pPixels(new uint8_t[width*height*3]{0}) {
	
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
	uint8_t *pPixels = m_pPixels.get();
	
	pPixels += (y*3) * m_width + (x*3);
	
	pPixels[0] = blue;
	pPixels[1] = green;
	pPixels[2] = red;
}

bool Bitmap::write(string filename) {
	BitmapInfoHeader infoHeader;
	BitmapFileHeader fileHeader;
	
	fileHeader.filesize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width*m_height*3;
	fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);
	
	infoHeader.width = m_width;
	infoHeader.height = m_height;
	
	ofstream file;	
	file.open(filename, ios::out|ios::binary);
	
	if (!file) {
		return false;
	}
	
	file.write((char *)&fileHeader, sizeof(fileHeader));
	file.write((char *)&infoHeader, sizeof(infoHeader));
	file.write((char *)m_pPixels.get(), m_width*m_height*3);
	
	file.close();
	
	if (!file) {
		return false;
	}
	
	return true;
}

Bitmap::~Bitmap() {
	
}

}