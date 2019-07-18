// Created by felix on 5/5/2019.
#ifndef SP02_20182_RIVAS_SORT_H
#define SP02_20182_RIVAS_SORT_H

#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iostream>

class Sort {
protected:
    std::string title;
    long long duration;
public:
    Sort(std::string title);
    virtual long long Execute(std::vector<int> data) = 0;
    long long GetDuration();
    std::string GetTitle();
};

class MergeSort : public Sort{
public:
    MergeSort(std::string tit_merge);
    long long Execute(std::vector<int> data) override;
    template <class Iter>
    void DoMerge(Iter first, Iter last);
};
class BubbleSort : public Sort{
public:
    BubbleSort(std::string tit_bubble);
    long long Execute(std::vector<int> data) override;
};

/*
class Sort {
protected:
    std::string title;
    long long duration;
public:
    Sort(std::string title);
    virtual long long Execute(std::vector<int> data) = 0;
    long long GetDuration();
    std::string GetTitle();
};
class MergeSort : public Sort{
public:
    MergeSort(std::string tit_merge);
    long long Execute(std::vector<int> data) override;
    template <class Iter>
    void DoMerge(Iter first, Iter last);
};
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
*/

#endif //SP02_20182_RIVAS_SORT_H
