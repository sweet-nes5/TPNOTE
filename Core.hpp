#ifndef CORE
#define CORE


#include <vector>
#include <iostream>
#include <type_traits>
#include<string>

template<typename T> class MapReduce;

template<typename T> class Core{

friend MapReduce<T>; 

private:
    int id;
    int degradation=0;
    
    static int nbinst;
public:
    std::vector<T>* values;
    virtual ~Core();//aussi concernant le destructeur,est il obligatoire de mettre virtual?
    static int getCount();
    static void incrnb(); 
    template<typename U> Core<T>& map(U (*func)); 
    template<typename U> T reduce(U (*func),T z); 
    const int getID()const;
    void set(std::vector<T>* vec);
    const int getDEGRADATION()const ;//le premier const veut dire que le fonction renvoie un const et le 2eme c'est que l'objet dans la methode ne sera po modifié
    //friend std::ostream& operator<<(std::ostream& os, const Core<T>& core);
     
protected:    
    Core();
};
//definition des methodes de la classe
//la surchage de l'operateur d'affichage
template<typename T>
std::ostream& operator<< (std::ostream& os, const Core<T>* core)
{
    os<<"----Core----"<<std::endl;
    os<<"id "<<core->getID()<<",  "<<"degradation "<<core->getDEGRADATION()<<std::endl<<std::endl;

   if(!core->values->empty()){//affiche si values n'est pas vide
      std::cout<<"values : [ ";
      for(unsigned int i=0;i<core->values->size();i++){
         
          std::cout<<core->values->at(i)<<" ";

      } std::cout<<"]"<<std::endl;
   }

    return os;
}
//le setter
template<typename T>
void Core<T>::set(std::vector<T>* vec){
    this->values=vec;
}

//initialisation du nombre d'instanciations
template<typename T>
int Core<T>::nbinst=0;
//la méthode qui incrémente le nb d'instanciations
template<typename T>
void Core<T>::incrnb(){
    Core<T>::nbinst++;
}
//le constructeur
template<typename T>
Core<T>::Core():values{nullptr}{
    
    id=Core<T>::nbinst;
    Core<T>::nbinst++;
    
}
//le destructeur 
template<typename T>
Core<T>::~Core(){
    values->clear();
}
//la méthode qui retourne le nombre d'instanciations
template<typename T>
int Core<T>::getCount(){
   return Core<T>::nbinst;
}
//getter de id
template<typename T>
const int Core<T>::getID()const {
    return id;
}
//getter de degradation
template<typename T>
const int Core<T>::getDEGRADATION()const {
    return degradation;
}
//méthode map
template<typename T>
template<typename U>
Core<T>& Core<T>::map(U (*func))
{
    this->degradation++;

    for(unsigned int i=0;i<values->size();i++){
            if (!func(values->at(i))){
                    values->erase(values->begin()+i); 
                     i--;    
                     }
             }
    

 return *this;   
}
//methode reduce
template<typename T>
template<typename U>
T Core<T>::reduce(U (*func),T z){
    this->degradation++;
    int result =0;
    //int count =0;

   // if(std::is_same<T, int>::value){ //j'ai voulue verifier pour les differents type(int,string) mais ça m'a créé des bug,dommage:(
       result=func(values->at(0),values->at(1));
        for (unsigned int i=2;i<values->size();i++){
            result=func(values->at(i),result);
            //result=func(count,values->at(i));
        }
        z=z+result;
        return z;
  /*} else {
       */
    //return z;
}
#endif
