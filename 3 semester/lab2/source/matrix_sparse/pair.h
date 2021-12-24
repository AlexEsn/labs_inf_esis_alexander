#pragma once
#include <tuple>
#include "pair.h"

template<typename T1,typename T2>
class pair {
public:
    const T1 first;
    const T2 second;
    pair():first(T1()),second(T2()){

    }
    pair(T1 first_, T2 second_) : first(first_), second(second_) {}
};

bool operator > (const pair<int,int>& lhs,const pair<int,int>& rhs){
    return std::make_tuple(lhs.first,lhs.second) > std::make_tuple(rhs.first,rhs.second);
}

bool operator != (const pair<int,int>& lhs,const pair<int,int>& rhs){
    return std::make_tuple(lhs.first,lhs.second) != std::make_tuple(rhs.first,rhs.second);
}

template<typename T>
class node {
public:
    T DATA;
    pair<int,int> indices;
    node *M_LEFT;
    node *M_RIGHT;

    node(const pair<int,int>& indices_,T DATA_) : indices(indices_),DATA(DATA_){
        M_LEFT = NULL;
        M_RIGHT = NULL;
    }
    node(T key,node<T>* left,node<T>* right){
        DATA = key;
        M_LEFT = left;
        M_RIGHT = right;
    }

};