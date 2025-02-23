#include "Car.h"

Car::Car():
make("Ford"),
totalMilesOnVehicle(13000),
sellingPrice(10000.0f),
fuelType(0)
{
    std::cout << "Car constuctor called" << std::endl;
}

Car::~Car()
{
    std::cout << "Car class destructor called" << std::endl;
}

float Car::calculateTrueSellValue(std::string carMake, float carSellingPrice, int totalMiles)
{
    float trueSellValue = 0.0f;

    std::cout << "Calculating True Sell Value for " << carMake << std::endl;
    trueSellValue = (carSellingPrice - (.1f * (static_cast<float>(totalMiles))));
    return std::abs(trueSellValue);
}

void Car::calculateMilesUntilOilChange(int fuelTypeCar, int totalMiles)
{
    int milesUntilOilChange = 0;

    if (!(milesUntilOilChange = totalMiles % 5000))
    {
        std::cout << fuelTypeCar << " car needs doesn't need oil change" << std::endl;
        return;
    }

    std::cout << "Car needs oil change in " << milesUntilOilChange << " miles"<< std::endl;                                  
}

bool Car::predictRaceWinProbability(std::string carMake, int maxSpeedCar)
{
    int competitorMaxSpeed = 200;

    if (maxSpeedCar > competitorMaxSpeed)
    {
        std::cout << "Your " << carMake << " likely win in a race" << std::endl;
        return true;
    }

    std::cout << "Your " << carMake << " will most likely lose in a race" << std::endl;
    return false;
}

void Car::printCalculateTrueSellValue()
{
    std::cout << "Car calculateTrueSellValue(): " << this->calculateTrueSellValue("Ford", 6000.75f, 100000) << std::endl;
}

void Car::printPredictRaceWinProbability()
{
    std::cout << "Car calculateRaceWinProbability(): " << this->calculateTrueSellValue("Ford", 250) << std::endl;
}

Car::Vehicle::Vehicle():
maxSpeed(160),
turboCharged(false),
vin("1BBHHK7772122340"),
engineDisplacement(5.7f)
{
    std::cout << "Vehicle constructor called" << std::endl;
}

Car::Vehicle::~Vehicle()
{
    std::cout << "Vehicle Destructor called" << std::endl;
}

void Car::Vehicle::renovateVehicle(std::string vehicleVin, int maxSpeedVehicle, bool isTurboCharged)
{
    if((vehicleVin.size() >= 10) && (vehicleVin[9] < 'J') && (maxSpeedVehicle < 155) && !isTurboCharged)
    {
        std::cout << "Renovate vehicle" << std::endl;
        return;
    }

    std::cout << "Don't renovate vehicle" << std::endl;
}

float Car::Vehicle::calculateHpToTheWheel(float engDisplacement, bool isTurboCharged, int maxSpeedVehicle)
{
    if(isTurboCharged)
    {
        return((engDisplacement * 100.0f) + 100.0f + maxSpeedVehicle);
    }

    return ((engDisplacement * 100.0f) + maxSpeedVehicle);
}

void Car::Vehicle::resetEngineControlModule(std::string vehicleVin, bool vehicleIsImmobolized)
{
    if((vehicleVin.size() >= 10) && (vehicleVin[9] > 'J') && vehicleIsImmobolized)
    {
        std::cout << "Reset module exists and starting ECM reset" << std::endl;
        return;
    }

    std::cout << "Reset module does not exist" << std::endl;
}

void Car::Vehicle::printCalculateHpToTheWheel()
{
    std::cout << "Car calculateHpToTheWheel(): " << this->calculateHpToTheWheel(4.1f) << std::endl;
}

struct CarWrapper
{
    CarWrapper(Car* ptr): car(ptr){}
    ~CarWrapper()
    {
        delete car;
    }

    Car* car = nullptr;
};
