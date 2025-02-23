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