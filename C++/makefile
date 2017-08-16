CXX = g++
E_LIB= -L"C:/Users/jorge.martinez/Desktop/JMV/Libs/freeglut/lib/x64"
E_INC= -I"C:/Users/jorge.martinez/Desktop/JMV/Libs/freeglut/include"

SRC  = src
ODIR = obj

_OBJ = main.o read_mesh.o matrix_functions.o mouse_action.o keyboard_action.o parameters.o
OBJ  = $(patsubst %,$(ODIR)/%,$(_OBJ))

LIBS = -lopengl32 -lglu32 -lfreeglut

# Primary makefile
#test: main.o
#	$(CXX) $(E_INC) $(E_LIB) -o main main.cpp read_mesh.cpp -lopengl32 -lglu32 -lfreeglut


# Alternativa makefile
main: $(OBJ)
	$(CXX) $(E_INC) $(E_LIB) $(OBJ) -o main $(LIBS)

$(ODIR)/main.o: main.cpp
	$(CXX) $(E_INC) -c $< -o $@ 

$(ODIR)/%.o: $(SRC)/%.cpp $(SRC)/%.h
	$(CXX) $(E_INC) -c $< -o $@ 


#$(ODIR)/mouse_action.o: $(SRC)/mouse_action.cpp $(SRC)/mouse_action.h $(SRC)/parameters.h
	#$(CXX) -c $^ -o $@

#$(ODIR)/parameters.o: $(SRC)/parameters.cpp $(SRC)/parameters.h
#	$(CXX) -c $< -o $@


clean:
	rm $(OBJ) main