#pragma once
#include <string>
#include <list>
#include <vector>
#include <iostream>
using namespace std;

class Vehicle {

private:
protected:
    int age;
    string reg_number, make, model, type;
public:
    Vehicle();

    ~Vehicle();

    static void addVehicle(vector<Vehicle *> &vec);

    static void removeVehicle(vector<Vehicle *> &vec);

    static void searchForCar(vector<Vehicle *> &vec);

    static void searchForBike(vector<Vehicle *> &vec);

    static void sortByCostPerDay(vector<Vehicle *> &vec);

    static void sortByRegistrationNumber(vector<Vehicle *> &vec);

    inline static void printVehicles(vector<Vehicle *> vec);

//    bool comparator(Vehicle &lhs, Vehicle &rhs);
    virtual int getCostPerDay();
    inline virtual int getAge() const;
    inline virtual void setAge(int age);
    inline virtual const string &getRegNumber() const;
    inline virtual void setRegNumber(const string &regNumber);
    inline virtual const string &getMake() const;
    inline virtual void setMake(const string &make);
    inline virtual const string &getModel() const;
    inline virtual void setModel(const string &model);
    inline const string &getType() const;
    inline void setType(const string &type);
};

void Vehicle::printVehicles(vector<Vehicle *> vec) {
    std::cout << "Registration Number  Cost Per Day	Vehicle Type\n";
    std::cout << "------------------ - ------------      ----------\n";
    for (auto & i : vec) {
        // Use typeid instead of having a type variable but make sure it is dereferenced
        std::cout << i->getRegNumber() << "\t\t\t" << i->getCostPerDay() << "\t\t" << i->getType() << " \n";
    }
}

int Vehicle::getAge() const {
    return age;
}

void Vehicle::setAge(int age) {
    Vehicle::age = age;
}

const string &Vehicle::getRegNumber() const {
    return reg_number;
}

void Vehicle::setRegNumber(const string &regNumber) {
    reg_number = regNumber;
}

const string &Vehicle::getMake() const {
    return make;
}

void Vehicle::setMake(const string &make) {
    Vehicle::make = make;
}

const string &Vehicle::getModel() const {
    return model;
}

void Vehicle::setModel(const string &model) {
    Vehicle::model = model;
}

const string &Vehicle::getType() const {
    return type;
}

void Vehicle::setType(const string &type) {
    Vehicle::type = type;
}