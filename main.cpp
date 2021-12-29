/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12
 Create a branch named Part1
Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 
=============================================
Since you didn't do Project 3:
=============================================
write 3 UDTs below that EACH have: 
        5 member variables
            the member variable names and types should be relevant to the work the UDT will perform.
            pick properties that can be represented with 'int float double bool char std::string'
        3 member functions with an arbitrary number of parameters
            give some of those parameters default values.
        constructors that initialize some of these member variables
            the remaining member variables should be initialized in-class
        for() or while() loops that modify member variables
 1) 2 of your 3 UDTs need to have a nested UDT.
    this nested UDT should fulfill the same requirements as above:
        5 member variables  
        3 member functions
        constructors and loops.
        
 2) Define your implementations of all functions OUTSIDE of the class. 
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
 
 4) add 2 new UDTs that use only the types you copied above as member variables.
 
 5) Add destructors to these 2 new types that do something.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 6) add 2 member functions to each of these 2 new types.
       These member functions should make use of the member variables. 
       Maybe interact with their properties or call their member functions.
       The purpose is to demonstrate that you know how to use a class's member variables and member functions when it is a member of another class.
 
 7) use at least 2 instances of each of your UDTs in main. 
       - call every member function of your UDTs to make sure they work as expected and don't produce warnings.
       - add some std::cout statements in main() that use your UDT's member variables.
       you have 5 UDTs and 2 nested UDTs, so there should be at minimum 14 UDTs declared in main(), as well as 14 * 3 function calls happening.
 
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
If you need inspiration for what to write, take a look at previously approved student projects in the Slack Workspace channel for this project part.
 */

/*
 UDT 1:
 */
#include <iostream>
#include <array>

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
    float calculateTrueSellValue(std::string make, float sellingPrice, int totalMilesOnVehicle = 10000);
    int calculateMilesUntilOilChange(int fuelType = 0, int totalMilesOnVehicle = 10000);
    bool predictRaceWinProbability(std::string make, int maxSpeed = 150);

    struct Vehicle
    {
        // 5 member variable
        int numberOfTires = 4;
        int maxSpeed;
        bool turboCharged;
        std::string vin;
        float engineDisplacement;

        // 3 member functions
        void renovateVehicle(std::string vin, int maxSpeed = 150, bool turboCharged = false);
        float calculateHpToTheWheel(float engineDisplacement, bool turboCharged = true, int maxSpeed = 200);
        void resetEngineControlModule(std::string vin, bool vehicleIsImmobolized = true);

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

float Car::calculateTrueSellValue(std::string make, float sellingPrice, int totalMilesOnVehicle)
{
    float trueSellValue = 0.0f;
    
    std::cout << "Calculating True Sell Value for " << make << std::endl;
    trueSellValue = (sellingPrice - (.1f * (static_cast<float>(totalMilesOnVehicle))));
    return trueSellValue;
}

int Car::calculateMilesUntilOilChange(int fuelType, int totalMilesOnVehicle)
{
    int milesUntilOilChange = 0;

    if ((milesUntilOilChange = totalMilesOnVehicle % 5000))
        std::cout << fuelType << " car needs doesn't need oil change" << std::endl;

    std::cout << "Car needs oil change in " << milesUntilOilChange << " miles"<< std::endl;
    return milesUntilOilChange;                                       
}
    
bool Car::predictRaceWinProbability(std::string make, int maxSpeed)
{
    int competitorMaxSpeed = 200;

    if (maxSpeed > competitorMaxSpeed)
    {
        std::cout << "You will most likely win in a race" << std::endl;
        return true;
    }

    std::cout << "You will most likely lose in a race" << std::endl;
    return false;
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

void Car::Vehicle::renovateVehicle(std::string vin, int maxSpeed, bool turboCharged)
{
    if((vin[9] < 'J') && (maxSpeed < 155))
    {
        std::cout << "Renovate vehicle" << std::endl;
    }

    std::cout << "Don't renovate vehicle" << std::endl;
}

float Car::Vehicle::calculateHpToTheWheel(float engineDisplacement, bool turboCharged, int maxSpeed)
{
    if(turboCharged)
    {
        return((engineDisplacement * 100.0f) + 100.0f + maxSpeed);
    }

    return ((engineDisplacement * 100.0f) + maxSpeed);
}

void Car::Vehicle::resetEngineControlModule(std::string vin, bool vehicleIsImmobolized)
{
    if((vin[9] > 'J') && vehicleIsImmobolized)
    {
        std::cout << "Reset module exists and starting ECM reset" << std::endl;
    }

    std::cout << "Reset module does not exist" << std::endl;
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
    double calculateWinProbability(double stoppageTime, int numberOfGoalsCurrentGame);
    int calculateTotalSeasonGoals(int numberOfGoalsCurrentGame, int numberOfGoalsUntilNow);

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

double SoccerTeam::calculateWinProbability(double stoppageTime, int numberOfGoalsCurrentGame)
{
    if((stoppageTime < 3.0) && (numberOfGoalsCurrentGame < 2))
    {
        std::cout << "Win probability over 50%" << std::endl;
        return 0.6;
    }

    std::cout << "Win probability less than 50%" << std::endl;
    return 0.4;
}

int SoccerTeam::calculateTotalSeasonGoals(int numberOfGoalsCurrentGame, int numberOfGoalsUntilNow)
{
    return (numberOfGoalsCurrentGame + numberOfGoalsUntilNow);
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
    
    float calculateCostToEnterDogShow(int weightInPounds = 30, std::string furColor = "brown", float entranceFee = 1000.54f);
    void predictWinProbabilityDogShow(std::string breedName, int weightInPounds, std::string furColor);
    float calculateTotalEarningsDogShow(float totalWinnings, float entranceFee = 2000.0f); 
    DogShow();
    ~DogShow();

    struct Animal
    {
        int numberOfLegs = 4;
        int theoreticalSpeed;
        std::string animalType;
        std::string countryOfShow;
        int ageOfAnimal;

        void determineAnimalShow(std::string animalType, std::string countryOfShow = "USA");
        int calculateMaxLandSpeed(int theoreticalSpeed = 40);
        void determineAnimalHealth(std::string animalType = "dog", int ageOfAnimal = 13);

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

float DogShow::calculateCostToEnterDogShow(int weightInPounds, std::string furColor, float entranceFee)
{
    float totalCost = entranceFee;

    if(weightInPounds > 50)
    {
        totalCost += 50.45f;
    }
    else if(furColor == "white")
    {
        totalCost+= 75.63f;
    }
    else
    {
        std::cout << "No additional costs" << std::endl;
    }

    return totalCost;
}

void DogShow::predictWinProbabilityDogShow(std::string breedName, int weightInPounds, std::string furColor)
{
    float winProbability  = 0.0f;
    std::array<std::string, 5> breeds = {"Pitbull", "German Shepherd", "Lab", "Great Dane", "Mastiff"};

    for(int i = 0; i < 5; ++i)
    {
        if(breedName == breeds[i])
        {
            winProbability += .4f;
            break;
        }
    }

    if(furColor != "white")
    {
        winProbability += .2f;
    }

    winProbability = (winProbability+ weightInPounds) / 100;
    std::cout << winProbability << "chance of win probability" << std::endl;
}

float DogShow::calculateTotalEarningsDogShow(float totalWinnings, float entranceFee)
{
    return (totalWinnings - entranceFee);
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

void DogShow::Animal::determineAnimalShow(std::string animalType, std::string countryOfShow)
{
    if((animalType == "dog" || animalType == "horse") && (countryOfShow == "USA"))
    {   
        std::cout << "Show exists for" << animalType << std::endl;
        return;
    }

    std::cout << "No show exists for animal" << animalType << std::endl;
}

int DogShow::Animal::calculateMaxLandSpeed(int theoreticalSpeed)
{
    return (theoreticalSpeed - 10);
}

void DogShow::Animal::determineAnimalHealth(std::string animalType, int ageOfAnimal)
{
    if(ageOfAnimal > 10)
    {
        std::cout << animalType << "health is bad" << std::endl;
        return;
    }

    std::cout << animalType << "health is good" << std::endl;
}

/*
 new UDT 4:
 */
struct GermanShepherd
{
    DogShow danielsDog;

    void calculateGermanShepherdEarnings(float entranceFee);
    void finishObstacleCourse(int weightInPounds);

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

/*
 new UDT 5:
 */

struct BayernMunich
{
    SoccerTeam germanTeam;

    void performFreeKickFormation(int numberOfPlayers);
    void celebrateGoal(std::string starPlayer);
    
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
    std::cout << starPlayer << "celebrates a great goal!" << std::endl;
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
    myBrothersCar.predictRaceWinProbability("Ford");
    myBrothersCar.calculateTrueSellValue("Ford", 6000.75f, 100000);
    myBrothersCar.calculateMilesUntilOilChange(1, 67089);
    
    Car mySistersCar;
    mySistersCar.predictRaceWinProbability("Dodge");
    mySistersCar.calculateTrueSellValue("Dodge", 5000.75f, 10000);
    mySistersCar.calculateMilesUntilOilChange(2, 6734);

    Car::Vehicle myBrothersVehicle;
    myBrothersVehicle.renovateVehicle("1G5JFKASJ123122", 300, false);
    float brotherVehicleHorsepower = myBrothersVehicle.calculateHpToTheWheel(4.1f);
    std::cout << brotherVehicleHorsepower << " HP" << std::endl;
    myBrothersVehicle.resetEngineControlModule("G5JFKASJ123122", true);

    Car::Vehicle mySistersVehicle;
    mySistersVehicle.renovateVehicle("1F34JFKASJ123122", 200, true);
    float sisterVehicleHorsepower = mySistersVehicle.calculateHpToTheWheel(5.7f);
    std::cout << sisterVehicleHorsepower << " HP" << std::endl;
    mySistersVehicle.resetEngineControlModule("1F34JFKASJ123122", false);

    SoccerTeam spanishSoccerTeam;
    spanishSoccerTeam.transferPlayerToTeam("PSG", "Barcelona");
    double spanishTeamWinProbability = spanishSoccerTeam.calculateWinProbability(1.56, 4);
    std::cout << spanishTeamWinProbability << " Win probability" << std::endl;
    spanishSoccerTeam.calculateTotalSeasonGoals(4, 130);

    SoccerTeam frenchSoccerTeam;
    frenchSoccerTeam.transferPlayerToTeam("Barcelona", "PSG");
    double frenchTeamWinProbability = frenchSoccerTeam.calculateWinProbability(1.41, 3);
    std::cout << frenchTeamWinProbability << " Win probability" << std::endl;
    spanishSoccerTeam.calculateTotalSeasonGoals(5, 210);

    DogShow previousUSDogShow;
    float previousDogShowCost = previousUSDogShow.calculateCostToEnterDogShow();
    std::cout << "Previous US dog show cost " << previousDogShowCost << std::endl;
    previousUSDogShow.predictWinProbabilityDogShow("Lab", 80, "brown");
    float previousDogShowEarnings = previousUSDogShow.calculateTotalEarningsDogShow(1000.37f);
    std::cout << "Previous US dog show earnings " << previousDogShowEarnings << std::endl;

    DogShow currentUSDogShow;
    float currentDogShowCost = currentUSDogShow.calculateCostToEnterDogShow(200);
    std::cout << "Current US dog show cost " << currentDogShowCost << std::endl;
    currentUSDogShow.predictWinProbabilityDogShow("Mastiff", 100, "white");
    float currentDogShowEarnings = currentUSDogShow.calculateTotalEarningsDogShow(2001.55f);
    std::cout << "Current US dog show earnings " << currentDogShowEarnings << std::endl;

    DogShow::Animal cow;
    cow.determineAnimalShow("cow", "England");
    int cowMaxLandSpeed = cow.calculateMaxLandSpeed();
    std::cout << "Max land speed is " << cowMaxLandSpeed << std::endl;
    cow.determineAnimalHealth("cow");

    DogShow::Animal horse;
    horse.determineAnimalShow("horse", "USA");
    int horseMaxLandSpeed = horse.calculateMaxLandSpeed();
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
