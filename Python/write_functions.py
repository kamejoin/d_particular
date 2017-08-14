def write_kj(nodes, triangles, limites, **kwargs):
	# kwargs handling
	centered = False
	file_clue = "no_name"
	for name, value in kwargs.items():
		if name == "name":
			file_clue = value
		elif name == "center" and value == True:
			centered = True

	# Create file
	filename = "fail.kj"
	if centered:
		medios = []
		for i in range(3):
			medios += [(limites[i][1] - limites[i][0]) / 2. + limites[i][0]]
		filename = "../../kj/" + file_clue + "_centered.kj"
	else:
		medios = [0, 0, 0]
		filename = "../../kj/" + file_clue + ".kj"

	print "Writing mesh info on", filename
	outFile = open(filename, 'w')


	# Writing NODES
	outFile.write("*** NODES ***\n" + str(len(nodes)) + "\n")
	for i in range(len(nodes)):
	    outFile.write(str(i) + ".")
	    for j in range(3):
	        outFile.write(" " + str(round(nodes[i][j] - medios[j], 5)))
	    outFile.write("\n")
	    
	# Writing TRIANGLES
	outFile.write("*** TRIANGLES ***\n" + str(len(triangles)) + "\n")
	for i in range(len(triangles)):
	    outFile.write(str(i) + ".")
	    for j in range(3):
	        outFile.write(" " + str(triangles[i][j]))
	    outFile.write("\n")
	outFile.close()
