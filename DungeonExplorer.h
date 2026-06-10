#pragma once
#include "BattleSystem.h"
#include "Character.h"
#include <random>
#include "MonsterFactory.h"

class DungeonExplorer {
public:
    void EnterDungeon(MonsterType type);
    bool Explore(Character& character);
    MonsterType GetDungeonType();
private:
    bool TryEncounter();

    MonsterType type;
    MonsterFactory factory;
    static constexpr int MAX_ROUNDS = 10;
    static constexpr int ENCOUNTER_PERCENT = 40;
};
