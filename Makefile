UNAME_S=$(shell uname -s)
# directories
INC=inc
INSTALL_DIR=/usr/local

CXX=g++
CFLAGS=-c -Wall -fPIC -std=c++20
LFLAGS=-o
IFLAGS=-I $(INC)
SRC=src/message.cpp src/messageFactory.cpp src/subscriber.cpp src/publisher.cpp src/messageService.cpp
OBJ=message.o messageFactory.o subscriber.o publisher.o messageService.o
# select library output and library type according to OS
ifeq ($(UNAME_S),Linux)
SHARED=-shared
LIB=lib/libpubsub.so
endif
ifeq ($(UNAME_S),Darwin)
SHARED=-dynamiclib
LIB=lib/libpubsub.dylib
endif
# utilities
RM=rm -rf
MKDIR=mkdir -p
CP=cp -rv
SYNC=sync
BACKUPS=*~

.PHONY: all
all:
	$(CXX) $(CFLAGS) $(SRC) $(IFLAGS)
	$(CXX) $(SHARED) $(LFLAGS) $(LIB) $(OBJ)

.PHONY: clean
clean:
	$(RM) $(OBJ) $(LIB) $(BACKUPS)

.PHONY: install
install: all
	$(MKDIR) $(INSTALL_DIR)
	$(MKDIR) $(INSTALL_DIR)/include/pubsub/
	$(CP) $(INC)/* $(INSTALL_DIR)/include/pubsub/
	$(MKDIR) $(INSTALL_DIR)/lib/
	$(CP) $(LIB) $(INSTALL_DIR)/lib/
	$(SYNC)
