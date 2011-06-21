#include "ofxGtsSurface.h"

static void buildVertexVector(gpointer data, vector<GtsVertex*>* vertices) {
	vertices->push_back((GtsVertex*)data);
	//vertices->push_back(ofVec3f(GTS_POINT(data)->x, GTS_POINT(data)->y, GTS_POINT(data)->z));
}

static void buildEdgeVector(gpointer data, vector<GtsEdge*>* edges) {
	edges->push_back((GtsEdge*)data);
}

ofxGtsSurface::ofxGtsSurface() {
	s = gts_surface_new(
			 gts_surface_class()
			,gts_face_class()
			,gts_edge_class()
			,gts_vertex_class()
	);
}

// level:  http://mathworld.wolfram.com/GeodesicDome.html
void ofxGtsSurface::createSphere(guint level) {
	gts_surface_generate_sphere(s, 4);
	gts_surface_write (s, stdout);
}

vector<GtsVertex*> ofxGtsSurface::getVertices() {
	vector<GtsVertex*> vertices;
	gts_surface_foreach_vertex (s, (GtsFunc) buildVertexVector, &vertices);
	return vertices;
}

vector<GtsEdge*> ofxGtsSurface::getEdges() {
	vector<GtsEdge*> edges;
	gts_surface_foreach_edge (s, (GtsFunc) buildEdgeVector, &edges);
	return edges;

}