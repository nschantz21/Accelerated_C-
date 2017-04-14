# makefile for new Student_info program
CXX = g++
CXXFLAGS = -Wall -g
objects = main.o \
	Student_info.o

edit: $(objects)
	g++ -o edit $(objects)

main.o: Student_info.h

Student_info.o: Student_info.cpp Student_info.h
	g++ -c Student_info.cpp
clean:
	rm *.o