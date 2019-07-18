// Created by felix on 5/5/2019.
#ifndef SP01_20182_STANISH_1__TASK_H
#define SP01_20182_STANISH_1__TASK_H

#include <string>

class Task {
protected:
    std::string name;
    int runtime;
public:
    Task(std::string name);
    virtual bool execute()=0;
};

class SingleTask : public Task{
public:
    SingleTask(std::string name);
    bool execute() override;
};

class FaultToleranceTask : public Task{
private:
    int maxAttempts;
public:
    FaultToleranceTask(std::string name, int maxAttempts);
    bool execute() override;
};


#endif //SP01_20182_STANISH_1__TASK_H
