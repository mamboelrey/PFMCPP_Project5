struct SoccerTeamWrapper
{
    SoccerTeamWrapper(SoccerTeam* ptr): soccerTeam(ptr){}
    ~SoccerTeamWrapper()
    {
        delete soccerTeam;
    }

    SoccerTeam* soccerTeam = nullptr;
};

struct DogShowWrapper
{
    DogShowWrapper(DogShow* ptr): dogShow(ptr){}
    ~DogShowWrapper()
    {
        delete dogShow;
    }

    DogShow* dogShow = nullptr;
};

struct GermanShepherdWrapper
{
    GermanShepherdWrapper(GermanShepherd* ptr): germanShepherd(ptr){}
    ~GermanShepherdWrapper()
    {
        delete germanShepherd;
    }

    GermanShepherd* germanShepherd = nullptr;
};


struct BayernMunichWrapper
{
    BayernMunichWrapper(BayernMunich* ptr): bayernMunich(ptr){}
    ~BayernMunichWrapper()
    {
        delete bayernMunich;
    }

    BayernMunich* bayernMunich = nullptr;
};