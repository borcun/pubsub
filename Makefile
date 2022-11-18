include Makefile.dirs
include Makefile.cmd

IFLAGS=-I $(INC)
SRC=src/message.cpp src/messageFactory.cpp src/subscriber.cpp src/publisher.cpp src/messageService.cpp
OBJ=message.o messageFactory.o subscriber.o publisher.o messageService.o
SHARED=-shared
LIB=lib/libpubsub.so

.PHONY: all
all:
	$(CXX) $(CFLAGS) -fPIC $(SRC) $(IFLAGS)
	$(CXX) $(SHARED) $(LFLAGS) $(LIB) $(OBJ)
	cd $(EXAMPLE_DIR) && make

.PHONY: clean
clean:
	rm -rf $(OBJ) $(LIB) *~
	cd $(EXAMPLE_DIR) && make clean

.PHONY: install
install:
	mkdir -p $(INC_DIR)
	cp $(INC)/* $(INC_DIR)
	mkdir -p $(LIB_DIR)
	cp $(LIB) $(LIB_DIR)
	sync
