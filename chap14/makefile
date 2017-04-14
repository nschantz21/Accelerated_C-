# makefile for new Student_info program
CXX = g++
CC = g++
CXXFLAGS = -Wall -g


urls_main:	urls_main.o urls.o Vec_clone.o Str.o

urls_main.o:	urls_main.cpp urls.h Vec.h Str.h 

urls.o:	urls.cpp urls.h Vec.h Str.h

Vec_clone.o:	Vec_clone.cpp Vec.h

Str.o:  Str.cpp Str.h Ptr.h

clean:
	rm *.o
	
