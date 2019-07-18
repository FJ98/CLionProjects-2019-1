// Created by felix on 4/24/2019.
#include "Progression.h"

Progression::Progression():first{1}, cur{1} {}
long Progression::firsValue(){return first;}
long Progression::getCur() {return cur;}
//Progression::Progression(long first) {}

ArithProgression::ArithProgression():Progression{}, inc{1} {}
ArithProgression::ArithProgression(long inc):inc{inc}{}
long ArithProgression::nextValue() { cur=cur+inc; return cur;}
long ArithProgression::getAtribute() {return inc;}
long ArithProgression::getInc(){return inc;}

GeoProgression::GeoProgression():base{2} {}
GeoProgression::GeoProgression(long base):base{base} {}
long GeoProgression::nextValue() {return cur=cur*base;}
long GeoProgression::getAtribute() {return base;}

FibonacciProgression::FibonacciProgression(): prev{0}  {}
FibonacciProgression::FibonacciProgression(long prev, long first):prev{prev}{this->first=first;}
long FibonacciProgression::nextValue() {return cur=cur+prev;}
long FibonacciProgression::getAtribute() {return prev;}

std::vector<long> get_series(Progression *p, int quantity) {
    std::vector<long> v1;
    long prog=0;
    ArithProgression a1;
    if(a1.getAtribute()==p->getAtribute()){}
    for(long i=0;i<quantity-1;i++){
        if(i==0){
            v1.push_back(p->firsValue());
        }else{
            prog=p->firsValue()+((i)*p->getAtribute());
            v1.push_back(prog);
        }
    }
    return v1;
}

long calculate_total(Progression *p, int quantity) {
    long total=0;
    for(auto item: get_series(p,quantity)){
        total = ( (  (p->firsValue()+p->nextValue()) *quantity  )  /2 );
        item++;
    }
    return total;
}
