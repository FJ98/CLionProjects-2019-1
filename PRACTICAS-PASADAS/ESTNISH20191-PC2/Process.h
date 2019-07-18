// Created by felix on 5/14/2019.
#ifndef ESTNISH20191_PC2_PROCESS_H
#define ESTNISH20191_PC2_PROCESS_H

#include <string>
class Process {
protected:
    std::string name;
    int duration;
public:
    explicit Process(std::string p_name);
    virtual bool run() = 0;
};
class SynProcess:public Process{
public:
    explicit SynProcess(std::string p_name);
    bool run() override ;
};
class ASynProcess : public Process{
    std::string callbackClient;
public:
    ASynProcess(std::string p_name, std::string p_callbackClient);
    bool run() override ;
};

#endif //ESTNISH20191_PC2_PROCESS_H
