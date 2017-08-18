infilepath  = "../../kj/derk_centered_surf.kj"
outfilepath = infilepath.replace("kj", "off")
outfilepath = outfilepath.replace(".kj", ".off")

infile  = open(infilepath, 'r')
outfile = open(outfilepath, 'w')

# infile info
nodes     = []
triangles = []
n_nodes     = 0
n_triangles = 0
for i,line in enumerate(infile):
	if line[0] != "*":
		values = line.strip().split()
		if len(values) == 1:
			if i == 1:
				n_nodes = int(values[0])
			else:
				n_triangles = int(values[0])
		else:
			if n_triangles == 0:
				nodes += [[float(n) for j,n in enumerate(values) if j != 0]]
			else:
				triangles += [[int(n) for j,n in enumerate(values) if j != 0]]
infile.close()


# outfile writing
outfile.write("OFF\n" + str(n_nodes) + " " + str(n_triangles) + "\n"*2)
for n in nodes:
	for i in range(3):
		if i != 2:
			outfile.write(str(n[i]) + " ")
		else:
			outfile.write(str(n[i]))
	outfile.write("\n")
for t in triangles:
	outfile.write("3")
	for i in range(3):
		outfile.write(" " + str(t[i]))
	outfile.write("\n")


