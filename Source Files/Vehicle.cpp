//
// Created by Ibrahim on 28/10/2022.
//
#include "../Header Files/Vehicle.h"
#include "../Header Files/Car.h"
#include "../Header Files/Bike.h"
#include <iostream>
#include <vector>
#include "algorithm"
#include "string"
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
    cout << "Would you like to enter a car or bike: \n";

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

//https://iq.opengenus.org/ways-to-remove-elements-from-vector-cpp/
void Vehicle::removeVehicle(vector<Vehicle> &vec) {
    cout << "Please enter registration number: ";
    string regNumber;
    cin >> regNumber;
    int index;

    for (int i = 0; i < vec.size(); i++){
        if (vec[i].getRegNumber() == regNumber){
            index = i;
        }
    }

    vec.erase(vec.begin() + index);
    cout << "Vehicle deleted\n";
    cout << "\n";
}


void Vehicle::searchForBike(vector<Vehicle> &vec) {

}

void Vehicle::searchForCar(vector<Vehicle> &vec) {
    int option = 0;
    do {
        cout << "Search for a car by :\n";
        cout << "--------------------\n";
        cout << "1) Registration number\n";
        cout << "2) Number of seats\n";
        cout << "3) Number of doors\n";
        cout << "9) Return to main menu\n";
        cout << "Please choose an option:\n";
        cin >> option;
        switch (option) {
            case 1:
                searchByRegNumber(vec);
                break;
            case 2:
                searchByNumberOfSeats(vec);
                break;
            case 3:
                searchByNumberOfDoors(vec);
                break;
            default:
                cout << "Please enter option above\n";
                break;
        }

    } while (option != 9);
}

void Vehicle::searchByRegNumber(vector<Vehicle> &vec) {
    cout << "Please enter registration number: \n";
    string reg_number;
    cin >> reg_number;
    cout << "\n";
    cout << "List of vehicles matching that search: \n";
    cout << "Registration Number  Cost Per Day	Vehicle Type\n";
    cout << "------------------ - ------------      ----------\n";
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i].getRegNumber() == reg_number) {
            cout << vec[i].getRegNumber() << "\t\t\t\t\t" << vec[i].getType() << " \n";
        }
    }
    cout << "\n";
}

void Vehicle::searchByNumberOfSeats(vector<Vehicle> &vec) {
    cout << "Please enter number of seats: \n";
    int seats;
    cin >> seats;
    cout << "List of cars matching that search: \n";
    cout << "Registration Number  Cost Per Day	Vehicle Type\n";
    cout << "------------------ - ------------      ----------\n";
    for (auto &item: vec) {
        if (item.getType() == "car") {
            Car c(item);
            if (c.getNumberOfSeats() == seats) {
                cout << c.getRegNumber() << "\t\t\t\t\t" << c.getType() << " \n";
            }
        }
    }
    cout << "\n";
}

void Vehicle::searchByNumberOfDoors(vector<Vehicle> &vec) {
    cout << "Please enter number of doors: \n";
    int doors;
    cin >> doors;
    cout << "List of cars matching that search: \n";
    cout << "Registration Number  Cost Per Day	Vehicle Type\n";
    cout << "------------------ - ------------      ----------\n";
    for (auto &item: vec) {
        if (item.getType() == "car") {
            Car c(item);
            if (c.getNumberOfDoors() == doors) {
                cout << c.getRegNumber() << "\t\t\t\t\t" << c.getType() << " \n";
            }
        }
    }
    cout << "\n";
}

void Vehicle::sortByCostPerDay(vector<Vehicle> &vec) {
    // in pence
    // Any costs per day less than £10 will be capped at £10
    for (int i = 0; i < vec.size()-1; i++) {
        for (int j = 0; j < vec.size()-1-i; j++) {
            if(vec[j].costPerDay() > vec[j+1].costPerDay()){
                swap(vec[j], vec[j+1]);
            }
        }
    }
}

// print out the vehicles
void Vehicle::sortByRegistrationNumber(vector<Vehicle> &vec){
    for (int i = 0; i < vec.size()-1; i++) {
        for (int j = 0; j < vec.size()-1-i; j++) {
            if(vec[j].getRegNumber() > vec[j+1].getRegNumber()){
                swap(vec[j], vec[j+1]);
            }
        }
    }
}

void Vehicle::printVehicles(vector<Vehicle> &vec) {
    cout << "Registration Number  Cost Per Day	Vehicle Type\n";
    cout << "------------------ - ------------      ----------\n";
    for (int i = 0; i < vec.size(); i++) {
        // Use typeid instead of having a type variable but make sure it is dereferenced
        cout << vec[i].getRegNumber() << "\t\t\t" << vec[i].costPerDay() << "\t\t" << vec[i].getType() << " \n";
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

int Vehicle::costPerDay() {
    return 0;
}


