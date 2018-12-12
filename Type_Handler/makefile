all:
	g++ -g -std=c++17 -fmax-errors=2 type_handler.cpp -o th
run:
	./th
checkmem:
	valgrind --tool=memcheck --leak-check=full ./th
clean:
	rm th
