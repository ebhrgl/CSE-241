all: hello

hello: hw2.o 
	g++ hw2.o -o exe 

hw2.o: hw2.cpp
	g++ -c hw2.cpp --std=c++11

clean:
	rm *.o exe
