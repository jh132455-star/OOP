#pragma once
#include "Job.h"
#include "GameEnum.h"
#include <memory>

class JobFactory {
public:
    static std::unique_ptr<Job> Create(JobType type);
};