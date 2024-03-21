#include "vehicle_factory.hpp"

vehicle *VehicleFactory::getVehicle(string vehicleType){

    vehicle *vehicle;
    if(vehicleType == "car")
    {
        vehicle = new car();
    }
    else if(vehicleType == "bike")
    {
        vehicle = new Bike();
    }
    
    return vehicle;
}