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