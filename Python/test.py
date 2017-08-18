test_file = open("../../Pascua Lama/botadero nevada.dxf", 'r')
outfile = open("test_out", 'w')
a = 5000
for i,line in enumerate(test_file):
	if i == a:
		break
	outfile.write(line)
test_file.close()
outfile.close()