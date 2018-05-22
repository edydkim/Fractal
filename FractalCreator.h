#ifndef FRACTALCREATOR_H
#define FRACTALCREATOR_H

#include <string>
#include <memory>
#include <math.h>
#include "Zoom.h"
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "RGB.h"

using namespace fractal;

namespace fractal {
	
class FractalCreator {
private:
	int m_width;
	int m_height;
	unique_ptr<int[]> m_pHistogram;
	unique_ptr<int[]> m_pFractal;
	Bitmap m_bitmap;
	ZoomList m_zoomList;
public:
	FractalCreator(int width, int height);
	virtual ~FractalCreator();
	
	void calculateIterator();
	void addZoom(const Zoom &zoom);
	void drawFractal();
	void writeBitmap(std::string filename);	
};

}

#endif	// FRACTALCREATOR_H
	