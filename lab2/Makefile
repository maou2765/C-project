all: dictionary
dictionary: Dictionary.o Pair.o main.o
	g++ -o dict Dictionary.o Pair.o main.o
main.o: main.cpp Dictionary.h
	g++ -c main.cpp
Dictionary.o: Dictionary.cpp Dictionary.h
	g++ -c Dictionary.cpp
Pair.o: Pair.cpp Pair.h
	g++ -c Pair.cpp
clean:
	rm *.o
