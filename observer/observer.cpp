/*
* This example code shows how the Observer pattern can be implemented in C++.
*
* The Observer pattern is a behavioral design pattern that lets us define a subscription 
* mechanism to notify multiple objects about any events that happen to the object they’re observing. 
* Observer defines a one-to-many dependency between objects so that when one object changes state, 
* all its dependents are notified and updated automatically.
*
*/

#include <iostream>
#include <vector>
#include <algorithm> // Needed for std::remove

class IObserver {
public:
    virtual ~IObserver() {}
    virtual void update() = 0;
};

class ISubject {
public:
    virtual ~ISubject() {}
    virtual void attach(IObserver* observer) = 0;
    virtual void detach(IObserver* observer) = 0;
    virtual void notify() = 0;
};

class ConcreteObserver : public IObserver {
public:
    ConcreteObserver(const std::string& name) : observer_name(name) {}
    void update() override { std::cout << "Observer " << observer_name << " is notified." << std::endl; }
private:
    std::string observer_name;
};

class ConcreteSubject : public ISubject {
public:
    void attach(IObserver* observer) override { observer_list.push_back(observer); }
    void detach(IObserver* observer) override {
        observer_list.erase(std::remove(observer_list.begin(), observer_list.end(), observer), observer_list.end());
    }
    void notify() override {
        for (auto& observer : observer_list) {
            observer->update();
        }
    }
private:
    std::vector<IObserver*> observer_list;
};

int main() {
    ConcreteSubject subject;
    ConcreteObserver observer1("1");
    ConcreteObserver observer2("2");
    subject.attach(&observer1);
    subject.attach(&observer2);
    subject.notify();

    // Detach observer1 and notify again to see it's no longer notified
    subject.detach(&observer1);
    subject.notify();
}
