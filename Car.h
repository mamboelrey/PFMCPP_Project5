#pragma once
struct Car
{
    // 5 member variables
    std::string make;
    int totalMilesOnVehicle;
    bool hasTwoDoors = false;
    float sellingPrice;
    int fuelType;

    // Constructor
    Car();
    // Destructor
    ~Car();

    // 3 Member Functions
    float calculateTrueSellValue(std::string carMake, float carSellingPrice, int totalMiles = 10000);
    void calculateMilesUntilOilChange(int fuelTypeCar = 0, int totalMiles = 10000);
    bool predictRaceWinProbability(std::string carMake, int maxSpeedCar = 150);
    void printCalculateTrueSellValue();
    void printPredictRaceWinProbability();

    struct Vehicle
    {
        // 5 member variable
        int numberOfTires = 4;
        int maxSpeed;
        bool turboCharged;
        std::string vin;
        float engineDisplacement;

        // 3 member functions
        void renovateVehicle(std::string vehicleVin, int maxSpeedVehicle = 150, bool isTurboCharged = false);
        float calculateHpToTheWheel(float engDisplacement, bool isTurboCharged = true, int maxSpeedVehicle = 200);
        void resetEngineControlModule(std::string vehicleVin, bool vehicleIsImmobolized = true);
        void printCalculateHpToTheWheel();
        // Constructor
        Vehicle();
        //Destructor
        ~Vehicle();

        JUCE_LEAK_DETECTOR(Vehicle)
    };
    JUCE_LEAK_DETECTOR(Car)
};
