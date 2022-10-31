//
// Created by Ibrahim on 28/10/2022.
//
#include "../Header Files/Vehicle.h"
#include "../Header Files/Car.h"
#include "../Header Files/Bike.h"
#include <iostream>
#include <vector>

using namespace std;


Vehicle::Vehicle() {
    this->age = 0;
    this->make = "";
    this->model = "";
    this->reg_number = "";
}

Vehicle::~Vehicle() {

}

void Vehicle::addVehicle(vector<Vehicle> &vec) {
    cout << "Would you like to enter a car or bike: ";
    string userInput;
    cin >> userInput;
    if (userInput == "car") {
        Car c;
        c = c.createCar();
        vec.push_back(c);
    } else {
        Bike b;
        b = b.createBike();
        vec.push_back(b);
    }
    cout << "\n";
}

void Vehicle::removeVehicle(vector<Vehicle> &vec) {
    cout << "Please enter registration number: ";
    string regNumber;
    cin >> regNumber;
    int index;

    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i].getRegNumber() == regNumber){
            index = i;
        }
    }
    vec.erase(vec.begin()+index);
    cout << "Vehicle deleted\n";
    cout << "\n";
}

void Vehicle::sortVehiclesByRegNumber() {

}

void Vehicle::searchForBike() {

}

void Vehicle::sortByNumberOfDoors() {

}

void Vehicle::sortByNumberOfSeats() {

}

void sortByNumberOfSeats() {
    cout << "Enter number of seats: \n";
    int numberOfSeat = 0;
    cin >> numberOfSeat;
}

void sortByNumberOfDoors() {
    cout << "Enter number of doors: \n";
    int numberOfDoors = 0;
    cin >> numberOfDoors;
}

void Vehicle::sortByCostPerDay(vector<Vehicle> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size(); j++) {

        }
    }
}

void Vehicle::printVehicles(vector<Vehicle> &vec) {
    cout << "Registration Number  Cost Per Day	Vehicle Type\n";
    cout << "------------------ - ------------      ----------\n";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i].getRegNumber() << "\t\t\t\t\t" << vec[i].getType() << " \n";
    }
}

void Vehicle::searchForCar() {
    cout << "Search for a car by :\n";
    cout << "--------------------\n";
    cout << "1) Registration number\n";
    cout << "2) Number of seats\n";
    cout << "3) Number of doors\n";
    cout << "9) Return to main menu\n";

    cout << "Please choose an option:\n";
    int option = 0;
    cin >> option;

    switch (option) {
        case 1:
            sortVehiclesByRegNumber();
            break;
        case 2:
            sortByNumberOfSeats();
            break;
        case 3:
            sortByNumberOfDoors();
            break;
        case 9:
            break;
        default:
            cout << "Please enter number above";
            break;
    }

    cout << "List of cars matching that search:\n";

    cout << "Enter number to choose vehicle or 0 to return to main menu: \n";
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
