#pragma once

#include <gts.h>
#include <vector>
#include "ofxGtsSurface.h"

using namespace std;


class ofxGtsIsoSurface {
public:
	ofxGtsIsoSurface(ofxGtsSurface* s, int w, int h);
	void	addLayer(float* data);
	void	createIsoSurface(float iso);
	void	setGridSize(float nDX = 0.3, float nDY = 0.3, float nDZ = 0.3);

	int		getWidth();
	int		getHeight();
	
	template<typename T> 
	void	fillVertexData(T& vd);

	vector<float*> layers;		
	
private:
	void				updateGridValues();
	int					size;
	ofxGtsSurface*		ofx_surface;
	GtsCartesianGrid	grid;
};

template<typename T> 
void ofxGtsIsoSurface::fillVertexData(T& vd) {
	ofx_surface->fillVertexData(vd);
}

inline void ofxGtsIsoSurface::setGridSize(float nDX, float nDY, float nDZ) {
	grid.dx = nDX;
	grid.dy = nDY;
	grid.dz = nDZ;
}

inline int ofxGtsIsoSurface::getWidth() {
	return grid.nx;
}

inline int ofxGtsIsoSurface::getHeight() {
	return grid.ny;
}