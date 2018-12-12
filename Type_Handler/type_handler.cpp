#include <typeinfo>
#include <typeindex>
#include <unordered_map>
#include <iostream>
#include <memory>

/*
 * Implement a TypeMap that allows different handlers to be registered
 * for different types.  The TypeMap can then be called with a value, and
 * asked to handle it.  This should cause dispatch to the registered
 * handler.
 *
 * Hint:  First create a map to map from type_info objects to handlers.
 * Store the handler in the map when it is registered.  When a value needs
 * to be handled, wrap it in a common Value base class, hiding the value
 * inside a derived class template.  Pass the Value to the handler.
 *
 * A suggested, but not required, definition of the base TypeHandler class is:
 *
 *     // Do not change this class.
 *     class TypeHandler {
 *         public:
 *             virtual void handle(std::shared_ptr<Value> v) = 0;
 *     };
 *
 * You must be able to add new types without changing any existing code.  For
 * example, I must be able to write a B_handler to handle a class B without
 * changing any of the code that you write.  Failure to follow this requirement
 * will limit your maximum credit to 50%.
 */

struct A {
    double x, y;
};


struct TypeNotRegistered {};

// PUT YOUR CODE HERE.

/*
Base class to each handler
*/
class Value {
public:
	virtual void operator()() = 0; //abstract
};

class int_Handler : public Value {
	virtual void operator()() override {
		std::cout << "int" << std::endl;
	}
};

class A_Handler : public Value {
	virtual void operator()() override {
		std::cout << "A" << std::endl;
	}
};

class double_Handler : public Value {
	virtual void operator()() override {
		std::cout<< "double" << std::endl;
	}
};

class TypeMap {
	std::unordered_map<std::type_index, std::shared_ptr<Value>> handler_map;
public:
	template<typename V>
	void registr(const std::type_info& t, const V& v) {
		handler_map[std::type_index(t)] = v;
	}

	template<typename T>
	void handle(T t) {
		//(*handler_map[std::type_index(typeid(t))])();
		auto it = handler_map.find(std::type_index(typeid(t)));
		if(it == handler_map.end()) {
			throw TypeNotRegistered();
		} else {
			(*it->second)();
		}
	}
};


int
main() {

    TypeMap tm;
    // Registers a handler for a type.
    tm.registr(typeid(int), std::make_shared<int_Handler>());
    tm.registr(typeid(A), std::make_shared<A_Handler>());

    // Calls the appropriate type handler with the given value.
    tm.handle(2); // Calls int_Handler.
    tm.handle(A{1.1, 2.2});
    try {
        tm.handle(1.1);
    } catch (const TypeNotRegistered &e) {
        std::cerr << "double not registered." << std::endl;
    }
    tm.registr(typeid(double), std::make_shared<double_Handler>());
    tm.handle(3.3);
}
