#pragma once
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