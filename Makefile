CXX = g++
FLAGS = -std=c++17
CFLAGS = -c
OPTFLAGS = -o3
DEBUGFLAGS = -g

SRCPATH = ./src
BINPATH = ./bin
OBJPATH = ./obj
BOOSTPATH = ./boost_1_84_0/ # ! Remember to specify the path
GLPKPATH = ./glpk-5.0/src/


all: csrun
debug: csrun_debug

# LINKFLAGS = -pedantic -Wall -fomit-frame-pointer -funroll-all-loops -O3
LINKFLAGS = -lglpk -lm 
GLPKLINKPATH = /usr/local/lib

_OBJS =	main.o \
		cSException.o globalResult.o \
		cord.o rectangle.o doughnutPolygon.o tile.o \
		cornerStitching.o rectilinear.o connection.o \
		eVector.o  legalResult.o line.o units.o \
		floorplan.o
		
OBJS = $(patsubst %,$(OBJPATH)/%,$(_OBJS))
DBG_OBJS = $(patsubst %.o, $(OBJPATH)/%_dbg.o, $(_OBJS))

csrun: $(OBJS)
	$(CXX) $(FLAGS) -L $(GLPKLINKPATH) $(LINKFLAGS) $^ -o $(BINPATH)/$@

$(OBJPATH)/main.o: $(SRCPATH)/main.cpp 
	$(CXX) $(FLAGS) -I $(BOOSTPATH) -I $(GLPKPATH) $(CFLAGS) $(OPTFLAGS) -DCOMPILETIME="\"`date`\"" $^ -o $@

$(OBJPATH)/%.o: $(SRCPATH)/%.cpp $(SRCPATH)/%.h
	$(CXX) $(FLAGS) -I $(BOOSTPATH) -I $(GLPKPATH) $(CFLAGS) $(OPTFLAGS) $< -o $@


csrun_debug: $(DBG_OBJS)
	$(CXX) $(DEBUGFLAGS) -L $(GLPKLINKPATH) $(LINKFLAGS) $^ -o $(BINPATH)/$@

$(OBJPATH)/main_dbg.o: $(SRCPATH)/main.cpp 
	$(CXX) $(DEBUGFLAGS) -I $(BOOSTPATH) -I $(GLPKPATH) $(CFLAGS) -DCOMPILETIME="\"`date`\"" $^ -o $@

$(OBJPATH)/%_dbg.o: $(SRCPATH)/%.cpp $(SRCPATH)/%.h
	$(CXX) $(DEBUGFLAGS) -I $(BOOSTPATH) -I $(GLPKPATH) $(CFLAGS) $< -o $@



.PHONY: clean
clean:
	rm -rf *.gch *.out $(OBJPATH)/* $(BINPATH)/* 

