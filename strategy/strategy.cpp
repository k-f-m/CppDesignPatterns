/*
 * This example code shows how the Strategy pattern can be implemented in C++.
 *
 * The Strategy class is an abstract base class that defines the interface for the concrete strategies. 
 * The ConcreteStrategyA and ConcreteStrategyB classes are concrete implementations of the Strategy interface. 
 * The Context class maintains a reference to a Strategy object and delegates it to the current Strategy object for executing the algorithm.
 */

#include <iostream>
#include <vector>
#include <memory>

class Strategy {
public:
    virtual void execute() = 0;
};

class ConcreteStrategyA : public Strategy {
public:
    void execute() override {
        std::cout << "Executing strategy A" << std::endl;
    }
};

class ConcreteStrategyB : public Strategy {
public:
    void execute() override {
        std::cout << "Executing strategy B" << std::endl;
    }
};

class Context {
public:
    Context(std::unique_ptr<Strategy> strategy) : current_strategy(std::move(strategy)) {}

    void set_strategy(std::unique_ptr<Strategy> strategy) {
        current_strategy = std::move(strategy);
    }

    void execute_strategy() {
        current_strategy->execute();
    }

private:
    std::unique_ptr<Strategy> current_strategy;
};

int main() {
    auto context = Context(std::make_unique<ConcreteStrategyA>());
    context.execute_strategy();

    context.set_strategy(std::make_unique<ConcreteStrategyB>());
    context.execute_strategy();

    return 0;
}