#pragma once
#include <string>
#include <list>
#include <vector>
using namespace std;

class Vehicle {

private:
protected:
    int age;
    string reg_number, make, model, type;
public:
    Vehicle();
    ~Vehicle();
    void addVehicle(vector<Vehicle> &vec);
    void removeVehicle(vector<Vehicle> &vec);
    void searchForCar(vector<Vehicle> &vec);
    void searchForBike(vector<Vehicle> &vec);
    void searchByRegNumber(vector<Vehicle> &vec);
    void searchByNumberOfSeats(vector<Vehicle> &vec);
    void searchByNumberOfDoors(vector<Vehicle> &vec);
    void sortByCostPerDay(vector<Vehicle> &vec);
    void sortByRegistrationNumber(vector<Vehicle> &vec);
    void printVehicles(vector<Vehicle> &vec);
//    bool comparator(Vehicle &lhs, Vehicle &rhs);
    virtual int costPerDay();
    virtual int getAge() const;
    virtual void setAge(int age);
    virtual const string &getRegNumber() const;
    virtual void setRegNumber(const string &regNumber);
    virtual const string &getMake() const;
    virtual void setMake(const string &make);
    virtual const string &getModel() const;
    virtual void setModel(const string &model);
    const string &getType() const;
    void setType(const string &type);
};
