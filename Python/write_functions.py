
def write_kj(nodes, triangles):

	outFile = open("../../kj/botadero.kj", 'w')
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



def write_centered_kj(nodes, triangles, limites):

	medios = []
	for i in range(3):
		medios += [(limites[i][1] - limites[i][0]) / 2. + limites[i][0]]

	outFile = open("../../kj/botadero_centered.kj", 'w')
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