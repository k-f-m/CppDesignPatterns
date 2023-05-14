/*
 * This code shows how the Singleton pattern can be implemented in C++ in a non-thread-safe way.
 *
 * The Singleton pattern ensures that a class has only one instance and provides a global point of access to it.
 */

#include <iostream>

class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    void showMessage() {
        std::cout << "An instance of a Singleton\n";
    }

private:
    Singleton() {}
    Singleton(Singleton const&) = delete;
    void operator = (Singleton const&) = delete;
};

int main() {

    Singleton::getInstance().showMessage();

    return 0;
}