#include "TownManager.h"
#include <iostream>
using namespace std;

void TownManager::EnterHospital(Character& character) {
    cout << "\n=== Entered Town ===" << endl;
    cout << "Your HP restored." << endl;
    character.TakeHp(50);
    //cout << "Current HP: " << character.GetHp() << endl;
}

void TownManager::ChangeJob(Character& character)
{
    cout << "\n=== Change Job ===" << endl;
    cout << "1. Warrior (Skill: Shield Bash, MP 10)" << endl;
    cout << "2. Mage    (Skill: Fireball,   MP 20)" << endl;
    cout << "Select: ";

    int choice;
    cin >> choice;

    JobType jobType;
    switch (choice) {
    case 1: jobType = JobType::Warrior; break;
    case 2: jobType = JobType::Mage;    break;
    default:
        cout << "Invalid input." << endl;
        return;
    }

    character.SetJob(JobFactory::Create(jobType));
    cout << "Job changeded "<< "!" << endl;
}