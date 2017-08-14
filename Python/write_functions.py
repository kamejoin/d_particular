from mesh_functions import *

def write_nodes(nodes, medios, outFile):
	# Writing NODES
	outFile.write("*** NODES ***\n" + str(len(nodes)) + "\n")
	for i in range(len(nodes)):
	    outFile.write(str(i) + ".")
	    for j in range(3):
	        outFile.write(" " + str(round(nodes[i][j] - medios[j], 5)))
	    outFile.write("\n")

def write_triangles(triangles, neis, style, outFile):
	# Writing TRIANGLES
	outFile.write("*** TRIANGLES ***\n" + str(len(triangles)) + "\n")
	for i in range(len(triangles)):
	    outFile.write(str(i) + ".")
	    for j in range(3):
	        outFile.write(" " + str(triangles[i][j]))
	    # .jh provide the triangle's neighbors after its nodes indexes
	    if style == "jh":
	    	for j in range(len(neis[i])):
	    		outFile.write(" " + str(neis[i][j]))
	    outFile.write("\n")

def write_kj(nodes, triangles, limites, **kwargs):
	# kwargs handling
	centered = False
	file_clue = "no_name"
	style = "kj"
	for name, value in kwargs.items():
		if name == "name":
			file_clue = value
		elif name == "center" and value == True:
			centered = True
		elif name == "style":
			style = value

	# Create file
	filename = "fail.kj"
	if centered:
		medios = []
		for i in range(3):
			medios += [(limites[i][1] - limites[i][0]) / 2. + limites[i][0]]
		filename = "../../kj/" + file_clue + "_centered." + style
	else:
		medios = [0, 0, 0]
		filename = "../../kj/" + file_clue + "." + style

	print "Writing mesh info on", filename
	outFile = open(filename, 'w')

	# Check Style
	neis = []
	if style != "kj":
		neis = get_neighbors(triangles)
	
	# Write file
	write_nodes(nodes, medios, outFile)
	write_triangles(triangles, neis, style, outFile)
	
	# Saving, Closing
	outFile.close()
	