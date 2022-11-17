CXX=g++
CFLAGS=-c -Wall -std=c++20
LFLAGS=-o
DFLAGS=-g
SRC=rssFeeder.cpp rssReader.cpp main.cpp
OBJ=rssFeeder.o rssReader.o main.o
EXEC=rss-example
INC=-I /usr/local/include/pubsub
LIB=-lpubsub -L /usr/local/lib/
RM=rm -rf
BACKUPS=*~

all:
	$(CXX) $(CFLAGS) $(SRC) $(INC)
	$(CXX) $(OBJ) $(LFLAGS) $(EXEC) $(LIB)

debug:
	$(CXX) $(CFLAGS) $(DFLAGS) $(SRC) $(INC)
	$(CXX) $(OBJ) $(LFLAGS) $(EXEC) $(LIB)

clean:
	$(RM) $(OBJ) $(EXEC) $(BACKUPS)
