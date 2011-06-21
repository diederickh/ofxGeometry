#include "ofxGtsSurface.h"

static void build_vertex_vector(gpointer data, vector<GtsVertex*>* vertices) {
	vertices->push_back((GtsVertex*)data);
}

static void build_edge_vector(gpointer data, vector<GtsEdge*>* edges) {
	edges->push_back((GtsEdge*)data);
}

static void build_triangle_vector(gpointer data, vector<GtsTriangle*>* triangles) {
	triangles->push_back((GtsTriangle*)data);
}

ofxGtsSurface::ofxGtsSurface() {
	s = gts_surface_new(
			 gts_surface_class()
			,gts_face_class()
			,gts_edge_class()
			,gts_vertex_class()
	);
}

ofxGtsSurface::~ofxGtsSurface() {
	{
		vector<GtsVertex*>::iterator it = vertices.begin();
		while(it != vertices.end()) {
			delete *it;
			++it;
		}
	}
	{
		vector<GtsEdge*>::iterator it = edges.begin();
		while(it != edges.end()) {
			delete *it;
			++it;
		}
	}
	{
		vector<GtsFace*>::iterator it = faces.begin();
		while(it != faces.end()) {
			delete *it;
			++it;
		}
	}
}

// level:  http://mathworld.wolfram.com/GeodesicDome.html
void ofxGtsSurface::createSphere(guint level) {
	gts_surface_generate_sphere(s, level);
}

GtsVertex* ofxGtsSurface::createVertex(float x, float y, float z) {
	GtsVertex* v = gts_vertex_new(s->vertex_class, x, y, z);
	vertices.push_back(v);
	return v;
}

GtsEdge* ofxGtsSurface::createEdge(GtsVertex* v1, GtsVertex* v2) {
	GtsEdge* edge = gts_edge_new(s->edge_class, v1, v2);
	edges.push_back(edge);
	return edge;
}

GtsFace* ofxGtsSurface::createFace(GtsEdge* e1, GtsEdge* e2, GtsEdge* e3) {
	GtsFace* face = gts_face_new(s->face_class, e1, e2, e3);
	faces.push_back(face);
	return face;
}

vector<GtsVertex*> ofxGtsSurface::getFaceVertices(GtsFace* face) {
	// THIS IS NOT CORRECT!!!!
	cout << "GETFACEVERTICES IS NOT YET READY!!! " << endl;
	GtsVertex* v1 = face->triangle.e1->segment.v1;
	GtsVertex* v2 = face->triangle.e2->segment.v2;
	GtsVertex* v3 = face->triangle.e3->segment.v1;
	vector<GtsVertex*> result;
	result.push_back(v1);
	result.push_back(v2);
	result.push_back(v3);
	return result;
}

vector<GtsVertex*> ofxGtsSurface::getVertices() {
	vector<GtsVertex*> vertices;
	gts_surface_foreach_vertex(s, (GtsFunc) build_vertex_vector, &vertices);
	return vertices;
}

vector<GtsEdge*> ofxGtsSurface::getEdges() {
	vector<GtsEdge*> edges;
	gts_surface_foreach_edge(s, (GtsFunc) build_edge_vector, &edges);
	return edges;
}

vector<GtsTriangle*> ofxGtsSurface::getTriangles() {
	vector<GtsTriangle*> triangles;
	gts_surface_foreach_face(s, (GtsFunc) build_triangle_vector, &triangles);
	return triangles;
}