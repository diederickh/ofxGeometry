#include "ofxGts.h"
ofxGts::ofxGts() {
}

ofxGts::~ofxGts() {	
	// cleanup surfaces.
	vector<ofxGtsSurface*>::iterator it = surfaces.begin();
	while(it != surfaces.end()) {
		delete (*it);
		it = surfaces.erase(it);
	}
}

ofxGtsSurface& ofxGts::createSurface() {
	ofxGtsSurface* s = new ofxGtsSurface();
	surfaces.push_back(s);
	return *s;
}