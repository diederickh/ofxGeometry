#pragma once
#include <gts.h>
#include <vector>
#include "ofMain.h"

using namespace std;
class ofxGtsSurface {
public: 
	ofxGtsSurface();
	void createSphere(guint level);
	vector<GtsVertex*> getVertices();
	vector<GtsEdge*> getEdges();
private:
	GtsSurface* s;
	
};