#include <iostream>
#include "../Header Files/Car.h"
#include <vector>
using namespace std;

void deleteVehicles(vector<Vehicle *> &vec);

// Displays the menu
// https://learn.microsoft.com/en-us/cpp/cpp/errors-and-exception-handling-modern-cpp?view=msvc-170
// https://learn.microsoft.com/en-us/cpp/cpp/errors-and-exception-handling-modern-cpp?view=msvc-170#exceptions_versus_assertions
// https://www.w3schools.com/cpp/cpp_files.asp
void menu() {
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
//  Exception and error handling
// use operator overloading when comparing two objects in the two sorting methods
//  The assignment is evaluating your knowledge of the c++ language and how well you can write code
// Make sure it works on visual studio
// Make methods static where applicable e.g, vehicle class
// The program first loads a list of vehicles and displays them
// use typeid in if statements in loops in bike and car

// Method for deallocating object memory
void deleteVehicles(vector<Vehicle *> &vec) {
    for (auto &i: vec)
        delete i;
}

int main() {
    menu();
    return 0;
}