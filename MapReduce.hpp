#ifndef MAPREDUCE
#define MAPREDUCE
#include"Core.hpp"

#include <vector>
#include <iostream>
template<typename T>
class MapReduce{
private:
    static std::vector<Core<T>*> cores;
    std::vector<T>* values;
    Core<T>* core; 
    
public:
    MapReduce(std::vector<T> b);  
    Core<T>* chooseCore();     

};

#endif