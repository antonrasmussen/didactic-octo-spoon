#include <iostream>
#include <string>
using namespace std;

#include "dog_LL.h"

int main()
{
dog * Pack = NULL;
dog * dptr;

int num;
cout<<"How many dogs?"<<endl;
cin>>num;
for(int i=0; i<num; i++)
{
    dptr = new dog("mixed breed", "no name", i+1);
    if(Pack==NULL){Pack = dptr; dptr = NULL;}
    else {dptr->setnext(Pack); Pack = dptr; dptr=NULL;}
}
Pack->showpack();
delete dptr;

return 0;
}
