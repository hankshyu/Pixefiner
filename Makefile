CXX = g++
FLAGS = -std=c++17
CFLAGS = -c
DEBUGFLAGS = -g

SRCPATH = ./src
BINPATH = ./bin
BOOSTPATH = ./boost_1_72_0/ # ! Remember to specify the path

all: pxrun
debug: pxrun_debug

# LINKFLAGS = -pedantic -Wall -fomit-frame-pointer -funroll-all-loops -O3
LINKFLAGS = -O3

pxrun: main.o monitor.o cord.o
	$(CXX) $(FLAGS) -I $(BOOSTPATH) $(LINKFLAGS) $^ -o $(BINPATH)/$@

main.o: $(SRCPATH)/main.cpp 
	$(CXX) $(FLAGS) -I $(BOOSTPATH) $(CFLAGS) $(LINKFLAGS) -DCOMPILETIME="\"`date`\"" $^ -o $@

%.o: $(SRCPATH)/%.cpp $(SRCPATH)/%.h
	$(CXX) $(FLAGS) -I $(BOOSTPATH) $(CFLAGS) $(LINKFLAGS) $< -o $@



pxrun_debug: main_db.o monitor_db.o cord_db.o
	$(CXX) $(DEBUGFLAGS) -I $(BOOSTPATH) $(LINKFLAGS) $^ -o $(BINPATH)/$@

main_db.o: $(SRCPATH)/main.cpp 
	$(CXX) $(DEBUGFLAGS) -I $(BOOSTPATH) $(CFLAGS) -DCOMPILETIME="\"`date`\"" $^ -o $@

%_db.o: $(SRCPATH)/%.cpp $(SRCPATH)/%.h
	$(CXX) $(DEBUGFLAGS) -I $(BOOSTPATH) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o *.gch *.out $(BINPATH)/* 

