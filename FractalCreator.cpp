#include "FractalCreator.h"

using namespace fractal;

namespace fractal {
	
FractalCreator::FractalCreator(int width, int height): m_width(width), m_height(height)
, m_pHistogram(new int[Mandelbrot::MAX_ITERATIONS]{0})
, m_pFractal(new int[m_width * m_height]{0})
, m_bitmap(m_width, m_height)
, m_zoomList(m_width, m_height) {
	m_zoomList.add(Zoom(m_width/2, m_height/2, 4.0/m_width));
	// m_zoomList.add(Zoom(295, m_height - 202, 0.1));
	// m_zoomList.add(Zoom(312, m_height - 304, 0.1));
}

FractalCreator::~FractalCreator() {
	
}
	
void FractalCreator::calculateIterator() {
	for (int y = 0; y < m_height; y++) {
		for (int x = 0; x < m_width; x++) {
			/* <-
			double xFractal = (x - WIDTH/2 - 200) * 2.0/HEIGHT;
			double yFractal = (y - HEIGHT/2) * 2.0/HEIGHT;
			*/
			
			pair<double, double> coors = m_zoomList.doZoom(x, y);			
			
			int iterations = Mandelbrot::getIterations(coors.first, coors.second);
			
			m_pFractal[y * m_width + x] = iterations;
			
			if (iterations != Mandelbrot::MAX_ITERATIONS) {			m_pHistogram[iterations]++;
			}
			
			/* <-
			uint8_t color =  (uint8_t)(256 * (double)iterations/Mandelbrot::MAX_ITERATIONS); 
			
			color = color*color*color;

			bitmap.setPixel(x, y, 0, color, 0);
			
			if (color < min)	min = color;
			if (color > max)	max = color;
			*/
		}
	}	
}

void FractalCreator::addZoom(const Zoom &zoom) {
	m_zoomList.add(zoom);
}

void FractalCreator::drawFractal() {	
	RGB startColor(0, 0, 0);
	RGB endColor(0, 255, 0);
	RGB diffColor = endColor - startColor;
	
	int total = 0;
	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
		total += m_pHistogram[i];
	}
	
	for (int y = 0; y < m_height; y++) {
		for (int x = 0; x < m_width; x++) {
			uint8_t red = 0;
			uint8_t green = 0;
			uint8_t blue = 0;
			
			int iterations = m_pFractal[y * m_width + x];
			
			if (iterations != Mandelbrot::MAX_ITERATIONS) {
				double hue = 0.0;	
				
				for (int i = 0; i <= iterations; i++) {
					hue += ((double)m_pHistogram[i])/total;
				}		
				
				// <- green = pow(255, hue);
				red = startColor.R - diffColor.R * hue;
				green = startColor.G - diffColor.G * hue;
				blue = startColor.B - diffColor.B * hue;
			}
			
			m_bitmap.setPixel(x, y, red, green, blue);
		}
		
	}
}
	
void FractalCreator::writeBitmap(std::string filename) {
	m_bitmap.write(filename);
}

}

