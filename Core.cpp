#include"Core.hpp"
template<typename T>
int Core<T>::nbinst=0;

template<typename T>
void Core<T>::incrnb(){
    Core<T>::nbinst++;
}

template<typename T>
Core<T>::Core(){
    Core<T>::incrnb();
}