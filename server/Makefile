# DMS Makefile
CPP      = g++
INC_DIR  = ../include
SYS_LIBS = -lpthread
CCFLAGS  = -O2 -Wall -std=c++0x
LIB_DIR  = 
TARGETS  = main
OBJECTS  = dms_server.o userdata.o
all:$(TARGETS)

main: $(OBJECTS)
	$(CPP) $(CCFLAGS) $(SYS_LIBS) $(OBJECTS) -o $@

%.o: %.cpp
	$(CPP) $(CCFLAGS) -I$(INC_DIR) -c $<

clean:
	rm --force $(TARGETS) *.o
