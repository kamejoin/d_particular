
def write_kj(nodes, triangles, filename):

	path = "../../kj/" + filename + ".kj"
	outFile = open(path, 'w')
	# Writing NODES
	outFile.write("*** NODES ***\n" + str(len(nodes)) + "\n")
	for i in range(len(nodes)):
	    outFile.write(str(i) + ".")
	    for j in range(3):
	        outFile.write(" " + str(nodes[i][j]))
	    outFile.write("\n")
	# Writing TRIANGLES
	outFile.write("*** TRIANGLES ***\n" + str(len(triangles)) + "\n")
	for i in range(len(triangles)):
	    outFile.write(str(i) + ".")
	    for j in range(3):
	        outFile.write(" " + str(triangles[i][j]))
	    outFile.write("\n")
	outFile.close()



def write_centered_kj(nodes, triangles, limites, filename, *argv):

	medios = []
	if len(argv) != 0:
		if argv[0] == "body":
			print "YES BODY"
			infile = open("limites.txt", 'r')
			for i,line in enumerate(infile):
				values = line.strip().split()
				limites[i] = [float(v) for v in values]
			infile.close()
	else:
		outfile = open("limites.txt", 'w')
		for i in range(3):
			outfile.write(str(limites[i][0]) + " " + str(limites[i][1]))
			if i != 2:
				outfile.write("\n")
		outfile.close()

	for i in range(3):
		medios += [(limites[i][1] - limites[i][0]) / 2. + limites[i][0]]

	path = "../../kj/" + filename + "_centered.kj"
	outFile = open(path, 'w')
	# Writing NODES
	outFile.write("*** NODES ***\n" + str(len(nodes)) + "\n")
	for i in range(len(nodes)):
	    outFile.write(str(i) + ".")
	    for j in range(3):
	        outFile.write(" " + str(round(nodes[i][j] - medios[j], 2)))
	    outFile.write("\n")
	# Writing TRIANGLES
	outFile.write("*** TRIANGLES ***\n" + str(len(triangles)) + "\n")
	for i in range(len(triangles)):
	    outFile.write(str(i) + ".")
	    for j in range(3):
	        outFile.write(" " + str(triangles[i][j]))
	    outFile.write("\n")
	outFile.close()