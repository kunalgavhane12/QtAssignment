#include <iostream>
#include <string>
#include "car.hpp"
#include "bike.hpp"

using namespace std;

int main()
{
    string vehicleType;
    cout << "Enter vehicle type: ";
    cin >> vehicleType;
    vehicle *vehicle;
    if(vehicleType == "car")
    {
        vehicle = new car();
    }
    else if(vehicleType == "bike")
    {
        vehicle = new Bike();
    }
    else
    {
        cout<<"Invaild input"<<endl;
    }
    vehicle->createVehicle();

    return 0;
}