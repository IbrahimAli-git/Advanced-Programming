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
    void searchForCar();
    void searchForBike();
    void sortVehiclesByRegNumber();
    void sortByCostPerDay(vector<Vehicle> &vec);
    void printVehicles(vector<Vehicle> &vec);
    void sortByNumberOfDoors();
    void sortByNumberOfSeats();
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
