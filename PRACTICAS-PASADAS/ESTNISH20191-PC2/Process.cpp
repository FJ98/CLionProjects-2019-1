#include <utility>
// Created by felix on 5/14/2019.
#include "Process.h"
#include <random>
#include <iostream>
Process::Process(std::string p_name) : name{std::move(p_name)}, duration{0} {}

SynProcess::SynProcess(std::string p_name) : Process(std::move(p_name)) {}

bool SynProcess::run() {
    std::random_device rd;
    duration = rd()%90+10;
    if (duration > 80) {
        std::cout << "Sync Process " << name << std::endl;
        std::cout << "-\tDuration: " << duration << std::endl;
        std::cout << "-\tResult: Success\n" << std::endl;
        return true;
    }
    else{
        std::cout << "Sync Process " << name << std::endl;
        std::cout << "-\tDuration: " << duration << std::endl;
        std::cout << "-\tResult: Fail\n" << std::endl;
        return false;
    }

}


ASynProcess::ASynProcess(std::string p_name, std::string p_callbackClient)
: Process{std::move(p_name)}, callbackClient{std::move(p_callbackClient)} {}

bool ASynProcess::run() {
    std::random_device rd;
    std::cout << "Sync Process "<< name << std::endl;
    for (int i = 1; i <= 10; ++i) {
        duration = rd()%1000+100;
        std::cout << "Attempt "<< i << std::endl;
        if (duration%2 != 0) {
            std::cout << "-\tDuration: " << duration << std::endl;
            std::cout << "-\tResult: Success\n" << std::endl;
            return true;
        }
        else{
            std::cout << "-\tDuration: " << duration << std::endl;
            std::cout << "-\tResult: Fail" << std::endl;
        }
    }
    return false;
}
