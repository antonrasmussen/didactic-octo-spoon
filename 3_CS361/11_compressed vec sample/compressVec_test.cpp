#include <iostream>
#include <list>
using namespace std;
#include "entry.h"

int main()
{
    entry * eptr;
    eptr = new entry(0,2, 3);
    ///eptr->display();

    rvec row1;
    row1.addEntry(eptr);
    eptr = new entry(0,3,-1);
    row1.addEntry(eptr);
    row1.display();

    rvec row2;
    eptr=new entry(0,1,1);
    row2.addEntry(eptr);
    eptr=new entry(0,3,2);
    row2.addEntry(eptr);
    row2.display();
    cout<<"---------------"<<endl;
    rvec row3;
    row3.sum(row1,row2);
    row3.display();
    return 0;
}
