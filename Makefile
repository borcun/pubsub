include Makefile.dirs
include Makefile.libs

CXX=g++
CFLAGS=-c -Wall -fPIC -std=c++20
LFLAGS=-o
IFLAGS=-I $(INC)
SRC=src/message.cpp src/messageFactory.cpp src/subscriber.cpp src/publisher.cpp src/messageService.cpp
OBJ=message.o messageFactory.o subscriber.o publisher.o messageService.o

.PHONY: all
all:
	$(CXX) $(CFLAGS) $(SRC) $(IFLAGS)
	$(CXX) $(SHARED) $(LFLAGS) $(LIB) $(OBJ)
	cd $(EXAMPLEDIR) && make

.PHONY: clean
clean:
	rm -rf $(OBJ) $(LIB) *~
	cd $(EXAMPLEDIR) && make clean

.PHONY: install
install: all
	mkdir $(INSTALL_DIR)
	mkdir $(INSTALL_DIR)/include/pubsub/
	cp $(INC)/* $(INSTALL_DIR)/include/pubsub/
	mkdir $(INSTALL_DIR)/lib/
	cp $(LIB) $(INSTALL_DIR)/lib/
	sync
