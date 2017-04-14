# makefile for new Student_info program
CXX = g++
CXXFLAGS = -Wall -g
objects = main.o Student_info.o letter_grade_array.o

a.out: $(objects)
	g++ -o a.out $(objects)

main.o:  main.cpp Student_info.h
	g++ -c main.cpp
	
Student_info.o: Student_info.cpp Student_info.h letter_grade_array.h
	g++ -c Student_info.cpp
	
letter_grade_array.o: letter_grade_array.cpp letter_grade_array.h
	g++ -c letter_grade_array.cpp

	
clean:
	rm *.o