import time
import re
import pprint
from math import *
from write_functions import *

inFile  = open('../../dxf/TOPOGRAFIA_VIRGEN.dxf', 'r')
#inFile  = open("../../Pascua Lama/botadero nevada.dxf", 'r')
#outFile = open('test.kj', 'w')

def sinSpecials(line):
    line = re.sub('[^A-Za-z0-9]+', '', line)
    return line

ti = time.time()

bloques = {}
count = 0
last = 0
on = 0
for i,line in enumerate(inFile):
    if line[0:6] == '3DFACE':
        last = i
        bloques[count] = []
        on = 1
    if on == 1:
        if line[0:3] == '  0':
            on = 0
            count += 1
        else:
            bloques[count].extend([line])

print "{:,}".format(i), "total lines."
print "{:,}".format(last), "last line with 3DFACE.\n"
print "{:,}".format(count), "total 3DFACE."
#outFile.close()

triangles   = {}
nodes   = {}
test_coords = {}
limites = {0: [1e10, -1e10], 1: [1e10, -1e10], 2: [1e10, -1e10]}

def check_limit(n):
    for i in range(3):
        for j in range(2):
            if (-2*j + 1) * n[i] < (-2*j + 1) * limites[i][j]:
                limites[i][j] = n[i]



for i,b in enumerate(bloques.keys()):
    triangles[b] = []
    
    for j in range(3):
        n = {}
        for p,k in enumerate([1,3,5]):
            # Tolerancia al cm
            # ind = 15 -> 10
            n[p] = round(float(bloques[b][15 + k + j*6].strip()),2)
        try:
            triangles[b] += [test_coords[(n[0], n[1], n[2])]]
        except:
            test_coords[(n[0], n[1], n[2])] = len(nodes)
            triangles[b] += [len(nodes)]
            nodes[len(nodes)] = n
            check_limit(n)
    triangles[b] = sorted(triangles[b])

inFile.close()
test_coords = None

print "{:,}".format(len(triangles)), "total triangles."
print "{:,}".format(len(nodes)), "total nodes."

filename = "derk"
write_kj(nodes, triangles, filename)
write_centered_kj(nodes, triangles, limites, filename)


tf = time.time()
print tf-ti, 'segundos'
