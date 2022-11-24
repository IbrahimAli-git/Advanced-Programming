#include <iostream>
#include "../Header Files/Car.h"

using namespace std;


Car::Car() {
    this->number_of_doors = 0;
    this->number_of_seats = 0;
}

Car::Car(int number_of_doors, int number_of_seats) : number_of_doors(number_of_doors),
                                                     number_of_seats(number_of_seats) {
}

Car::Car(Vehicle &vehicle) {

}

Car::Car(Vehicle *vehicle) {

}

Car::~Car() {

}

Car* Car::createCar() {
    Car* c = new Car();
    cout << "Please enter age, registration number, make and model: \n";
    cin >> age >> reg_number >> make >> model;
    cout << "Please enter number of doors and number of seats: \n";
    cin >> number_of_doors >> number_of_seats;
    c->setAge(age);
    c->setRegNumber(reg_number);
    c->setMake(make);
    c->setModel(model);
    c->setType("car");
    c->setNumberOfDoors(number_of_doors);
    c->setNumberOfSeats(number_of_seats);
    c->setCostPerDay(getCostPerDay());
    return c;
}

void Car::searchForCar(vector<Vehicle *> &vec) {
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

void Car::searchByRegNumber(vector<Vehicle*> &vec) {
    cout << "Please enter registration number: \n";
    string reg_number;
    cin >> reg_number;
    cout << "\n";
    cout << "List of cars matching that search: \n";
    cout << "Registration Number  Cost Per Day	Vehicle Type\n";
    cout << "------------------ - ------------      ----------\n";
    for (auto & i : vec) {
        if (i->getRegNumber() == reg_number) {
            cout << i->getRegNumber() << "\t\t\t\t\t" << i->getType() << " \n";
        }
    }
    cout << "\n";
}

void Car::searchByNumberOfSeats(vector<Vehicle*> &vec) {
    cout << "Please enter number of seats: \n";
    int seats;
    cin >> seats;
    cout << "List of cars matching that search: \n";
    cout << "Registration Number  Cost Per Day	Vehicle Type\n";
    cout << "------------------ - ------------      ----------\n";
    for (auto &item: vec) {
        if (item->getType() == "car") {
            Car* c = dynamic_cast<Car*>(item);
            if (c->getNumberOfSeats() == seats) {
                cout << c->getRegNumber() << "\t\t\t\t\t" << c->getType() << " \n";
            }
        }
    }
    cout << "\n";
}

void Car::searchByNumberOfDoors(vector<Vehicle*> &vec) {
    cout << "Please enter number of doors: \n";
    int doors;
    cin >> doors;
    cout << "List of cars matching that search: \n";
    cout << "Registration Number  Cost Per Day	Vehicle Type\n";
    cout << "------------------ - ------------      ----------\n";
    for (auto &item: vec) {
        if (item->getType() == "car") {
            Car* c = dynamic_cast<Car*>(item);
            if (c->getNumberOfDoors() == doors) {
                cout << c->getRegNumber() << "\t\t\t\t\t" << c->getType() << " \n";
            }
        }
    }
    cout << "\n";
}

int Car::getCostPerDay() {
    int costPerDay = 2500 - (getAge() * 150) - (getNumberOfDoors() * 200);
    return costPerDay;
}

