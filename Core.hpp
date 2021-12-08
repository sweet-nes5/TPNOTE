#ifndef CORE
#define CORE


#include <vector>
#include <iostream>

template<class T> class Core{
private:
    int id;
    static int nbinst;
    int degradation;
public:
    Core();
    virtual ~Core();
    static int getCount();    


};
//definition des methodes 
#endif
