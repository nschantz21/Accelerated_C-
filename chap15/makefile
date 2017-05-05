OBJS = Pic.o Str.o Vec_clone.o main_test.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
# <macro_name> = <macro_string>
# <target>: [ <dependency > ]*
#   	[ <TAB> <command> <endl> ]+

# CC The name of the compiler
# DEBUG The debugging flag. This is -g in both g++ and cxx. The purpose of the flag is to include debugging information into the executable, so that you can use utilities such as gdb to debug the code.
 #LFLAGS The flags used in linking. As it turns out, you don't need any special flags for linking. The option listed is "-Wall" which tells the compiler to print all warnings. But that's fine. We can use that.
# CFLAGS The flags used in compiling and creating object files. This includes both "-Wall" and "-c". The "-c" option is needed to create object files, i.e. .o files.

all: my_program

my_program: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o my_program

main_test.o: Pic.h Vec.h Str.h
	$(CC) $(CFLAGS) main_test.cpp

Pic.o: Pic.h Str.h Ptr.h Vec.h
	$(CC) $(CFLAGS) Pic.cpp

Str.o: Vec.h Ptr.h Str.h
	$(CC) $(CFLAGS) Str.cpp

Vec_clone.o: Vec.h
	$(CC) $(CFLAGS) Vec_clone.cpp
	
clean:
	\rm *.o *~ my_program