#include "JobFactory.h"
#include "Warrior.h"
#include "Mage.h"

std::unique_ptr<Job> JobFactory::Create(JobType type) {
    switch (type) {
    case JobType::Warrior: 
        return std::make_unique<Warrior>();
    case JobType::Mage:    
        return std::make_unique<Mage>();
    default:               
        return nullptr;
    }
}