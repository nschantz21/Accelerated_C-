# don't use this

CXX = g++
CXXFLAGS = -Wall -g
blobjects = frame_test.o frame.o split.o
objects = student_test.o \
	Student_info.o

student: $(objects)
	g++ -o student $(objects)

student_test: Student_info.h Vec.h
	g++ -c student_test.cpp

Student_info.o: Student_info.h Vec.h
	g++ -c Student_info.cpp
	
letter_grade_array.o: letter_grade_array.h
	g++ -c letter_grade_array.cpp
	
clean:
	rm *.o