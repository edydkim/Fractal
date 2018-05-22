#include <iostream>
#include "FractalCreator.h"
#include "RGB.h"

using namespace std;
using namespace fractal;

int main(int argc, char *argv[]) {
	FractalCreator fractalCreator(800, 600);
		
	fractalCreator.calculateIterator();
	fractalCreator.drawFractal();
	fractalCreator.writeBitmap("test.bmp");
	
	return 0;
}