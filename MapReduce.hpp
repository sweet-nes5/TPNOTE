#ifndef MAPREDUCE
#define MAPREDUCE
#include"Core.cpp"

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
    static void afficherCores();     

};
//definition des methodes de la classes générique
template<typename T>
std::vector<Core<T>*> MapReduce<T>::cores={new Core<T>,new Core<T>,new Core<T>,new Core<T>};

template<typename T>
Core<T>* MapReduce<T>::chooseCore(){
    int temp =0;

  /*for(int i=0;i<4;i++){
     if (MapReduce<T>::cores[i]->getDEGRADATION()==0)
         core= MapReduce<T>::cores[i];
         std::cout<<*MapReduce<T>::cores[i];
         return core;
  }*/

}
template<typename T>
MapReduce<T>::MapReduce(std::vector<T>* b){
    values = b;
}
template<typename T>
void MapReduce<T>::afficherCores(){
    std::cout<<"****Coeurs disponibles****"<<std::endl;
    for (int i=0;i<4;i++){
       std::cout<<"id : "<< MapReduce<T>::cores[i]->getID()<<" |  "<< "degradation : "<<MapReduce<T>::cores[i]->getDEGRADATION()<<std::endl;
    }
}
#endif