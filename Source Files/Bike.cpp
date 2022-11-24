#include <iostream>
#include "../Header Files/Bike.h"

using namespace std;

Bike::Bike(Vehicle vehicle) {

}
Bike::Bike() {
    this->number_of_wheels = 0;
    this->engine_size = 0;
}

Bike::Bike(int engineSize, int numberOfWheels) : engine_size(engineSize), number_of_wheels(numberOfWheels) {

}

Bike::Bike(Vehicle *vehicle) {

}

Bike::~Bike() {

}

Bike* Bike::createBike() {
    cout << "Please enter age, registration number, make and model: \n";
    cin >> age >> reg_number >> make >> model;
    cout << "Please enter engine size and number of wheels: \n"; // number of wheels can only be two or three
    cin >> engine_size >> number_of_wheels;
    Bike* b = new Bike(engine_size, number_of_wheels);
    b->setAge(age);
    b->setRegNumber(reg_number);
    b->setMake(make);
    b->setModel(model);
    b->setType("bike");
    return b;
}



void Bike::searchForBike(vector<Vehicle*> &vec) {
    int option = 0;
    do {
        cout << "Search for a bike by :\n";
        cout << "--------------------\n";
        cout << "1) Registration number\n";
        cout << "2) Max engine size\n";
        cout << "3) Two or Three-wheeler\n";
        cout << "9) Return to main menu\n";
        cout << "Please choose an option:\n";
        cin >> option;
        switch (option) {
            case 1:
                searchByRegNumber(vec);
                break;
            case 2:
                searchByEngineSize(vec);
                break;
            case 3:
                searchByTwoOrThreeWheeler(vec);
                break;
            default:
                cout << "Please enter option above\n";
                break;
        }

    } while (option != 9);
}

void Bike::searchByRegNumber(vector<Vehicle*> &vec) {
    cout << "Please enter registration number: \n";
    string reg_number;
    cin >> reg_number;
    cout << "\n";
    cout << "List of bikes matching that search: \n";
    cout << "Registration Number  Cost Per Day	Vehicle Type\n";
    cout << "------------------ - ------------      ----------\n";
    for (auto & i : vec) {
        if (i->getRegNumber() == reg_number && i->getType() == "bike") {
            cout << i->getRegNumber() << "\t\t\t\t\t" << i->getType() << " \n";
        }
    }
    cout << "\n";
}

void Bike::searchByEngineSize(vector<Vehicle*> &vec) {
    cout << "Please enter engine size\n";
    int engine_size = 0;
    cin >> engine_size;
    cout << "List of bikes matching that search: \n";
    cout << "Registration Number  Cost Per Day	Vehicle Type\n";
    cout << "------------------ - ------------      ----------\n";
    for (auto &item: vec) {
        if (item->getType() == "bike") {
            Bike* bike = dynamic_cast<Bike*>(item);
            if (bike->getEngineSize() == engine_size) {
                cout << bike->getRegNumber() << "\t\t\t\t\t" << bike->getType() << " \n";
            }
        }
    }
    cout << "\n";
}

void Bike::searchByTwoOrThreeWheeler(vector<Vehicle*> &vector) {
    cout << "Would you like to search by two or three wheeler: \n";
    int no_of_wheels;
    cin >> no_of_wheels;
    for (auto &item: vector){
        if (item->getType() == "bike") {
            Bike* bike = dynamic_cast<Bike*>(item);
            if (bike->getNumberOfWheels() == no_of_wheels) {
                cout << bike->getRegNumber() << "\t\t\t\t\t" << bike->getType() << " \n";
            }
        }
    }


}

int Bike::getCostPerDay() {
    int costPerDay = (1500 + getEngineSize());
    return costPerDay;
}