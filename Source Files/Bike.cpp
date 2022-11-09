//
// Created by Ibrahim on 28/10/2022.
//
#include <iostream>
#include <cmath>
#include "../Header Files/Bike.h"
using namespace std;

Bike::Bike() {
    this->number_of_wheels = 0;
    this->engine_size = 0;
}

Bike::Bike(int engineSize, int numberOfWheels) : engine_size(engineSize), number_of_wheels(numberOfWheels) {

}

Bike::~Bike() {

}

Bike Bike::createBike() {
    cout << "Please enter age, registration number, make and model: ";
    cin >> age >> reg_number >> make >> model;
    cout << "Please enter number of wheels and engine size: ";
    cin >> number_of_wheels >> engine_size;
    Bike b(engine_size, number_of_wheels);
    b.setAge(age);
    b.setRegNumber(reg_number);
    b.setMake(make);
    b.setModel(model);
    b.setType("bike");
    return b;
}

int Bike::costPerDay(){
    int costPerDay = (1500 + engine_size);
    return costPerDay;
}


int Bike::getEngineSize() const {
    return engine_size;
}

void Bike::setEngineSize(int engineSize) {
    engine_size = engineSize;
}

int Bike::getNumberOfWheels() const {
    return number_of_wheels;
}

void Bike::setNumberOfWheels(int numberOfWheels) {
    number_of_wheels = numberOfWheels;
}


