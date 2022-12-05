#include "../Header Files/Car.h"

// Constructors for initialising different types of car objects
Car::Car() {
    this->number_of_doors = 0;
    this->number_of_seats = 0;
}

Car::Car(int number_of_doors, int number_of_seats) : number_of_doors(number_of_doors),
                                                     number_of_seats(number_of_seats) {
}

Car::Car(Vehicle *vehicle) {

}

// Destructor for deallocating memory
Car::~Car() {

}

// Creates a car object and returns a pointer to it
Car *Car::createCar() {
    Car *c = new Car();
    cout << "Please enter age: \n"; age = Vehicle::userInput(age);
    cout << "Please enter registration number: \n"; cin >> reg_number;
    cout << "Please enter make: \n"; cin >> make;
    cout << "Please enter model: \n"; cin >> model;
    cout << "Please enter number of doors \n"; number_of_doors = Vehicle::userInput(number_of_doors);
    cout << "Please enter number of seats: \n"; number_of_seats = Vehicle::userInput(number_of_seats);
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

// Menu for searching for a car
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
        option = Vehicle::userInput(option);
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

// Searches for car by registration number
void Car::searchByRegNumber(vector<Vehicle *> &vec) {
    cout << "Please enter registration number: \n";
    string reg_number;
    cin >> reg_number;
    cout << "\n";
    cout << "   List of cars matching that search: \n";
    cout << "   Registration Number  Cost Per Day  Make  Model\n";
    cout << "   ------------------ - ------------  ----  -----\n";

    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i]->getType() == "car"){
            if (vec[i]->getRegNumber() == reg_number){
                cout << i << "  " << vec[i]->getRegNumber() << "\t\t\t" << vec[i]->getCostPerDay() << "\t\t" << vec[i]->getMake()
                     << " "
                     << vec[i]->getModel() << "\n";
            }
        }
    }
    cout << "Enter number to choose vehicle or 0 to return to main menu: \n";
    int option;
    cin >> option;
    if (option == 0) return;
    Vehicle* v = vec[--option];
    cout << "\n";
}

// Searches for cars by number of seats
void Car::searchByNumberOfSeats(vector<Vehicle *> &vec) {
    cout << "Please enter number of seats: \n";
    int seats = 0;
    seats = Vehicle::userInput(seats);
    cout << "   List of cars matching that search: \n";
    cout << "   Registration Number  Cost Per Day	Vehicle Type\n";
    cout << "   ------------------ - ------------      ----------\n";
    for (auto &item: vec) {
        int index = 1;
        if (item->getType() == "car") {
            Car *c = dynamic_cast<Car *>(item);
            if (c->getNumberOfSeats() == seats) {
                cout << index << "  " << c->getRegNumber() << "\t\t\t\t\t" << typeid(c).name() << " \n";
            }
        }
        ++index;
    }
    cout << "\n";
}

// Searches for cars by number of doors
void Car::searchByNumberOfDoors(vector<Vehicle *> &vec) {
    cout << "Please enter number of doors: \n";
    int doors = 0;
    doors = Vehicle::userInput(doors);
    cout << "   List of cars matching that search: \n";
    cout << "   Registration Number  Cost Per Day	Vehicle Type\n";
    cout << "   ------------------ - ------------      ----------\n";
    for (auto &item: vec) {
        int index = 1;
        if (item->getType() == "car") {
            Car *c = dynamic_cast<Car *>(item);
            if (c->getNumberOfDoors() == doors) {
                cout << index << "  " << c->getRegNumber() << "\t\t\t\t\t" << typeid(c).name() << " \n";
            }
        }
        ++index;
    }
    cout << "\n";
}

// Returns the cost per day for each car
int Car::getCostPerDay() {
    int costPerDay = 2500 - (getAge() * 150) - (getNumberOfDoors() * 200);
    return costPerDay;
}