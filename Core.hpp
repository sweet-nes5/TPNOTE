#ifndef CORE
#define CORE


#include <vector>
#include <iostream>

template<typename T> class Core{
private:
    int id;
    static int nbinst;
    int degradation;
    std::vector<T>* values;
public:
    
    virtual ~Core();
    static int getCount(); 
    static void incrnb(); 
    Core<T> map(T(*func(T x))); 
    //friend std::ostream& operator<<(std::ostream& os, const Core<T>& core);
    template<typename U> friend class MapReduce;
protected:    
    Core();

};
//definition des methodes 
#endif
