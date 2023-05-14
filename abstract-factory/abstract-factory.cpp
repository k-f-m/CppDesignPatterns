/*
 * This code demonstrates how to use the Abstract Factory pattern in C++ to create a GUI factory that
 * can create buttons and checkboxes depending on the platform, namely Windows and Mac.
 *
 * The Abstract Factory pattern provides an interface for creating families of related objects without specifying
 * their concrete classes.
 */

#include <iostream>

class Button {
public:
    virtual void paint() = 0;
};

class WinButton : public Button {
public:
    void paint() {
        std::cout << "Windows Button" << std::endl;
    }
};

class MacButton : public Button {
public:
    void paint() {
        std::cout << "Mac Button" << std::endl;
    }
};

class CheckBox {
public:
    virtual void paint() = 0;
};

class WinCheckBox : public CheckBox {
public:
    void paint() {
        std::cout << "Windows CheckBox" << std::endl;
    }
};

class MacCheckBox : public CheckBox {
public:
    void paint() {
        std::cout << "Mac CheckBox" << std::endl;
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
#ifdef WIN32
    GUIFactory* factory = new WinFactory();
#else
    GUIFactory* factory = new MacFactory();
#endif

    Button* button = factory->createButton();
    button->paint();

    CheckBox* checkbox = factory->createCheckBox();
    checkbox->paint();

    delete button;
    delete checkbox;
}