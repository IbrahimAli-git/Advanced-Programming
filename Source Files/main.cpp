#include <iostream>
#include "../Header Files/Car.h"
#include "../Header Files/Vehicle.h"
#include "../Header Files/Bike.h"
#include <vector>

using namespace std;

//Registration Number     Cost Per Day	Vehicle Type
//------------------ - ------------      ---------- -
//AB12 XYZ			£13.50		Car
//CD34 LMN			£11.00		Car
//EF56 OPQ			£24.00		Bike
//GH78 RST			£19.50		Car


void mainMenu() {
    vector<Vehicle > vec;
    Vehicle vehicle;
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
                vehicle.addVehicle(vec);
                break;
            case 2:
                vehicle.removeVehicle(vec);
                break;
            case 3:
                vehicle.searchForCar(vec);
                break;
            case 4:
                vehicle.searchForBike(vec);
                break;
            case 5:
                vehicle.sortByRegistrationNumber(vec);
                break;
            case 6:
                vehicle.sortByCostPerDay(vec);
                break;
            case 9:
                break;
            default:
                cout << "Please enter number above\n";
                break;
        }
    } while (option != 9);
    vehicle.printVehicles(vec);
//  Exception and error handling
//  PUSH ALL OF YOUR CODE TO GITHUB
//  Have containers of pointers which mean you will need to create them using the new object "new Contact()"
//  List vs Vectors
//  The assignment is evaluating your knowledge of the c++ language and how well you can write code

}

int main() {
    mainMenu();
    return 0;
}