a: final.o grade.o median.o
	g++ -o a final.o grade.o median.o
final.o: final.cpp
	g++ -c final.cpp
grade.o : grade.cpp
	g++ -c grade.cpp
median.o : median.cpp
	g++ -c median.cpp
all: a
clean:
	rm -f *.o a
