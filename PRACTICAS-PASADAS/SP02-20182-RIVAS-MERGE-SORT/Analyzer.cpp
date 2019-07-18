// Created by felix on 5/5/2019.
#include "Analyzer.h"
#include <iostream>
void Analyzer::PushData(int item) {data.push_back(item);}

void Analyzer::PushMethod(Sort *method) {metodos.push_back(method);}

void Analyzer::ExecuteAll() {
    for(auto & item : metodos){
        item->Execute(data);
    }
}

void Analyzer::ShowDurations() {
    for(auto & item: metodos){
        std::cout<<item->GetTitle()<<" "<<item->GetDuration()<<std::endl;
    }
}

std::vector<int> Analyzer::getData() {return data;}
std::vector<Sort *> Analyzer::getMetodos() {return metodos;}
