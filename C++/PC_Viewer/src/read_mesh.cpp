#include "read_mesh.h"
#include <stdlib.h>
using namespace std;

readmesh::readmesh(const char *filepath) {
	printf("%s %s\n", "Reading mesh file:", filepath);
	read_mesh_file(filepath);
}


void readmesh::read_mesh_file(FILE *fp) {	

	if (fp == NULL) {perror("Error opening file (possible wrong path).");}

	char line[1000];
	string l;
	vector<string> vec;
	Point node;
	vector<int> t;
	int i=0, j, mode=0; // mode: Data currently being read.

	while(!feof(fp)) {
		fgets(line, 1000, fp);

		if (line[0] != '*') {
			l = line;
			l.erase(l.length() - 1); // Getting rid of newline
			vec = split(l, ' ');

			// NODES
			if (mode == 1 && vec.size() != 0) { 
				if (i == 1) n_nodes = atoi(vec[0].c_str());
				else {
					node.x = atof(vec[1].c_str());
					node.y = atof(vec[2].c_str());
					node.z = -atof(vec[3].c_str());
					nodes.push_back(node);
				}
			}
			// TRIANGLES
			if (mode == 2 && vec.size() != 0) {
				if (i == 1) n_tri = atoi(vec[0].c_str());
				else {
					for (j=1; j<vec.size(); j++) t.push_back(atoi(vec[j].c_str()));
					triangles.push_back(t);
					t.clear();
				}
			}
		}
		else {mode++; i=0;}

		i++;
	}

}


body::body(const char *filepath, const char *color_char) : readmesh(filepath) {
	printf("%s %s\n", "Reading object file:", filepath);

	color.r = 1.;
	color.g = 0.;
	color.b = 0.;
	color.a = 1.;
}