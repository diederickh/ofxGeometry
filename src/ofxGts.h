#pragma once
#include <gts.h>
#include <vector>

#include "ofxGtsSurface.h"

using  namespace std;

class ofxGts {
public:
	ofxGts();
	~ofxGts();
	ofxGtsSurface& createSurface();
private:
	vector<ofxGtsSurface*> surfaces;
};