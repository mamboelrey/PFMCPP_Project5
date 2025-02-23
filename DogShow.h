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