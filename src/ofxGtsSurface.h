#pragma once
#include <Gts/gts.h>
#include <vector>
#include "ofMain.h"

using namespace std;
class ofxGtsSurface {
public: 
	ofxGtsSurface();
	~ofxGtsSurface();
	GtsVertex* 		createVertex(float x, float y, float z);
	GtsEdge* 		createEdge(GtsVertex* v1, GtsVertex* v2);
	GtsFace* 		createFace(GtsEdge* e1, GtsEdge* e2, GtsEdge* e3);
	void 			createSphere(guint level);
	
	template<typename T>
	inline void fillVertexData(T& vd);
	
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
		vector<GtsTriangle*> tmp_triangles = getTriangles();
		vector<GtsTriangle*>::iterator it = tmp_triangles.begin();
		while(it != tmp_triangles.end()) {
			GtsTriangle* tri = *it;
			GtsPoint& p1 = tri->e1->segment.v1->p;
		    GtsPoint& p2 = tri->e2->segment.v1->p;
		    GtsPoint& p3 = tri->e3->segment.v1->p;
			vd.addVertex(p1.x, p1.y, p1.z);
			vd.addVertex(p2.x, p2.y, p2.z);
			vd.addVertex(p3.x, p3.y, p3.z);
			
			/*
			   GtsTriangle *triangle = (GtsTriangle*)triList->data;
		      GtsPoint &p1 = triangle->e1->segment.v1->p;
		      GtsPoint &p2 = triangle->e2->segment.v1->p;
		      GtsPoint &p3 = triangle->e3->segment.v1->p;
			*/
			//vd.addVertex(v->p.x, v->p.y, v->p.z);
			++it;
		}	
	}
}