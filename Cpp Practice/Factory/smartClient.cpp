#include "vehicle_factory.hpp"
#include <iostream>
using namespace std;

int main()
{
    string vehicleType;
    cout<<"Enter vehicle type: ";
    cin>>vehicleType;

    vehicle *vehicle = VehicleFactory::getVehicle(vehicleType);
    vehicle->createVehicle();

    return 0;
}