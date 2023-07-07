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