/*
* This example shows how to use the Prototype pattern in C++.
*
* We have an abstract prototype interface (Drawable) and concrete prototype classes (Circle and Rectangle).
* The Circle and Rectangle objects play the role of prototypes.
* DrawingService acts as a client that uses these prototypes to create and draw shapes without 
* needing to know their internal details.
*/

#include <iostream>
#include <memory>

// Interface for a drawable shape
class Drawable {
public:
    virtual ~Drawable() {}
    virtual void draw() const = 0;
};

// Concrete implementation of a circle
class Circle : public Drawable {
public:
    Circle(int x, int y, int radius) : x_(x), y_(y), radius_(radius) {}
    void draw() const override {
        std::cout << "Drawing circle at (" << x_ << ", " << y_ << ") with radius " << radius_ << std::endl;
    }
private:
    int x_;
    int y_;
    int radius_;
};

// Concrete implementation of a rectangle
class Rectangle : public Drawable {
public:
    Rectangle(int x, int y, int width, int height) : x_(x), y_(y), width_(width), height_(height) {}
    void draw() const override {
        std::cout << "Drawing rectangle at (" << x_ << ", " << y_ << ") with width " << width_ << " and height " << height_ << std::endl;
    }
private:
    int x_;
    int y_;
    int width_;
    int height_;
};

// Drawing service to draw different shapes
class DrawingService {
public:
    void drawShape(const Drawable& shape) {
        shape.draw();
    }
};

int main() {
    auto circle = std::make_unique<Circle>(10, 20, 20);
    auto rectangle = std::make_unique<Rectangle>(50, 50, 30, 50);

    DrawingService drawingService;
    drawingService.drawShape(*circle);
    drawingService.drawShape(*rectangle);

    return 0;
}