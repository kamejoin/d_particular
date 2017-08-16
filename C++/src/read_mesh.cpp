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
	vector<int> t, n;
	int i=0, j, k, mode=0; // mode: Data currently being read.

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
					node.z = atof(vec[3].c_str());
					nodes.push_back(node);
				}
			}
			// TRIANGLES
			if (mode == 2 && vec.size() != 0) {
				if (i == 1) n_triangles = atoi(vec[0].c_str());
				else {
					for (j=1; j<4; j++) t.push_back(atoi(vec[j].c_str()));
					for (k=j; k<vec.size();k++) n.push_back(atoi(vec[k].c_str()));
					triangles.push_back(t);
					neighbors.push_back(n);
					t.clear();
					n.clear();
				}
			}
		}
		else {mode++; i=0;}

		i++;
	}

}
