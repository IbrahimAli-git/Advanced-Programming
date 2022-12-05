#include "../Header Files/Vehicle.h"
#include "../Header Files/Car.h"
#include "../Header Files/Bike.h"
#include <iostream>
#include <utility>
#include <vector>
#include "algorithm"
#include "string"
using namespace std;


// Default Constructor
Vehicle::Vehicle() {
    this->age = 0;
    this->make = "";
    this->model = "";
    this->reg_number = "";
}

// Destructor for deallocating memory
Vehicle::~Vehicle() {

}

// For adding a vehicle, car or bike, to the container
void Vehicle::addVehicle(vector<Vehicle *> &vec) {
    cout << "Would you like to enter a car or bike: \n";
    string userInput;
    cin >> userInput;
    if (userInput == "car") {
        Car *c = new Car();
        c = c->createCar();
        vec.push_back(c);
    } else {
        Bike *b = new Bike();
        b = b->createBike();
        vec.push_back(b);
    }
    cout << "\n";
}

// https://iq.opengenus.org/ways-to-remove-elements-from-vector-cpp/
// For removing a vehicle by registration number
void Vehicle::removeVehicle(vector<Vehicle *> &vec) {
    cout << "Please enter registration number: \n";
    string regNumber;
    cin >> regNumber;
    int index;

    for (int i = 0; i < vec.size(); i++) {
        if (vec[i]->getRegNumber() == regNumber) {
            index = i;
        }
    }

    vec.erase(vec.begin() + index);
    delete vec[index];

    // if vehicle was deleted than print out this
    cout << "Vehicle deleted\n";
    cout << "\n";
}

// For searching for a specific bike
void Vehicle::searchForBike(vector<Vehicle *> &vec) {
    Bike::searchForBike(vec);
}

// For searching for a specific car
void Vehicle::searchForCar(vector<Vehicle *> &vec) {
    Car::searchForCar(vec);
}

// For sorting the vehicles by cost per day
void Vehicle::sortByCostPerDay(vector<Vehicle *> &vec) {
    // in pence
    // Any costs per day less than £10 will be capped at £10
    for (int i = 0; i < vec.size() - 1; i++) {
        for (int j = 0; j < vec.size() - 1 - i; j++) {
            if (vec[j]->getCostPerDay() > vec[j + 1]->getCostPerDay()) {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

// For sorting the vehicles by registration number
void Vehicle::sortByRegistrationNumber(vector<Vehicle *> &vec) {
    for (int i = 0; i < vec.size() - 1; i++) {
        for (int j = 0; j < vec.size() - 1 - i; j++) {
            if (vec[j]->getRegNumber() > vec[j + 1]->getRegNumber()) {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

// This method returns the cost per day and is overridden in subclasses
int Vehicle::getCostPerDay() {
    return 0;
}


/*ostream &operator<<(ostream &os, const Vehicle& veh) {
    os << veh.getRegNumber() << "\t\t\t" << veh.cost_per_day << "\t" << typeid(veh).name() << " \n";
    return os;
}*/
