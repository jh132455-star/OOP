#include "DungeonExplorer.h"
#include <iostream>
using namespace std;

void DungeonExplorer::EnterDungeon(MonsterType type)
{
    this->type = type;
}

bool DungeonExplorer::Explore(Character& character) {
    cout << "\n===Dungeon Exploration Start ===" << endl;

    for (int round = 1; round <= MAX_ROUNDS; round++) {
        if (character.IsDead()) {
            cout << "Character is dead. Exploration stopped." << endl;
            break;
        }

        if (TryEncounter()) {
            cout << "Encountered a Monster!" << endl;
            return true;
        }
        else {
            cout << "Nothing happened." << endl;
            return false;
        }
    }
    return false;
}

MonsterType DungeonExplorer::GetDungeonType()
{
    return type;
}

bool DungeonExplorer::TryEncounter() {
    static mt19937 rng(random_device{}());
    uniform_int_distribution<int> dist(1, 100);
    return dist(rng) <= ENCOUNTER_PERCENT;
}