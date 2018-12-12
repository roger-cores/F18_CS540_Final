/*
 * Write a variadic function template named evenodd that return 0 if called
 * with an even number of arguments, and 1 if called with an odd number of
 * arguments.
 */

#include <iostream>
#include <array>

template <typename... Params>
int evenodd(Params... params) {
    return (sizeof...(params)) % 2 != 0;
}

int evenodd() {
	return 0;
}

class Base {
	int x;
	public:
		Base() : x(0) {}
		Base(int x) : x(x) {} 
};

// PUT YOUR CODE HERE.

int
main() {

    /*
     * Below should print out:
     * 0
     * 1
     * 1
     * 0
     * 0
     * 1
     * 0
     */
    std::cout << evenodd() << std::endl;
    std::cout << evenodd(1) << std::endl;
    std::cout << evenodd(1.1) << std::endl;
    std::cout << evenodd(1, 1.1) << std::endl;
    std::cout << evenodd(1.1, 1) << std::endl;
    int *p;
    std::cout << evenodd(1, p, 1, p, 1, p, 1, p, 1, p, 1, p, 3.14) << std::endl;
    std::cout << evenodd("a", 1, p, 1, p, 1, p, 1, p, 1, p, 1, p, 3.14) << std::endl;

    Base b;
    std::cout << evenodd(3.5, b) << std::endl;

}
