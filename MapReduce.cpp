#include "MapReduce.hpp"
#include "Core.cpp"
#include<vector>
#include<iostream>
template<typename T>
Core<T> *core1=new Core<T>;
template<typename T>
std::vector<Core<T>*> MapReduce<T>::cores={0,0,0,0};
template<typename T>
MapReduce<T>::MapReduce(std::vector<T> *b){
    MapReduce<T>::values = *b;
}