/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

7) If you were using any UDTs as function arguments like this:
*/
#if false
void someMemberFunction(Axe axe);
#endif
/*
  Pass those arguments by Reference now that you know what references are (Project 6 Part 2).
*/
#if false
void someMemberFunction(Axe& axe);
#endif
/*
If you aren't modifying the passed-in object inside the function, pass by const reference.
*/
#if false
void someMemberFunction(const Axe& axe);
#endif
/*
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 Clear any warnings about exit-time-destructors.
 Suppress them by adding -Wno-exit-time-destructors to the .replit file with the other warning suppression flags
 */





/*
 UDT 1:
 */
#include <iostream>
#include <array>
#include <cmath>

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
    };
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
    };
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
    Car myBrothersCar;
    auto brotherWinProbability = myBrothersCar.predictRaceWinProbability("Ford", 250);
    std::cout << "Brother win probability " << brotherWinProbability << std::endl;
    myBrothersCar.printPredictRaceWinProbability();
    auto brothersCarSellValue = myBrothersCar.calculateTrueSellValue("Ford", 6000.75f, 100000);
    std::cout << "True sell value of brothers car: $" << brothersCarSellValue << std::endl; 
    myBrothersCar.printCalculateTrueSellValue();
    myBrothersCar.calculateMilesUntilOilChange(1, 10000);

    Car mySistersCar;
    auto sisterWinProbability = mySistersCar.predictRaceWinProbability("Dodge");
    std::cout << "Sister win probability " << sisterWinProbability << std::endl;
    auto sistersCarSellValue = mySistersCar.calculateTrueSellValue("Dodge", 5000.75f, 10000);
    std::cout << "True sell value of sisters car: $" << sistersCarSellValue << std::endl; 
    mySistersCar.calculateMilesUntilOilChange(2, 6734);

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

    SoccerTeam spanishSoccerTeam;
    spanishSoccerTeam.transferPlayerToTeam("PSG", "Barcelona");
    auto spanishTeamWinProbability = spanishSoccerTeam.calculateWinProbability(4.56, 1);
    std::cout << spanishTeamWinProbability << " Win probability" << std::endl;
    spanishSoccerTeam.printCalculateWinProbability();
    spanishSoccerTeam.calculateTotalSeasonGoals(4, 130);

    SoccerTeam frenchSoccerTeam;
    frenchSoccerTeam.transferPlayerToTeam("Barcelona", "PSG");
    auto frenchTeamWinProbability = frenchSoccerTeam.calculateWinProbability(1.41, 3);
    std::cout << frenchTeamWinProbability << " Win probability" << std::endl;
    spanishSoccerTeam.calculateTotalSeasonGoals(5, 210);

    DogShow previousUSDogShow;
    auto previousDogShowCost = previousUSDogShow.calculateCostToEnterDogShow();
    std::cout << "Previous US dog show cost " << previousDogShowCost << std::endl;
    previousUSDogShow.printCalculateCostToEnterDogShow();
    previousUSDogShow.predictWinProbabilityDogShow("Lab", 80, "brown");
    auto previousDogShowEarnings = previousUSDogShow.calculateTotalEarningsDogShow(1000.37f);
    std::cout << "Previous US dog show earnings " << previousDogShowEarnings << std::endl;
    previousUSDogShow.printCalculateTotalEarningsDogShow();

    DogShow currentUSDogShow;
    auto currentDogShowCost = currentUSDogShow.calculateCostToEnterDogShow(200);
    std::cout << "Current US dog show cost " << currentDogShowCost << std::endl;
    currentUSDogShow.predictWinProbabilityDogShow("Mastiff", 100, "white");
    auto currentDogShowEarnings = currentUSDogShow.calculateTotalEarningsDogShow(2001.55f);
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


    GermanShepherd racingShepherd;
    racingShepherd.calculateGermanShepherdEarnings(racingShepherd.danielsDog.calculateTotalEarningsDogShow(1000));
    racingShepherd.danielsDog.weightInPounds = 300;
    racingShepherd.finishObstacleCourse(racingShepherd.danielsDog.weightInPounds);

    GermanShepherd policeShepherd;
    policeShepherd.calculateGermanShepherdEarnings(policeShepherd.danielsDog.calculateTotalEarningsDogShow(2000));
    policeShepherd.finishObstacleCourse(policeShepherd.danielsDog.weightInPounds);

    BayernMunich bayernMunichDivision1;
    bayernMunichDivision1.germanTeam.starPlayer = "Mueller";
    bayernMunichDivision1.germanTeam.numberOfPlayers = 9;
    bayernMunichDivision1.performFreeKickFormation(bayernMunichDivision1.germanTeam.numberOfPlayers);
    bayernMunichDivision1.celebrateGoal(bayernMunichDivision1.germanTeam.starPlayer);

    BayernMunich bayernMunichDivision2;
    bayernMunichDivision2.germanTeam.starPlayer = "Ballack";
    bayernMunichDivision2.performFreeKickFormation(bayernMunichDivision2.germanTeam.numberOfPlayers);
    bayernMunichDivision2.celebrateGoal(bayernMunichDivision2.germanTeam.starPlayer);
    
    std::cout << "good to go!" << std::endl;
}
