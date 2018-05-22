#ifndef RGB_H
#define RGB_H

namespace fractal {

struct RGB {
	double R;
	double G;
	double B;
	
	RGB(double r, double g, double b);		
};

RGB operator-(const RGB &rgb1, const RGB &rgb2);

}

#endif	// RGB_H