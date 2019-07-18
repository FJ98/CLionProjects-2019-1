// Created by felix on 6/5/2019.
#ifndef PC3_PRACTICE_FUNCIONES_H
#define PC3_PRACTICE_FUNCIONES_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <deque>
#include <bits/stdc++.h>
using namespace std;

auto reverseQueue(std::queue<int> q){
    std::vector<int> v;
    std::stack<int> stk;
    std::reverse(v.begin(),v.end());
}


template <typename T>
auto suma (T num) {
    return num;
}

template <typename T, typename... Params>
auto suma (T first_arg, Params... args) {
    auto sum = suma(first_arg) + suma(args...);
    return sum;
}

//------------------------------BALANCED PARENTHESIS--------------------------------------------------------------------
std::string isBalanced(const std::string& s){
    std::stack<char> stk;
    for (auto item : s) {
        if ( item == '(' || item == '{' || item == '[' ){
            stk.push(item);
        } else if (  ( !stk.empty() ) && ( (item == ')' && stk.top() == '(') ||
                (item == '}' && stk.top() == '{') || (item == ']' && stk.top() == '[') )  ) {
            stk.pop();
        } else {
            return "NO";
        }
    }
    if (stk.empty()) { return "YES"; }
    else { return "NO"; }
}
// BALANCED PARENTHESIS OTRA FORMA
string isBalanced2(const string& s) {
    stack<char> st; map<char,char> m;
    m['}']='{'; m[']']='['; m[')']='(';
    for(auto ch: s){
        if(ch=='{' || ch=='[' || ch=='(') {st.push(ch);}
        else if(st.top() == m[ch]) {st.pop();}
        else {return "NO";}
    }
    return st.empty() ? "YES" : "NO";
}
// Falta
bool isBalanced3(const std::string & string1){
    std::stack<char> stack; std::map<char, char> map;
    map['}'] = '{'; map[']'] = '['; map[')'] = '(';
    for (int i = 0; i < 5; ++i) {  }
}
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------MAKING ANAGRAMS HACKERRANK----------------------------------------------------------
int makingAnagrams(string s1, string s2) {
    int first[26] = {0}, second[26] = {0}, len1=0, len2=0, cont=0;
    len1 = s1.size(); len2 = s2.size();
    for(int i = 0; i < len1; i++) { first[s1[i]-97]++; }
    for(int i = 0; i < len2 ;i++) { second[s2[i]-97]++; }
    for(int i = 0; i < 26; i++) { cont += abs(first[i] - second[i]); }
    return cont;
}
//----------------------------------------------------------------------------------------------------------------------

//--------------------------------QUEUE WITH TWO STACKS HACKERRANK------------------------------------------------------
class Queue{
    std::stack<int> stackNewestOnTop;
    std::stack<int> stackOldestOnTop;
public:
    Queue() = default;
    void enqueue(int value);
    int peek();
    void shiftStacks();
    int dequeue();
};

void Queue::enqueue(int value) { stackNewestOnTop.push(value); }

void Queue::shiftStacks() {
    if (stackOldestOnTop.empty()) {
        while(!stackNewestOnTop.empty()){
            stackOldestOnTop.push((stackNewestOnTop.top()));
            stackNewestOnTop.pop();
        }
    }
}

int Queue::peek(){
    shiftStacks();
    return stackOldestOnTop.top();
}

int Queue::dequeue() {
    shiftStacks();
    int saveTop = stackOldestOnTop.top();
    stackOldestOnTop.pop();
    return saveTop;
}
//----------------------------------------------------------------------------------------------------------------------

//--------------------------------------------DEQUE STL-----------------------------------------------------------------
template <typename T>
void printKMax(T arr[], int tamArr, int tamSubArr){
    std::deque<T> dq;
    std::cout << "Valores maximos (subgrupos de " << tamSubArr << "): ";
    for (int i = 0; i < tamArr; i++){
        if ( dq.empty() ) { dq.push_back(i); }
        if ( dq.front() <= (i - tamSubArr) ) { dq.pop_front(); }
        while (!dq.empty() && arr[i] >= arr[dq.back()]) { dq.pop_back(); }
        dq.push_back(i);
        if (i >= (tamSubArr - 1)) { std::cout << arr[dq.front()] << " "; }
    } std::cout << std::endl;
}
//----------------------------------------------------------------------------------------------------------------------

template <int T>
struct Fibonacci{ enum { value = (Fibonacci<T - 1>::value + Fibonacci<T - 2>::value) }; };
template <>
struct Fibonacci<0> { enum { value = 1 }; };
template <>
struct Fibonacci<1> { enum { value = 1 }; };
//template <> struct Fibonacci<2> { enum { value = 1 }; };

template <typename T>
T fibo(T n){
    if (n < 2){
        return 1;
    }else{
        return (fibo(n-1)+fibo(n-2));
    }
}

template <typename T, typename U, typename  V>
T aritTerm(T start, U diff, V term){
    return (start + (term - 1) * diff);
}

template <typename T, typename U, typename  V>
T aritSum(T start, U term, V n){
    return ((start + term) * n)/2;
}

template <typename T>
auto crearPA(T start, T cant, T inc){
    std::vector<T> vec;
    vec.push_back(start);
    for (auto i = 1; i < cant; ++i) {
        start = start + inc ;
        vec.push_back(start);
    }
    return vec;
}
template <typename T>
struct generatePA {
    T current_;
    T inc_;
    explicit generatePA (T start, T inc) : current_(start - inc), inc_(inc) {}
    T operator() () {
        return current_ +=  inc_;
    }
};




#endif //PC3_PRACTICE_FUNCIONES_H
