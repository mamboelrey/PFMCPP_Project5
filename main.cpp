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
