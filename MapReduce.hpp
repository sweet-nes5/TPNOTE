#ifndef MAPREDUCE
#define MAPREDUCE
#include"Core.hpp"

#include <vector>
#include <iostream>
template<typename T>
class MapReduce{
private:
    
    std::vector<T>* values;
    Core<T>* core; 
    
public:
    static std::vector<Core<T>*> cores;
    MapReduce(std::vector<T>* b);  
    Core<T>* chooseCore();     

};

#endif