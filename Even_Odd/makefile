all:
	g++ -g -std=c++17 evenodd.cpp -o evenodd
run:
	./evenodd
checkmem:
	valgrind --tool=memcheck --leak-check=full ./evenodd
clean:
	rm evenodd
