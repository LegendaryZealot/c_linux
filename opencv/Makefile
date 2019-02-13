# CC = g++
# CFLAGS = -g -Wall
# SRCS = main.cpp
# PROG = app

# OPENCV = `pkg-config opencv --cflags --libs`
# LIBS = $(OPENCV)

# $(PROG):$(SRCS)
# 	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)
# clean:
# 	rm $(PROG)
TARGET  := app

SOURCE  := $(wildcard *.c) $(wildcard *.cpp)
OBJS    := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))
OPENCVLIB = `pkg-config opencv --cflags --libs`

CC      := g++
LIBS    := $(OPENCVLIB)
LDFLAGS :=
INCLUDE := -I.
CFLAGS  := -g -Wall -O3 $(DEFINES) $(INCLUDE)
CXXFLAGS:= $(CFLAGS) -DHAVE_CONFIG_H

.PHONY : everything objs clean veryclean rebuild

everything : $(TARGET)

all : $(TARGET)

run:everything
	./$(TARGET)

objs : $(OBJS)

rebuild: veryclean everything
                
clean :
	-rm -f $(OBJS)
    
veryclean : clean
	-rm -f $(TARGET)
  
$(TARGET) : $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(LIBS)