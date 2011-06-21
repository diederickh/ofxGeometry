#pragma once
#include <gts.h>
#include <vector>
#include "ofMain.h"

using namespace std;
class ofxGtsSurface {
public: 
	ofxGtsSurface();
	~ofxGtsSurface();
	GtsVertex* createVertex(float x, float y, float z);
	GtsEdge* createEdge(GtsVertex* v1, GtsVertex* v2);
	GtsFace* createFace(GtsEdge* e1, GtsEdge* e2, GtsEdge* e3);

	vector<GtsVertex*> getFaceVertices(GtsFace* face);
	void createSphere(guint level);
	vector<GtsVertex*> getVertices();
	vector<GtsEdge*> getEdges();
	vector<GtsTriangle*> getTriangles();
private:
	GtsSurface* s;
	vector<GtsVertex*> vertices;	
	vector<GtsEdge*> edges;
	vector<GtsFace*> faces;
};