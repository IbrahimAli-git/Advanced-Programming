//
// Created by Ibrahim on 28/10/2022.
//

#pragma once
#include "../Header Files/Vehicle.h"
#include "../Header Files/Car.h"
using namespace std;

class Car : public Vehicle {

private:
    int number_of_doors, number_of_seats;

public:
    Car();
    Car(int number_of_doors, int number_of_seats);
    ~Car();
    Car createCar();
    int costPerDay() override;
    int getNumberOfDoors() const;
    void setNumberOfDoors(int numberOfDoors);
    int getNumberOfSeats() const;
    void setNumberOfSeats(int numberOfSeats);

    Car(Vehicle& vehicle);
};