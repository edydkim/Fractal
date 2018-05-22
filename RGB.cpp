#include "RGB.h"

using namespace fractal;

namespace fractal {

RGB::RGB(double r, double g, double b): R(r), G(g), B(b) {
	
}

RGB operator-(const RGB &rgb1, const RGB &rgb2) {
	return RGB(rgb1.R - rgb2.R, rgb1.G - rgb2.G, rgb1.B - rgb2.B);
}

}