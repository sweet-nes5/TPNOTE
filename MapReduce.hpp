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
    MapReduce(std::vector<T> *b);  
    Core<T>* chooseCore();
    Core<T>* getCore();
    static void afficherCores(); 
    //template<typename U>  map(U func(T x));   
    template<typename U> MapReduce<T>* map(U (*func)); 

};
//definition des methodes de la classes générique
template<typename T>
std::vector<Core<T>*> MapReduce<T>::cores={new Core<T>,new Core<T>,new Core<T>,new Core<T>};
//le constructeur
template<typename T>
MapReduce<T>::MapReduce(std::vector<T> *b):values{b},core{nullptr}{}
//la méthode pour choisir le coeur
template<typename T>
Core<T>* MapReduce<T>::chooseCore(){
    int min=MapReduce<T>::cores[0]->getDEGRADATION();
    int pos=0;//pour connaitre la position de l'element minimal
   for(unsigned int i=0;i<cores.size();i++){

     if (MapReduce<T>::cores[i]->getDEGRADATION()<min){
          min=MapReduce<T>::cores[i]->getDEGRADATION();
          pos=i;
          }
          continue;
    } 

    core=MapReduce<T>::cores[pos];
    core->set(values);
    return core;
}

template<typename T>
void MapReduce<T>::afficherCores(){
    std::cout<<"****Coeurs disponibles****"<<std::endl;
    for (int i=0;i<4;i++){
       std::cout<<"id : "<< MapReduce<T>::cores[i]->getID()<<" |  "<< "degradation : "<<MapReduce<T>::cores[i]->getDEGRADATION()<<std::endl;
    }
}
//methode map de MapReduce 

template<typename T>
template<typename U>   
MapReduce<T>* MapReduce<T>::map(U (*func)){
    chooseCore()->map(*func);
    return this;
}

template<typename T>
Core<T>* MapReduce<T>::getCore(){
    return this->core;
}
#endif