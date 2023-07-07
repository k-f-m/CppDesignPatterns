/*
 * This example code shows how the Adapter pattern can be implemented in C++.
 *
 * In this example, we have an ITarget interface that defines the expected interface for our code. 
 * We also have an Adaptee class that has a different interface than what our code expects. 
 * Finally, we have an Adapter class that implements the ITarget interface and uses the Adaptee class internally.
 */

#include <iostream>
#include <string>

class ITarget {
public:
    virtual ~ITarget() = default;
    virtual std::string Request() const = 0;
};

class Adaptee {
public:
    std::string SpecificRequest() const {
        return "Adaptee::SpecificRequest";
    }
};

class Adapter : public ITarget {
public:
    explicit Adapter(const Adaptee& adaptee) : adaptee_(adaptee) {}

    std::string Request() const override {
        return "Adapter::Request " + adaptee_.SpecificRequest();
    }

private:
    const Adaptee& adaptee_;
};

int main() {
    Adaptee adaptee;
    Adapter adapter(adaptee);
    std::cout << adapter.Request() << std::endl;
}