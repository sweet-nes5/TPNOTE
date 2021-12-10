#include "MapReduce.hpp"
#include<vector>


template<typename T>
std::vector<Core<T>*> MapReduce<T>::cores={0,0,0};
template<typename T>
MapReduce<T>::MapReduce(std::vector<T> b){
    values={};
}