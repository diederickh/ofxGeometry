#include "ofxGtsIsoSurface.h"
#include "ofxGtsSurface.h"


// todo memcpy
static void iso_layers(gdouble ** f, GtsCartesianGrid g, guint k, gpointer data) {
	ofxGtsIsoSurface* iso = static_cast<ofxGtsIsoSurface*>(data);
	float* array = iso->layers[k];
	for(int j = 0; j < g.ny; ++j) {
	
		for(int i = 0; i < g.nx; ++i) {
			f[i][j] = array[(j*g.nx)+i];
//			memcpy(f[(j*g.nx)], array+(j*g.nx), sizeof(float)*g.nx);
		}
	}
}


ofxGtsIsoSurface::ofxGtsIsoSurface(ofxGtsSurface* surf, int w, int h)
	:ofx_surface(surf)
{
	grid.nx = w;
	grid.ny = h;
	grid.dx = grid.dy = grid.dz = 0.2;
	size = (w*h) * sizeof(float);
}

void ofxGtsIsoSurface::addLayer(float* data) {
	float* f = new float[size];
	memcpy(f,data,size);
	layers.push_back(f);
	grid.nz = layers.size();
}


// iso: iso surface value
void ofxGtsIsoSurface::createIsoSurface(float iso) {
	gts_isosurface_tetra(ofx_surface->getGtsSurface(), grid, iso_layers, this, iso);
}
