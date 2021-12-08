#ifndef CORE
#define CORE


#include <vector>
#include <iostream>

template<typename T> class Core{
private:
    int id;
    static int nbinst;
    int degradation;
public:
    Core();
    virtual ~Core();
    static int getCount(); 
    static void incrnb();   


};
//definition des methodes 
#endif
