#pragma once
#include "Vehicle.h"

class Bike : public Vehicle {

private:
    int engine_size, number_of_wheels;

public:
    Bike();
    Bike(int engineSize, int numberOfWheels);
    int costPerDay() override;
    ~Bike();
    int getEngineSize() const;
    void setEngineSize(int engineSize);
    int getNumberOfWheels() const;
    void setNumberOfWheels(int numberOfWheels);
    Bike createBike();
};