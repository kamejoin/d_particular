#include <vector>
#include <string>
#include <cstdio>
#include <sstream>
#include <iostream>

using namespace std;

struct Point { double x, y, z;};
struct Edge { int p1, p2;};

class readmesh {
	public:
		int n_nodes; // Total nodes = total connections
		int n_triangles;
		
		vector<Point> nodes; // Nodes coords
		vector< vector<int> > triangles; // Triangles indexes
		vector< vector<int> > neighbors; // Triangles neighbors indexes

		readmesh(const char *filepath);

		void read_mesh_file(FILE *fp);

		inline void read_mesh_file(const char *filepath) {
			FILE *fp=fopen(filepath,"r");
			read_mesh_file(fp);
			fclose(fp);
			printf("%s %s %s\n", "File", filepath, "closed correctly.");
		}

	protected:
		vector<string> &split(const string &s, char delim, vector<string> &elems){
			stringstream ss(s);
			string item;
			while (getline(ss, item, delim)) {
				if (!item.empty()) {
				  elems.push_back(item);  
				}
			}
			return elems;
		}

		vector<string> split(const string &s, char delim) {
			vector<string> elems;
			split(s, delim, elems);
			return elems;
		}
};