#include <iostream>
#include <random>
#include <ctime>
#include <list>
#include "object.h"
using namespace std;

int main()
{
    list<object> myObjects;
    list<object>::iterator oitr;   ///iterator to use inside list
    object * optr;
    double x, y;
    double dx = 1.5;
    double dy=0.0;
    y = 0;
    x = 0;
    ///this is using the C++ 11 stl random library
    default_random_engine * gptr;
    gptr= new default_random_engine (time(NULL));
    normal_distribution<double> ydist(0,.5);

    for(int i=0; i<15; i++)
    {
        x=i*dx;
        dy=ydist(*gptr);
        y =y +dy;

    ///making an new object and setting x and y
    optr=new object;
    optr->setx(x);
    optr->sety(y);
    ///adding the new object to the list
    myObjects.push_back(*optr);
    }

    cout<<myObjects.size()<<" objects stored"<<endl;
    oitr=myObjects.begin();
    while(oitr!=myObjects.end())
    {
        oitr->display();
        oitr++;
    }
    return 0;

}
