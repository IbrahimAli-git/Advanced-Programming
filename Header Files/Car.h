#pragma once
#include "../Header Files/Vehicle.h"
#include "../Header Files/Car.h"

class Car : public Vehicle {

private:
    int number_of_doors, number_of_seats;

public:
    Car();

    Car(Vehicle *vehicle);

    Car(int number_of_doors, int number_of_seats);

    ~Car();

    Car *createCar();

    int getCostPerDay() override;

    inline int getNumberOfDoors() const;

    inline void setNumberOfDoors(int numberOfDoors);

    inline int getNumberOfSeats() const;

    inline void setNumberOfSeats(int numberOfSeats);

    static void searchForCar(vector<Vehicle *> &vec);

    static void searchByRegNumber(vector<Vehicle *> &vec);

    static void searchByNumberOfSeats(vector<Vehicle *> &vec);

    static void searchByNumberOfDoors(vector<Vehicle *> &vec);
};

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