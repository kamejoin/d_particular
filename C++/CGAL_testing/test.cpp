#include <vector>
#include <fstream>

#include <CGAL/Simple_cartesian.h>
#include <CGAL/Polyhedron_3.h>
#include <CGAL/IO/File_scanner_OFF.h>
#include <CGAL/IO/Polyhedron_iostream.h>
#include <CGAL/boost/graph/graph_traits_Polyhedron_3.h>

#include <boost/foreach.hpp>
#include <CGAL/Surface_mesh.h>



typedef CGAL::Simple_cartesian<double> K;
// Surface Mesh
typedef CGAL::Surface_mesh<K::Point_3> Mesh;
typedef Mesh::Vertex_index vertex_descriptor;
typedef Mesh::Face_index face_descriptor;

// Polyhedron_3
typedef CGAL::Polyhedron_3<K> Polyhedron;
typedef Polyhedron::Halfedge_handle Halfedge_handle;


using namespace std;

bool  verbose   = false;
bool  unitcube  = false;

int main(int argc, char **argv) {

	int n = 0; // Number of filenames.
	char *filename[1] = { NULL };
    bool help = false;
    for (int i = 1; i < argc; i++) { // check commandline options
        if ( strcmp( "-v", argv[i]) == 0)
            verbose = true;
        else if ( strcmp( "-unit", argv[i]) == 0)
            unitcube = true;
        else if ( (strcmp( "-h", argv[i]) == 0) ||
                  (strcmp( "-help", argv[i]) == 0))
            help = true;
        else if ( n < 1 ) {
            filename[ n++] = argv[i]; // Esta notacion le suma al n 
            // filename[0] = filename
        } 
        else {
	    	n++;
            break;
		}
    }

    istream*     p_in = &cin;
    ifstream     in;
    if ( n > 0) {
        in.open( filename[0]);
        p_in = &in;
    }
    if ( ! * p_in) {
        cerr << argv[0] << ": error: cannot open file '"<< filename[0]
         << "' for reading." <<endl;
        exit( 1);
    }

    /*
    cout << "CGAL::File_scanner_OFF(" << filename[0] << ") ...." << endl;
    CGAL::File_scanner_OFF scanner( * p_in);
    cout << scanner.size_of_vertices() << " vertices" << endl;
    */

	Mesh m;

	vertex_descriptor u = m.add_vertex(K::Point_3(0,0,0));
	vertex_descriptor v = m.add_vertex(K::Point_3(1,0,0));
	vertex_descriptor w = m.add_vertex(K::Point_3(0,1,0));

	m.add_face(u,v,w);


	cout << "all vertices " << endl;

	Mesh::Vertex_range::iterator vb, ve;
	Mesh::Vertex_range r = m.vertices();

	vb = r.begin();
	ve = r.end();

	BOOST_FOREACH(vertex_descriptor vd, m.vertices()) cout << vd << endl;
    /*
	Polyhedron P;
	Halfedge_handle h = P.make_tetrahedron();
	if (P.is_tetrahedron(h)) cout << "it is!" << endl;
    */
	cout << "BIEN" << endl;
	return 0;
}