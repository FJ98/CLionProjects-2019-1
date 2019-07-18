#include <iostream>
#include "Sort.h"
#include "Analyzer.h"
#include <random>
int main() {
    auto a = new Analyzer();
    int n=1000;
    std::random_device r;
    for (int j = 0; j < n; ++j) {
        a->PushData(r()%n+1);
    }
    auto b1 = new BubbleSort("Bubble Sort");
    auto m1 = new MergeSort("Merge Sort");

    a->PushMethod(b1);
    a->PushMethod(m1);

    a->ExecuteAll();
    a->ShowDurations();

    /*
    std::vector<int> v{8, 2, 0, -1, 9};
    Sort* b1=new BubbleSort();
    Sort* m1=new MergeSort();
    for(auto i : v){
        std::cout<<i<<"  ";
    }std::cout<<"\n\n";
    b1->Execute(v);
    */
    return 0;
}