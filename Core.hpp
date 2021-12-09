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
    Core();
    virtual ~Core();
    static int getCount(); 
    static void incrnb(); 
    Core<T> map(T(*func(T x))); 
   // friend std::ostream& operator<<(std::ostream& os, const Core<T>& core);


};
//definition des methodes 
#endif
