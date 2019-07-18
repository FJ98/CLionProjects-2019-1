// Created by felix on 5/5/2019.
#include "Sort.h"


Sort::Sort(std::string title) : title{title},duration{0}{}
long long Sort::GetDuration() {return duration;}
std::string Sort::GetTitle() {return title;}
BubbleSort::BubbleSort(std::string tit_bubble) : Sort{tit_bubble} {}
MergeSort::MergeSort(std::string tit_merge):Sort{tit_merge} {}


long long MergeSort::Execute(std::vector<int> data) {
    using tp = typename std::chrono::steady_clock::time_point;
    tp start = std::chrono::steady_clock::now();

    DoMerge(data.begin(),data.end());
    //for (auto item: data){std::cout<<item<<"  ";}std::cout<<"\n";
    tp end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
    return duration;
}

template <class Iter>
void MergeSort::DoMerge(Iter first, Iter last) {
    Iter middle;
    if(last-first>1){
        middle=first+(last-first)/2;
        DoMerge(first, middle);
        DoMerge(middle, last);
        std::inplace_merge(first,middle,last);
    }
}

long long BubbleSort::Execute(std::vector<int> data) {
    using tp = typename std::chrono::steady_clock::time_point;
    tp start = std::chrono::steady_clock::now();

    for(int i=0; i < data.size()-1;++i){
        for (int j = i+1; j < data.size(); ++j) {
            if(data[i]>data[j]){
                std::swap(data[i],data[j]);
            }
        }
    }
    //for (auto item: data){std::cout<<item<<"  ";}std::cout<<std::endl;
    tp end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
    return duration;
}


