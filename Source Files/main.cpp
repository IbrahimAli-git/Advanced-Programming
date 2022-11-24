#include <iostream>
#include "../Header Files/Car.h"
#include "../Header Files/Vehicle.h"
#include "../Header Files/Bike.h"
#include <vector>

using namespace std;

void deleteVehicles(vector<Vehicle *> &vec);

//Registration Number     Cost Per Day	Vehicle Type
//------------------ - ------------      ---------- -
//AB12 XYZ			£13.50		Car
//CD34 LMN			£11.00		Car
//EF56 OPQ			£24.00		Bike
//GH78 RST			£19.50		Car


void mainMenu() {
    vector<Vehicle*> vec;
    int option = 0;

    do {
        cout << "Vehicle Rental System\n";
        cout << "---------------------\n";

        cout << "1) Add vehicle\n";
        cout << "2) Remove vehicle\n";
        cout << "3) Search for car\n";
        cout << "4) Search for bike\n";
        cout << "5) Sort vehicles by registration number\n";
        cout << "6) Sort by cost per day\n";
        cout << "9) Exit\n";
        cin >> option;
        switch (option) {
            case 1:
                Vehicle::addVehicle(vec);
                break;
            case 2:
                Vehicle::removeVehicle(vec);
                break;
            case 3:
                Vehicle::searchForCar(vec);
                break;
            case 4:
                Vehicle::searchForBike(vec);
                break;
            case 5:
                Vehicle::sortByRegistrationNumber(vec);
                break;
            case 6:
                Vehicle::sortByCostPerDay(vec);
                break;
            case 9:
                break;
            default:
                cout << "Please enter number above\n";
                break;
        }
    } while (option != 9);
    Vehicle::printVehicles(vec);
    deleteVehicles(vec);
}
// deleteVehicles(vec, vehicle);
//  Exception and error handling
//  Have containers of pointers which mean you will need to create them using the new object "new Contact()"
// optimize code using inline functions, pass by ref, pointer instead of objects etc
//  List vs Vectors
//  The assignment is evaluating your knowledge of the c++ language and how well you can write code
// How to override parent class method
// Make sure it works on visual studio
// For each loop instead of normal for where applicable
// Make methods static where applicable e.g, vehicle class


void deleteVehicles(vector<Vehicle *> &vec) {
    for (auto &i: vec)
        delete i;
}

int main() {
    mainMenu();
    return 0;
}