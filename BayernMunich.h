#pragma once
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