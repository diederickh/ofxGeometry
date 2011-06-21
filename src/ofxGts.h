#pragma once
#include <gts.h>
#include <vector>

#include "ofxGtsSurface.h"

/*
  Point - a point in 3D space
  Vertex - a Point in 3D space that may be used to define a Segment
  Segment - a line defined by two Vertex end-points
  Edge - a Segment that may be used to define the edge of a Triangle
  Triangle - a triangle defined by three Edges
  Face - a Triangle that may be used to define a face on a Surface
  Surface - a surface composed of Faces

some nice info:
http://pygts.svn.sourceforge.net/viewvc/pygts/doc/gts.html
*/


using  namespace std;

class ofxGts {
public:
	ofxGts();
	~ofxGts();
	ofxGtsSurface& createSurface();
private:
	vector<ofxGtsSurface*> surfaces;
};