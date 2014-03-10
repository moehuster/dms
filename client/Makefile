# DMS Makefile
CPP      = g++
INC_DIR  = ../include
SYS_LIBS = -lm
CCFLAGS  = -O2 -Wall -std=c++0x
LIB_DIR  = 
TARGET   = main
OBJECTS  = logreader.o logreader_test.o

$(TARGET): $(OBJECTS)
	$(CPP) $(CCFLAGS) $(SYS_LIBS) $(OBJECTS) -o $@

%.o: %.cpp
	$(CPP) $(CCFLAGS) -I$(INC_DIR) -c $<

clean:
	rm --force $(OBJECTS) $(TARGET)
