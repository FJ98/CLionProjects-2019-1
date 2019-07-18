// Created by felix on 3/31/2019.
#ifndef HR1_2018_2_MIINTENTO_FAULTTOLERANCETASK_H
#define HR1_2018_2_MIINTENTO_FAULTTOLERANCETASK_H


#include <iostream>
#include "Task.h"


class FaultToleranceTask : public Task {
private:
    int maxAttempts;
public:
    FaultToleranceTask (std::string name, int maxAttempts);
    bool execute() override;
};


#endif //HR1_2018_2_MIINTENTO_FAULTTOLERANCETASK_H
