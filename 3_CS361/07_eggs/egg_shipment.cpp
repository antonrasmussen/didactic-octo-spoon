#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <list>
using namespace std;
#include "egg.h"

int main()
{
    default_random_engine * genptr;
    genptr = new default_random_engine(time(NULL));
/*
    eggcart* eptr;
    eptr=new eggcart;

    eptr->display();
    cout<<"dropping the egg carton"<<endl;
    eptr->whoops(genptr);
    eptr->display();
    */
    shipment S(4);
    S.OHMY(genptr);

    S.display();
    return 0;
}
