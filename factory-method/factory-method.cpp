/*
 * This code shows how the Factory Method pattern can be implemented in C++.
 *
 * The Factory Method is a creational design pattern that provides an interface
 * for creating objects in a superclass, but allows subclasses to alter the type of objects that will be created.
 */

#include <iostream>
using namespace std;

class Product {
public:
    virtual void print() = 0;
};

class ConcreteProduct1 : public Product {
public:
    void print() {
        cout << "ConcreteProduct1" << endl;
    }
};

class ConcreteProduct2 : public Product {
public:
    void print() {
        cout << "ConcreteProduct2" << endl;
    }
};

class Creator {
public:
    virtual Product* factoryMethod() = 0;
    void someOperation() {
        Product* product = factoryMethod();
        product->print();
    }
};

class ConcreteCreator1 : public Creator {
public:
    Product* factoryMethod() {
        return new ConcreteProduct1();
    }
};

class ConcreteCreator2 : public Creator {
public:
    Product* factoryMethod() {
        return new ConcreteProduct2();
    }
};

int main() {
    Creator* creator = new ConcreteCreator1();
    creator->someOperation();

    creator = new ConcreteCreator2();
    creator->someOperation();

    return 0;
}
