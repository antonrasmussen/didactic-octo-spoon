#include <iostream>
#include <list>
using namespace std;
#include "dog.h"

int main()
{
int n;
dog * dptr;
list<dog>pack;
list<dog>::iterator ditr;

cout<<"how many dogs?"<<endl;
cin>>n;
for(int i=0; i<n; i++)
{
    dptr = new dog("mixed", "none");
    pack.push_back(*dptr);
}

ditr= pack.begin();
while(ditr!=pack.end())
{
    ditr->display();
    ditr++;
}
return 0;}
