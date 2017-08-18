CXX = g++

DIR_CGAL  = -I"C:\Libs\CGAL-4.10\include"
#DIR_CGAL2  = -I"C:\Libs\CGAL-4.10\build\include"
DIR_BOOST = -I"C:\Libs\boost_1_64_0"

ALL_INC = $(DIR_CGAL) $(DIR_CGAL2) $(DIR_BOOST)
#E_INC = $(foreach d, $(INC), -I$d) $(DIR_CGAL)


LIB_CGAL = -L"C:\Libs\CGAL-4.10\build\lib"
LIB_BOOST = -L"C:\Libs\boost_1_64_0\lib64-msvc-14.0" 
ALL_LIBS = $(LIB_CGAL) $(LIB_BOOST)

LIBS = -lboost_system-vc140-mt-1_64 -lCGAL-vc140-mt-4.10 -lCGAL_Core-vc140-mt-4.10
#-lgmp


# Alternativa makefile
main: test.cpp
	$(CXX) -Wall $(ALL_INC) $(ALL_LIBS) test.cpp -o main $(LIBS)

