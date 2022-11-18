include ../Makefile.cmd

SRC=test.cpp
OBJ=test.o
EXEC=test
INC=-I /usr/include/ -I /usr/local/include/pubsub/
LIB=-lgtest -L /usr/lib64/ -lpubsub -L /usr/local/lib/

all:
	$(CXX) $(CFLAGS) $(SRC) $(INC)
	$(CXX) $(OBJ) $(LFLAGS) $(EXEC) $(LIB)

clean:
	rm -rf $(OBJ) $(EXEC) *~
