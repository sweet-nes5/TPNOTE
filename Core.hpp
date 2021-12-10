#ifndef CORE
#define CORE


#include <vector>
#include <iostream>
template<typename T> class MapReduce;
template<typename T> class Core{

friend MapReduce<T>; 

private:
    int id;
    int degradation=0;
    std::vector<T>* values;
    static int nbinst;
public:
    
    //virtual ~Core();
    static int getCount();
    static void incrnb(); 
    Core<T> map(T(*func(T x))); 
    const int getID()const ;
    const int getDEGRADATION()const ;//le premier const veut dire que le fonction renvoie un const et le 2eme c'est que l'objet dans la methode ne sera po modifié
    //friend std::ostream& operator<<(std::ostream& os, const Core<T>& core);
     
protected:    
    Core();

};
//definition des methodes de la classe
 

//la surchage de l'operateur d'affichage
template<typename T>
std::ostream& operator<< (std::ostream& os, const Core<T>& core)
{
    os<<"----Core----"<<std::endl;
    os<<"id "<<core.getID()<<",  "<<"degradation "<<core.getDEGRADATION()<<std::endl;

    return os;
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
Core<T>::Core(){
    id=Core<T>::nbinst;
    Core<T>::nbinst++;
    
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

#endif
