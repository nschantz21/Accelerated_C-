CXX = g++
CXXFLAGS = -Wall -g
blobjects = split_test.o frame.o split.o

framing: $(blobjects)
	g++ -o blobs $(blobjects)

frame_test.o: frame.h split.h Vec.h
	g++ -c frame_test.cpp
	
frame.cpp: frame.h Vec.h
	g++ -c frame.cpp
	
split.o: split.h Vec.h Str.h
	g++ -c split.cpp
	

	

	

	
clean:
	rm *.o