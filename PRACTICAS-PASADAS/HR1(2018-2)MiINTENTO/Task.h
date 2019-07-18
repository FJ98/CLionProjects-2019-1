#ifndef HR1_2018_2_MIINTENTO_TASK_H // Created by felix on 3/31/2019.
#define HR1_2018_2_MIINTENTO_TASK_H

#include <iostream>

class Task {
protected:
    std::string name;
    int runtime;
public:
    virtual bool execute() = 0;

    explicit Task (std::string &name);

};


#endif //HR1_2018_2_MIINTENTO_TASK_H
