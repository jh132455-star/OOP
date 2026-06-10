#pragma once

class SkillCapable {
public:
    virtual unsigned int UseSkill(unsigned int& currentMp) = 0;
};