// Created by felix on 5/5/2019.
#ifndef SP02_20182_RIVAS_ANALYZER_H
#define SP02_20182_RIVAS_ANALYZER_H

#include "Sort.h"

class Analyzer {
private:
    std::vector<int> data;
    std::vector<Sort*> metodos;
public:
    void PushData(int item);
    void PushMethod(Sort* method);
    void ExecuteAll();
    void ShowDurations();
    std::vector<int> getData();
    std::vector<Sort*> getMetodos();
};


#endif //SP02_20182_RIVAS_ANALYZER_H
