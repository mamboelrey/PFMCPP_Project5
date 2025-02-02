/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
         Don't forget the '#pragma once'
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
         
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
         tip: you cannot forward-declare nested types!  
         The file that a nested type is defined in MUST be included wherever that nested type is written.
 */






/*
 UDT 1:
 */
#include <iostream>
#include <array>
#include <cmath>
#include "LeakedObjectDetector.h"

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

/*
 UDT 2:
 */
struct SoccerTeam
{
    int numberOfPlayers = 11;
    float stoppageTime;
    int numberOfGoalsCurrentGame;
    std::string starPlayer;

    void transferPlayerToTeam(std::string transferToTeam, std::string transferFromTeam);
    double calculateWinProbability(double extraTime, int numberOfGoalsGame);
    int calculateTotalSeasonGoals(int numberOfGoalsGame, int numberOfGoalsUntilNow);

    void printCalculateWinProbability();
    void printCalculateTotalSeasonGoals();

    SoccerTeam();
    ~SoccerTeam();
    JUCE_LEAK_DETECTOR(SoccerTeam)
};

SoccerTeam::SoccerTeam():
stoppageTime(2.34f),
numberOfGoalsCurrentGame(3),
starPlayer("Neymar")
{
    std::cout << "SoccerTeam constructor called" << std::endl;
}

SoccerTeam::~SoccerTeam()
{
    std::cout << "SoccerTeam destructor called" << std::endl;
}

void SoccerTeam::transferPlayerToTeam(std::string transferToTeam, std::string transferFromTeam)
{
    std::cout << "Transferring from team " << transferFromTeam << " to team " << transferToTeam << std::endl;
}

double SoccerTeam::calculateWinProbability(double extraTime, int numberOfGoalsGame)
{
    if((extraTime > 3.0) && (numberOfGoalsGame < 2))
    {
        std::cout << "Win probability over 50%" << std::endl;
        return 0.6;
    }

    std::cout << "Win probability less than 50%" << std::endl;
    return 0.4;
}

int SoccerTeam::calculateTotalSeasonGoals(int numberOfGoalsGame, int numberOfGoalsUntilNow)
{
    return (numberOfGoalsGame + numberOfGoalsUntilNow);
}

void SoccerTeam::printCalculateWinProbability()
{
    std::cout << "SoccerTeam calculateWinProbability(): " << this->calculateWinProbability(4.56, 1) << std::endl;    
}

void SoccerTeam::printCalculateTotalSeasonGoals()
{
    std::cout << "SoccerTeam calculateTotalSeasonGoals(): " << this->calculateTotalSeasonGoals(4, 130) << std::endl;
}

struct SoccerTeamWrapper
{
    SoccerTeamWrapper(SoccerTeam* ptr): soccerTeam(ptr){}
    ~SoccerTeamWrapper()
    {
        delete soccerTeam;
    }

    SoccerTeam* soccerTeam = nullptr;
};
/*
 UDT 3:
 */
struct DogShow
{
    std::string breedName = "Pitbull";
    int weightInPounds;
    std::string furColor;
    float entranceFee;
    float totalWinnings;
    
    float calculateCostToEnterDogShow(int dogWeightInPounds = 30, std::string dogFurColor = "brown", float dogEntranceFee = 1000.54f);
    void predictWinProbabilityDogShow(std::string dogBreedName, int dogWeightInPounds, std::string dogFurColor);
    float calculateTotalEarningsDogShow(float dogTotalWinnings, float dogEntranceFee = 2000.0f); 
    void printCalculateCostToEnterDogShow();
    void printCalculateTotalEarningsDogShow();

    DogShow();
    ~DogShow();

    struct Animal
    {
        int numberOfLegs = 4;
        int theoreticalSpeed;
        std::string animalType;
        std::string countryOfShow;
        int ageOfAnimal;

        void determineAnimalShow(std::string typeOfAnimal, std::string country = "USA");
        int calculateMaxLandSpeed(int theoreticSpeed = 40);
        void determineAnimalHealth(std::string typeOfAnimal = "dog", int animalAge = 13);
        void printCalculateMaxLandSpeed();

        Animal();
        ~Animal();

        JUCE_LEAK_DETECTOR(Animal)
    };

    JUCE_LEAK_DETECTOR(DogShow)
};

DogShow::DogShow():
weightInPounds(135),
furColor("black"),
entranceFee(1500.0f),
totalWinnings(4500.0f)
{
    std::cout << "Dog constructor called" << std::endl;
}

DogShow::~DogShow()
{
    std::cout << "Dog destructor called" << std::endl;
}

float DogShow::calculateCostToEnterDogShow(int dogWeightInPounds, std::string dogFurColor, float dogEntranceFee)
{
    float totalCost = dogEntranceFee;

    if(dogWeightInPounds > 50)
    {
        totalCost += 50.45f;
    }
    else if(dogFurColor == "white")
    {
        totalCost+= 75.63f;
    }
    else
    {
        std::cout << "No additional costs" << std::endl;
    }

    return totalCost;
}

void DogShow::predictWinProbabilityDogShow(std::string dogBreedName, int dogWeightInPounds, std::string dogFurColor)
{
    float winProbability  = 0.0f;
    std::array<std::string, 5> breeds = {"Pitbull", "German Shepherd", "Lab", "Great Dane", "Mastiff"};

    for(std::size_t i = 0; i < breeds.size(); ++i)
    {
        if(dogBreedName == breeds[i])
        {
            winProbability += .4f;
            break;
        }
    }

    if(dogFurColor != "white")
    {
        winProbability += .2f;
    }

    winProbability = (winProbability + static_cast<float>(dogWeightInPounds)) / 100.0f;
    std::cout << winProbability << " chance of win probability" << std::endl;
}

float DogShow::calculateTotalEarningsDogShow(float dogTotalWinnings, float dogEntranceFee)
{
    return std::abs((dogTotalWinnings - dogEntranceFee));
}

void DogShow::printCalculateCostToEnterDogShow()
{
    std::cout << "DogShow calculateCostToEnterDogShow() " << this->calculateCostToEnterDogShow() << std::endl;
}
void DogShow::printCalculateTotalEarningsDogShow()
{
    std::cout << "DogShow calculateTotalEarningsDogShow() " << this->calculateTotalEarningsDogShow(1000.37f) << std::endl;
}

DogShow::Animal::Animal():
theoreticalSpeed(45),
animalType("dog"),
countryOfShow("USA"),
ageOfAnimal(10)
{
    std::cout << "Animal constructor called" << std::endl;
}

DogShow::Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}

void DogShow::Animal::determineAnimalShow(std::string typeOfAnimal, std::string country)
{
    if((typeOfAnimal == "dog" || typeOfAnimal == "horse") && (country == "USA"))
    {   
        std::cout << "Show exists for " << typeOfAnimal << std::endl;
        return;
    }

    std::cout << "No show exists for " << typeOfAnimal << std::endl;
}

int DogShow::Animal::calculateMaxLandSpeed(int theoreticSpeed)
{
    return (theoreticSpeed - 10);
}

void DogShow::Animal::determineAnimalHealth(std::string typeOfAnimal, int animalAge)
{
    if(animalAge > 10)
    {
        std::cout << typeOfAnimal << " health is bad" << std::endl;
        return;
    }

    std::cout << typeOfAnimal << " health is good" << std::endl;
}

void DogShow::Animal::printCalculateMaxLandSpeed()
{
    std::cout << "Animal calculateMaxLandSpeed " << this->calculateMaxLandSpeed(45) << std::endl;
}

struct DogShowWrapper
{
    DogShowWrapper(DogShow* ptr): dogShow(ptr){}
    ~DogShowWrapper()
    {
        delete dogShow;
    }

    DogShow* dogShow = nullptr;
};
/*
 new UDT 4:
 */
struct GermanShepherd
{
    DogShow danielsDog;

    void calculateGermanShepherdEarnings(float entranceFee);
    void finishObstacleCourse(int weightInPounds);
    void printDanielsDog();

    GermanShepherd();
    ~GermanShepherd();
    JUCE_LEAK_DETECTOR(GermanShepherd)
};

GermanShepherd::GermanShepherd()
{
    std::cout << "German Shepherd constructor" << std::endl;
}
GermanShepherd::~GermanShepherd()
{
    std::cout << "German Shepherd destructor" << std::endl;
}

void GermanShepherd::calculateGermanShepherdEarnings(float entranceFee)
{
    std::cout << "Total earnings " << entranceFee << std::endl; 
}

void GermanShepherd::finishObstacleCourse(int weightInPounds)
{
    if(weightInPounds < 100)
    {
        std::cout << "German Shepherd will finish" << std::endl;
        return;
    }
    
    std::cout << "German Shepherd will not finish"<< std::endl;
}

void GermanShepherd::printDanielsDog()
{
    std::cout << "GermanShepherd danielsDog()" << this->danielsDog.breedName << std::endl;
}

struct GermanShepherdWrapper
{
    GermanShepherdWrapper(GermanShepherd* ptr): germanShepherd(ptr){}
    ~GermanShepherdWrapper()
    {
        delete germanShepherd;
    }

    GermanShepherd* germanShepherd = nullptr;
};
/*
 new UDT 5:
 */

struct BayernMunich
{
    SoccerTeam germanTeam;

    void performFreeKickFormation(int numberOfPlayers);
    void celebrateGoal(std::string starPlayer);
    void printGermanTeam();
    
    BayernMunich();
    ~BayernMunich();

    JUCE_LEAK_DETECTOR(BayernMunich)
};

BayernMunich::BayernMunich()
{
    std::cout << "Bayern Munich constructor" << std::endl;
}

BayernMunich::~BayernMunich()
{
    std::cout << "Bayern Munich destructor" << std::endl;
}

void BayernMunich::performFreeKickFormation(int numberOfPlayers)
{
    if(numberOfPlayers > 9)
    {
        std::cout << "Perform golden triangle formation" << std::endl;
        return;
    }

    std::cout << "Perform regular formation" << std::endl; 
}

void BayernMunich::celebrateGoal(std::string starPlayer)
{
    std::cout << starPlayer << " celebrates a great goal!" << std::endl;
}

void BayernMunich::printGermanTeam()
{
    std::cout << "BayernMunich " << this->germanTeam.starPlayer << std::endl;
}

struct BayernMunichWrapper
{
    BayernMunichWrapper(BayernMunich* ptr): bayernMunich(ptr){}
    ~BayernMunichWrapper()
    {
        delete bayernMunich;
    }

    BayernMunich* bayernMunich = nullptr;
};
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.
 send me a DM to review your pull request when the project is ready for review.
 Wait for my code review.
 */

#include <iostream>
int main()
{
    CarWrapper myBrothersCar(new Car);
    auto brotherWinProbability = myBrothersCar.car->predictRaceWinProbability("Ford", 250);
    std::cout << "Brother win probability " << brotherWinProbability << std::endl;
    myBrothersCar.car->printPredictRaceWinProbability();
    auto brothersCarSellValue = myBrothersCar.car->calculateTrueSellValue("Ford", 6000.75f, 100000);
    std::cout << "True sell value of brothers car: $" << brothersCarSellValue << std::endl; 
    myBrothersCar.car->printCalculateTrueSellValue();
    myBrothersCar.car->calculateMilesUntilOilChange(1, 10000);

    CarWrapper mySistersCar(new Car);
    auto sisterWinProbability = mySistersCar.car->predictRaceWinProbability("Dodge");
    std::cout << "Sister win probability " << sisterWinProbability << std::endl;
    auto sistersCarSellValue = mySistersCar.car->calculateTrueSellValue("Dodge", 5000.75f, 10000);
    std::cout << "True sell value of sisters car: $" << sistersCarSellValue << std::endl; 
    mySistersCar.car->calculateMilesUntilOilChange(2, 6734);

    Car::Vehicle myBrothersVehicle;
    myBrothersVehicle.renovateVehicle("1G5JFKASJ123122", 100, false);
    auto brotherVehicleHorsepower = myBrothersVehicle.calculateHpToTheWheel(4.1f);
    std::cout << brotherVehicleHorsepower << " HP" << std::endl;
    myBrothersVehicle.printCalculateHpToTheWheel();
    myBrothersVehicle.resetEngineControlModule("G5JFKASJ1K3122", true);

    Car::Vehicle mySistersVehicle;
    mySistersVehicle.renovateVehicle("1F34JFKASJ123122", 200, true);
    auto sisterVehicleHorsepower = mySistersVehicle.calculateHpToTheWheel(5.7f);
    std::cout << sisterVehicleHorsepower << " HP" << std::endl;
    mySistersVehicle.resetEngineControlModule("1F34JFKASJ123122", false);

    SoccerTeamWrapper spanishSoccerTeam(new SoccerTeam);
    spanishSoccerTeam.soccerTeam->transferPlayerToTeam("PSG", "Barcelona");
    auto spanishTeamWinProbability = spanishSoccerTeam.soccerTeam->calculateWinProbability(4.56, 1);
    std::cout << spanishTeamWinProbability << " Win probability" << std::endl;
    spanishSoccerTeam.soccerTeam->printCalculateWinProbability();
    spanishSoccerTeam.soccerTeam->calculateTotalSeasonGoals(4, 130);

    SoccerTeam frenchSoccerTeam;
    frenchSoccerTeam.transferPlayerToTeam("Barcelona", "PSG");
    auto frenchTeamWinProbability = frenchSoccerTeam.calculateWinProbability(1.41, 3);
    std::cout << frenchTeamWinProbability << " Win probability" << std::endl;
    spanishSoccerTeam.soccerTeam->calculateTotalSeasonGoals(5, 210);

    DogShowWrapper previousUSDogShow(new DogShow);
    auto previousDogShowCost = previousUSDogShow.dogShow->calculateCostToEnterDogShow();
    std::cout << "Previous US dog show cost " << previousDogShowCost << std::endl;
    previousUSDogShow.dogShow->printCalculateCostToEnterDogShow();
    previousUSDogShow.dogShow->predictWinProbabilityDogShow("Lab", 80, "brown");
    auto previousDogShowEarnings = previousUSDogShow.dogShow->calculateTotalEarningsDogShow(1000.37f);
    std::cout << "Previous US dog show earnings " << previousDogShowEarnings << std::endl;
    previousUSDogShow.dogShow->printCalculateTotalEarningsDogShow();

    DogShowWrapper currentUSDogShow(new DogShow);
    auto currentDogShowCost = currentUSDogShow.dogShow->calculateCostToEnterDogShow(200);
    std::cout << "Current US dog show cost " << currentDogShowCost << std::endl;
    currentUSDogShow.dogShow->predictWinProbabilityDogShow("Mastiff", 100, "white");
    auto currentDogShowEarnings = currentUSDogShow.dogShow->calculateTotalEarningsDogShow(2001.55f);
    std::cout << "Current US dog show earnings " << currentDogShowEarnings << std::endl;

    DogShow::Animal cow;
    cow.determineAnimalShow("cow", "England");
    auto cowMaxLandSpeed = cow.calculateMaxLandSpeed();
    std::cout << "Max land speed is " << cowMaxLandSpeed << std::endl;
    cow.printCalculateMaxLandSpeed();
    cow.determineAnimalHealth("cow");

    DogShow::Animal horse;
    horse.determineAnimalShow("horse", "USA");
    auto horseMaxLandSpeed = horse.calculateMaxLandSpeed();
    std::cout << "Max land speed is " << horseMaxLandSpeed << std::endl;
    horse.determineAnimalHealth("horse");


    GermanShepherdWrapper racingShepherd(new GermanShepherd);
    racingShepherd.germanShepherd->calculateGermanShepherdEarnings(racingShepherd.germanShepherd->danielsDog.calculateTotalEarningsDogShow(1000));
    racingShepherd.germanShepherd->danielsDog.weightInPounds = 300;
    racingShepherd.germanShepherd->finishObstacleCourse(racingShepherd.germanShepherd->danielsDog.weightInPounds);

    GermanShepherdWrapper policeShepherd(new GermanShepherd);
    policeShepherd.germanShepherd->calculateGermanShepherdEarnings(policeShepherd.germanShepherd->danielsDog.calculateTotalEarningsDogShow(2000));
    policeShepherd.germanShepherd->finishObstacleCourse(policeShepherd.germanShepherd->danielsDog.weightInPounds);

    BayernMunichWrapper bayernMunichDivision1(new BayernMunich);
    bayernMunichDivision1.bayernMunich->germanTeam.starPlayer = "Mueller";
    bayernMunichDivision1.bayernMunich->germanTeam.numberOfPlayers = 9;
    bayernMunichDivision1.bayernMunich->performFreeKickFormation(bayernMunichDivision1.bayernMunich->germanTeam.numberOfPlayers);
    bayernMunichDivision1.bayernMunich->celebrateGoal(bayernMunichDivision1.bayernMunich->germanTeam.starPlayer);

    BayernMunichWrapper bayernMunichDivision2(new BayernMunich);
    bayernMunichDivision2.bayernMunich->germanTeam.starPlayer = "Ballack";
    bayernMunichDivision2.bayernMunich->performFreeKickFormation(bayernMunichDivision2.bayernMunich->germanTeam.numberOfPlayers);
    bayernMunichDivision2.bayernMunich->celebrateGoal(bayernMunichDivision2.bayernMunich->germanTeam.starPlayer);
    
    std::cout << "good to go!" << std::endl;
}
