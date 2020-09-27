#simplifying makefile and ensuring latest c++ standard
CXX=g++
CXXFLAGS=-g -std=c++17

#compile and link the application
all: main

#run the application
run: main
	./main

#link main.o, time.o, and date.o to executable main
main: main.o time.o date.o
	$(CXX) -o main main.o time.o date.o

#compile the main.cpp to main.o
main.o: main.cpp
	$(CXX) -c main.cpp

#compile the time.cpp to time.o
time.o: time.cpp
	$(CXX) -c time.cpp

#compile the date.cpp to date.o
date.o: date.cpp
	$(CXX) -c date.cpp

#remove built files
clean:
	rm -rf main main.o time.o date.o *~
