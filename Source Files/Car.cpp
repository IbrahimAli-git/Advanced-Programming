//
// Created by Ibrahim on 28/10/2022.
//
#include <iostream>
#include "../Header Files/Car.h"
using namespace std;


Car::Car() {
    this->number_of_doors = 0;
    this->number_of_seats = 0;
}

Car::Car(int number_of_doors, int number_of_seats) : number_of_doors(number_of_doors), number_of_seats(number_of_seats) {

}

Car::~Car() {

}

int Car::getNumberOfDoors() const {
    return number_of_doors;
}

void Car::setNumberOfDoors(int numberOfDoors) {
    number_of_doors = numberOfDoors;
}

int Car::getNumberOfSeats() const {
    return number_of_seats;
}

void Car::setNumberOfSeats(int numberOfSeats) {
    number_of_seats = numberOfSeats;
}

Car Car::createCar() {
    cout << "Please enter age, registration number, make and model: ";
    cin >> age >> reg_number >> make >> model;
    cout << "Please enter number of doors and number of seats: ";
    cin >> number_of_doors >> number_of_seats;
    Car c(number_of_doors, number_of_seats);
    c.setAge(age); c.setRegNumber(reg_number); c.setMake(make); c.setModel(model); c.setType("car");
    return c;
}






