# makefile for new Student_info program
CXX = g++
CXXFLAGS = -Wall -g
objects = 10-1.o \
	Student_info.o letter_grade_array.o

edit: $(objects)
	g++ -o edit $(objects)

10-1.o: Student_info.h
	g++ -c 10-1.cpp

Student_info.o: Student_info.cpp Student_info.h letter_grade_array.h
	g++ -c Student_info.cpp
	
letter_grade_array.o: letter_grade_array.cpp letter_grade_array.h
	g++ -c letter_grade_array.cpp
	
10-2.o:
	g++ -o 10-2.o
	

	
clean:
	rm *.o