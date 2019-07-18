// Created by felix on 3/31/2019.
#ifndef HR1_2018_2_MIINTENTO_SINGLETASK_H
#define HR1_2018_2_MIINTENTO_SINGLETASK_H

#include "Task.h"
#include <iostream>

class SingleTask : public Task {
public:
    explicit SingleTask (std::string name);
    bool execute() override;
};

#endif //HR1_2018_2_MIINTENTO_SINGLETASK_H