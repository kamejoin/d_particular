def get_neighbors(triangles):
	# Triangles per node
	n_tri = {}
	for t in sorted(triangles.keys()):
		for n in triangles[t]:
			try:
				n_tri[n] += [t]
			except:
				n_tri[n] = [t]

	# Neighbors per triangle
	neis = []
	for t in sorted(triangles.keys()):
		n = []
		for i in range(3):
			n += list(set(n_tri[triangles[t][i]]).intersection(n_tri[triangles[t][i-1]]))
		neis += [list(set([x for x in n if x != t]))]

	return neis

def get_tendencies(neis, triangles):
	# Triangles per number of neighbors
	n_neis = [0,0,0]
	for i,n in enumerate(neis):
		try:
			n_neis[len(n) - 1] += 1
		except:
			print "Triangle", i, "got more than 3 neighbors." 
			print "		Neighbors:", n
			print "			Nodes:", triangles[i]
			input()

	for i in range(3):
		print "n" + str(i + 1) + " =", n_neis[i]
	print sum(n_neis)