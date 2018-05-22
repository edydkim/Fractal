#ifndef MANDELBROT_H
#define MANDELBROT_H

namespace fractal {

class Mandelbrot {
public:
	static int const MAX_ITERATIONS = 1000;	
	
public:
	Mandelbrot();
	static int getIterations(double x, double y);
	virtual ~Mandelbrot();
};

}

#endif	// MANDELBROT_H