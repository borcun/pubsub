# directories
INC=inc
INSTALL_DIR=/usr/local

CXX=g++
CFLAGS=-c -Wall -fPIC -std=c++20
LFLAGS=-o
IFLAGS=-I $(INC)
SHARED=-shared

SRC=src/message.cpp src/messageFactory.cpp src/subscriber.cpp src/publisher.cpp src/messageService.cpp
OBJ=message.o messageFactory.o subscriber.o publisher.o messageService.o
LIB=lib/libpubsub.so

RM=rm -rf
MKDIR=mkdir -p
CP=cp -rv
SYNC=sync
BACKUPS=*~


all:
	$(CXX) $(CFLAGS) $(SRC) $(IFLAGS)
	$(CXX) $(SHARED) $(LFLAGS) $(LIB) $(OBJ)

clean:
	$(RM) $(OBJ) $(LIB) $(BACKUPS)

install:
	$(MKDIR) $(INSTALL_DIR)
	$(MKDIR) $(INSTALL_DIR)/include/pubsub/
	$(CP) $(INC) $(INSTALL_DIR)/include/pubsub/
	$(CP) $(LIB) $(INSTALL_DIR)/lib/
	$(SYNC)
