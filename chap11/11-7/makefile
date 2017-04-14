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
	

framing: $(blobjects)
	g++ -o blobs $(blobjects)

frame_test.o: frame.h split.h Vec.h
	g++ -c frame_test.cpp
	
frame.cpp: frame.h Vec.h
	g++ -c frame.cpp
	
split.o: split.h Vec.h
	g++ -c split.cpp
	

	

	
clean:
	rm *.o