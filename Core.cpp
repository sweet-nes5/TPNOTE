#include"Core.hpp"
#include<iostream>
template<typename T>
int Core<T>::nbinst=0;
//la méthode qui incrémente le nb d'instanciations
template<typename T>
void Core<T>::incrnb(){
    Core<T>::nbinst++;
}
//le constructeur
template<typename T>
Core<T>::Core(){
    Core<T>::incrnb();
}
//la méthode qui retourne le nombre d'instanciations
template<typename T>
int Core<T>::getCount(){
   return Core<T>::nbinst;
}
//la surchage de l'operateur d'affichage
template<typename T>
std::ostream& operator<< (std::ostream& os, const Core<T>& core)
{
    os<<"----Core----"<<'\n';
    os<<"id "<<core.id<<","<<"degradation "<<core.degradation<<'\n';

    return os;
}
