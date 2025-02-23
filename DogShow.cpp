
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