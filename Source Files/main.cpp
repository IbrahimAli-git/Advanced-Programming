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

//PUSH ALL OF YOUR CODE TO GITHUB

void mainMenu() {
    vector<Vehicle> vector;
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
                vehicle.addVehicle(vector);
                break;
            case 2:
                vehicle.removeVehicle(vector);
                break;
            case 3:
                vehicle.searchForCar();
                break;
            case 4:
                vehicle.searchForBike();
                break;
            case 5:
                vehicle.sortVehiclesByRegNumber();
                break;
            case 6:
                vehicle.sortByCostPerDay(vector);
                break;
            case 9:
                break;
            default:
                cout << "Please enter number above\n";
                break;
        }
    } while (option != 9);
    vehicle.printVehicles(vector);
//    delete(vehicle);
//    delete car and bike objects
//    Exception and error handling
}

int main() {
    mainMenu();
    return 0;
}