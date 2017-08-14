inFile = open("../../kj/botadero_centered.kj", 'r')

mode = 0
nodes = []
triangles = []
n_tri = {}

for i,line in enumerate(inFile):
	if line[0] != "*":
		values = line.strip().split()
		if len(values) > 1:
			if mode == 1:
				nodes += [[float(values[1]), float(values[2]), float(values[3])]]
			else:
				t = [int(values[1]), int(values[2]), int(values[3])]
				triangles += [t]
				for n in t:
					try:
						n_tri[n] += [len(triangles) - 1]
					except:
						n_tri[n] = [len(triangles) - 1]
	else:
		mode += 1
inFile.close()

neis = []
for i,t in enumerate(triangles):
	n = []
	for j in range(3):
		n += list(set(n_tri[t[j]]).intersection(n_tri[t[j-1]]))
	neis += [list(set([x for x in n if x != i]))]



print len(nodes), "nodes"
print len(triangles), "triangles"

n_neis = [0,0,0]
for i,n in enumerate(neis):
	try:
		n_neis[len(n) - 1] += 1
		#print "neis[" + str(i) + "] =", neis[i]
	except:
		print i, n
		print triangles[i]
		input()
for i in range(3):
	print "n" + str(i + 1) + " =", n_neis[i]

print sum(n_neis)