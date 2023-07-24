/*
* This example shows how the Iterator pattern can be implemented in C++.
*
* Iterator is a behavioral design pattern that allows us to sequentially traverse a 
* complex data structure without exposing its internal details.
*
* In this example, the Iterator class provides the interface for iterating over elements, 
* and the Aggregate class provides the interface for creating iterators.
* Concrete implementations 'ConcreteIterator' and 'ConcreteAggregate' handle the specific functionalities. 
* As a result, the high-level main function relies on abstractions (Aggregate and Iterator) rather than concrete classes, 
* promoting a more flexible and decoupled design.
*/

#include <iostream>
#include <vector>

// Interface for the Iterator
class Iterator {
public:
    virtual bool hasNext() = 0;
    virtual int next() = 0;
    virtual ~Iterator() {}
};

// Interface for the Aggregate
class Aggregate {
public:
    virtual Iterator* createIterator() = 0;
    virtual ~Aggregate() {}
};

// ConcreteIterator provides the implementation for Iterator
class ConcreteIterator : public Iterator {
public:
    ConcreteIterator(const std::vector<int>& v) : vec(v), pos(0) {}
    bool hasNext() override {
        return pos < vec.size();
    }
    int next() override {
        return vec[pos++];
    }
private:
    const std::vector<int>& vec;
    int pos;
};

// ConcreteAggregate provides the implementation for Aggregate
class ConcreteAggregate : public Aggregate {
public:
    ConcreteAggregate(const std::vector<int>& v) : vec(v) {}
    Iterator* createIterator() override {
        return new ConcreteIterator(vec);
    }
private:
    const std::vector<int>& vec;
};

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};

    // Using Abstractions (Interfaces) to decouple the code
    Aggregate* agg = new ConcreteAggregate(v);
    Iterator* it = agg->createIterator();
    while (it->hasNext()) {
        std::cout << it->next() << std::endl;
    }

    // Clean up the allocated memory
    delete it;
    delete agg;
}