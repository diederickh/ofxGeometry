#pragma once
#include <gts.h>
#include <vector>
#include "ofMain.h"

struct FloatArray {
	float* data;
};

using namespace std;
class ofxGtsSurface {
public: 
	ofxGtsSurface();
	~ofxGtsSurface();
	GtsVertex* 		createVertex(float x, float y, float z);
	GtsEdge* 		createEdge(GtsVertex* v1, GtsVertex* v2);
	GtsFace* 		createFace(GtsEdge* e1, GtsEdge* e2, GtsEdge* e3);
	void 			createSphere(guint level);
	void			createLayers(int w, int h);

	
	template<typename T>
	void fillVertexData(T& vd);
	
	template<typename T>
	void updateVertexData(T& vd);
	
	GtsSurface*				getGtsSurface();
	vector<GtsVertex*>		getFaceVertices(GtsFace* face);
	vector<GtsVertex*> 		getVertices();
	vector<GtsEdge*> 		getEdges();
	vector<GtsTriangle*> 	getTriangles();
	
	GtsSurface* 		surface;
	vector<GtsVertex*> 	vertices;	
	vector<GtsEdge*> 	edges;
	vector<GtsFace*> 	faces;
};

template<typename T>
inline	void ofxGtsSurface::fillVertexData(T& vd) {	
	// vertices
	{
		vector<GtsVertex*> tmp_vertices = getVertices();
		vector<GtsVertex*>::iterator it = tmp_vertices.begin();
		while(it != tmp_vertices.end()) {
			GtsVertex* v = *it;
//			vd.addVertex(v->p.x, v->p.y, v->p.z);
			++it;
		}	
	}
	
	// triangles
	{
		GtsVertex* a = NULL;
		GtsVertex* b = NULL;
		GtsVertex* c = NULL;
			
		vector<GtsTriangle*> tmp_triangles = getTriangles();
		vector<GtsTriangle*>::iterator it = tmp_triangles.begin();
		while(it != tmp_triangles.end()) {
			GtsTriangle* tri = *it;
			
			gts_triangle_vertices(tri, &a, &b, &c);
			vd.addVertex(a->p.x, a->p.y, a->p.z);
			vd.addVertex(b->p.x, b->p.y, b->p.z);
			vd.addVertex(c->p.x, c->p.y, c->p.z);
			++it;
		}	
	}
}

template<typename T>
inline void ofxGtsSurface::updateVertexData(T& vd) {
	vd.clear();
	
	GtsVertex* a = NULL;
	GtsVertex* b = NULL;
	GtsVertex* c = NULL;
			
	vector<GtsTriangle*> tmp_triangles = getTriangles();
	vector<GtsTriangle*>::iterator it = tmp_triangles.begin();
	while(it != tmp_triangles.end()) {
		GtsTriangle* tri = *it;
			
		gts_triangle_vertices(tri, &a, &b, &c);
		vd.addVertex(a->p.x, a->p.y, a->p.z);
		vd.addVertex(b->p.x, b->p.y, b->p.z);
		vd.addVertex(c->p.x, c->p.y, c->p.z);
		++it;
	}	

}

inline GtsSurface* ofxGtsSurface::getGtsSurface() {
	return surface;
}
