/*
 * The builder pattern is a creational design pattern that enables us construct complex objects step by step. 
 * The pattern lets us produce different types and representations of an object using the same construction code.
 * 
 * The builder pattern generally involves three main components:
 * 1. The Builder interface: This interface defines all possible construction steps and provides methods for getting the final result.
 * 2. The Concrete Builder: This class implements the Builder interface and provides specific implementations of the construction steps.
 * 3. The Director (optional): This class is responsible for managing the construction process and calling the appropriate methods on the builder.
 *
 * The builder pattern is useful when we need to create complex objects with many optional parameters or when we want to reuse the same construction code to produce different representations of an object.
 */

#include <iostream>
#include <string>
#include <vector>
#include <memory>

// Different models of cars can have different features
// A car (product) can have a brand, model, the year it's
// produced, engine type, and color.
class Car {
public:
    void setBrand(const std::string& brand) {
        carBrand = brand;
    }
    void setModel(const std::string& model) {
        carModel = model;
    }
    void setYear(const int& year) {
        productionYear = year;
    }
    void setEngineType(const std::string& engType) {
        engineType = engType;
    }
     void setcolor(const std::string& color) {
        carColor = color;
    }

    void printProperties() const {
        std::cout << "Car with brand " << carBrand << ", model " << carModel << ", year " << productionYear << ", engine type " << engineType << " and " << carColor << " color.\n";
    }

private:
    std::string carBrand;
    std::string carModel;
    int productionYear;
    std::string engineType;
    std::string carColor;
};

// The builder interface specifies methods for creating
// different parts of the product objects.
class CarBuilder {
public:
    virtual ~CarBuilder() {}

    Car* getCar() {
        return builtCarPointer.release();
    }

    void createNewCarProduct() {
        builtCarPointer = std::make_unique<Car>();
    }

    virtual void buildBrand() = 0;
    virtual void buildModel() = 0;
    virtual void buildYear() = 0;
    virtual void buildEngineType() = 0;
    virtual void buildcolor() = 0;

protected:
    std::unique_ptr<Car> builtCarPointer;
};

// The concrete builder class specifies implementations of building 
// steps and sets the car's properties to those of a sports car.
class SportsCarBuilder : public CarBuilder {
public:
    void buildBrand() override {
        builtCarPointer->setBrand("Ferrari");
    }
    void buildModel() override {
        builtCarPointer->setModel("F8 Tributo");
    }
    void buildYear() override {
        builtCarPointer->setYear(2022);
    }
    void buildEngineType() override {
        builtCarPointer->setEngineType("V8");
    }
    void buildcolor() override {
        builtCarPointer->setcolor("Plum Crazy Pearl");
    }
};

// The concrete builder class specifies implementations of building 
// steps and sets the car's properties to those of an SUV
class SUVBuilder : public CarBuilder {
public:
    void buildBrand() override {
        builtCarPointer->setBrand("Jeep");
    }
    void buildModel() override {
        builtCarPointer->setModel("Grand Cherokee");
    }
    void buildYear() override {
        builtCarPointer->setYear(2022);
    }
    void buildEngineType() override {
        builtCarPointer->setEngineType("V6");
    }
    void buildcolor() override {
        builtCarPointer->setcolor("Brilliant Black Crystal Pearl");
    }
};

// The director class definition constructs the car product 
// according to a specific order and configuration.
class Director {
public:
    void setBuilder(CarBuilder* builder) {
        builderObject = builder;
    }

    Car* getCar() {
        return builderObject->getCar();
    }

    void constructCar() {
        builderObject->createNewCarProduct();
        builderObject->buildBrand();
        builderObject->buildModel();
        builderObject->buildYear();
        builderObject->buildEngineType();
        builderObject->buildcolor();
    }

private:
    CarBuilder* builderObject;
};

int main() {
    Director director;

    SportsCarBuilder sportsCarBuilder;
    director.setBuilder(&sportsCarBuilder);
    director.constructCar();

    // The construction result obtained from the director
    // as all products follow the same interface.
    Car* sportsCar = director.getCar();
    sportsCar->printProperties();

    SUVBuilder suvBuilder;
    director.setBuilder(&suvBuilder);
    director.constructCar();

    Car* suv = director.getCar();
    suv->printProperties();

    delete sportsCar;
    delete suv;

    return 0;
}