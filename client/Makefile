# DMS Makefile
CPP      = g++
INC_DIR  = ../include
SYS_LIBS = -lm
CCFLAGS  = -O2 -Wall -std=c++0x
LIB_DIR  = 
TARGETS  = main except.out file.out
OBJECTS  = logreader.o logreader_test.o
all:$(TARGETS)

file.out: file_test.o
	$(CPP) $(CCFLAGS) $(SYS_LIBS) $< -o $@

except.out: dms_exception_test.o
	$(CPP) $(CCFLAGS) $(SYS_LIBS) $< -o $@

main: $(OBJECTS)
	$(CPP) $(CCFLAGS) $(SYS_LIBS) $(OBJECTS) -o $@

%.o: %.cpp
	$(CPP) $(CCFLAGS) -I$(INC_DIR) -c $<

clean:
	rm --force $(TARGETS) *.o
