/*
 * This example code shows how the Decorator pattern can be implemented in C++.
 *
 * In this example, the Vehicle class serves as the base, and decorators such as 
 * GPSDecorator and BluetoothDecorator enhance the base vehicle by adding features.
 */

 #include <iostream>

// Interface for all vehicles
class Vehicle {
public:
    virtual void showInfo() const {
        std::cout << "Base Vehicle" << std::endl;
    }
    virtual ~Vehicle() {}
};

// Decorator class for adding GPS functionality to a vehicle
class GPSDecorator : public Vehicle {
protected:
    Vehicle* vehicle;
public:
    GPSDecorator(Vehicle* _vehicle) : vehicle(_vehicle) {}
    void showInfo() const override {
        vehicle->showInfo();
        std::cout << "GPS added" << std::endl;
    }
};

// Decorator class for adding Bluetooth functionality to a vehicle
class BluetoothDecorator : public Vehicle {
protected:
    Vehicle* vehicle;
public:
    BluetoothDecorator(Vehicle* _vehicle) : vehicle(_vehicle) {}
    void showInfo() const override {
        vehicle->showInfo();
        std::cout << "Bluetooth added" << std::endl;
    }
};

// Concrete implementation of a basic vehicle
class BasicVehicle : public Vehicle {
public:
    void showInfo() const override {
        std::cout << "Base Vehicle" << std::endl;
    }
};

int main() {
    Vehicle* basicVehicle = new BasicVehicle();
    Vehicle* vehicleWithGPS = new GPSDecorator(basicVehicle);
    Vehicle* vehicleWithBluetooth = new BluetoothDecorator(vehicleWithGPS);

    vehicleWithBluetooth->showInfo();

    // Clean up the dynamically allocated memory
    delete vehicleWithBluetooth;
    delete vehicleWithGPS;
    delete basicVehicle;

    return 0;
}