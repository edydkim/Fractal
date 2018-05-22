#ifndef ZOOMLIST_H
#define ZOOMLIST_H

#include <vector>
#include <utility>

#include "Zoom.h"

namespace fractal {

class ZoomList {
private:
	double m_xCenter{0.0};
	double m_yCenter{0.0};
	double m_scale{1.0};
	
	int m_width;
	int m_height;
	std::vector<Zoom> zooms;
public:
	ZoomList(int width, int height);
	void add(const Zoom &zoom);
	std::pair<double, double> doZoom(int x, int y);
	virtual ~ZoomList();
};

}

#endif	// ZOOMLIST_H