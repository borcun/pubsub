include ../Makefile.dirs
include ../Makefile.cmd

SRC=rssFeeder.cpp rssReader.cpp main.cpp
OBJ=rssFeeder.o rssReader.o main.o
EXEC=rss-example
INC=-I $(INC_DIR)
LIB=-lpubsub -L $(LIB_DIR)

all:
	$(CXX) $(CFLAGS) $(SRC) $(INC)
	$(CXX) $(OBJ) $(LFLAGS) $(EXEC) $(LIB)

debug:
	$(CXX) $(CFLAGS) $(DFLAGS) $(SRC) $(INC)
	$(CXX) $(OBJ) $(LFLAGS) $(EXEC) $(LIB)

clean:
	rm -rf $(OBJ) $(EXEC) *~
