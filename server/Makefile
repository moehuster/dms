# DMS Makefile
CPP      = g++
PROC     = proc
INC_DIR  = ../include
SYS_LIBS = -lpthread -lclntsh
CCFLAGS  = -O2 -Wall -std=c++0x
LIB_DIR  = $(ORACLE_HOME)/lib
PROCFLAGS= iname=$< oname=$@ parse=none
OBJECTS  = dms_server.o userdata.o logdao.o
TARGETS  = main

$(TARGETS): $(OBJECTS)
	$(CPP) $(CCFLAGS) $(SYS_LIBS) $(OBJECTS) -o $@

%.o: %.cpp
	$(CPP) $(CCFLAGS) -I$(INC_DIR) -c $<

%.cpp: %.pc
	$(PROC) $(PROCFLAGS) code=cpp

clean:
	rm --force $(TARGETS) *.o *.lis
