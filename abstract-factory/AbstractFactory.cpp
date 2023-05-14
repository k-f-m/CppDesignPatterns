/*
 * This code demonstrates how to use the Abstract Factory pattern in C++ to create a GUI factory that can create
 * buttons and checkboxes for different platforms (Windows and Mac).
 *
 * The Abstract Factory pattern provides an interface for creating families of related objects without specifying
 * their concrete classes.
 */

#include <iostream>
using namespace std;

class Button {
public:
    virtual void paint() = 0;
};

class WinButton : public Button {
public:
    void paint() {
        cout << "Windows Button" << endl;
    }
};

class MacButton : public Button {
public:
    void paint() {
        cout << "Mac Button" << endl;
    }
};

class CheckBox {
public:
    virtual void paint() = 0;
};

class WinCheckBox : public CheckBox {
public:
    void paint() {
        cout << "Windows CheckBox" << endl;
    }
};

class MacCheckBox : public CheckBox {
public:
    void paint() {
        cout << "Mac CheckBox" << endl;
    }
};

class GUIFactory {
public:
    virtual Button* createButton() = 0;
    virtual CheckBox* createCheckBox() = 0;
};

class WinFactory : public GUIFactory {
public:
    Button* createButton() {
        return new WinButton();
    }

    CheckBox* createCheckBox() {
        return new WinCheckBox();
    }
};

class MacFactory : public GUIFactory {
public:
    Button* createButton() {
        return new MacButton();
    }

    CheckBox* createCheckBox() {
        return new MacCheckBox();
    }
};

int main()
{
 // Create an instance of the factory based on the platform
#ifdef WIN32
    GUIFactory* factory = new WinFactory();
#else
    GUIFactory* factory = new MacFactory();
#endif

    // Use the factory to create a button and a checkbox
    Button* button = factory->createButton();
    button->paint();

    CheckBox* checkbox = factory->createCheckBox();
    checkbox->paint();

    // Clean up
    delete button;
    delete checkbox;
}