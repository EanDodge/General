main: fileio.o 
	clang++ -Wall fileio.o -o main

fileio.o: fileio.cpp
	clang++ -Wall -c fileio.cpp

clean:
	rm -f *.o
	rm -f main
