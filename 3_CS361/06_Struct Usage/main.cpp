#include <iostream>
#include <fstream>
#include "data.h"
using namespace std;

void showDat(dat * dptr);
dat * loadDat(dat * dptr);

int main()
{
   dat Dtest;
   Dtest.id = 11;
   Dtest.dptr=NULL;

   dat * dmain=NULL;
   dat * dmain2=NULL;
   dat * dmain3=NULL;
   dmain = new dat;
   dmain->id=8;
   dmain->dptr = &Dtest;

   showDat(dmain);
   cout<<endl;
   dmain2=loadDat(dmain2);
   showDat(dmain2);
   cout<<endl;

   dmain3=loadDat(dmain);
   showDat(dmain3);
   cout<<endl;



    return 0;
}

void showDat(dat * dptr)
{
    if(dptr!=NULL)
    {
        cout<<dptr->id<<" ";
        if(dptr->dptr!= NULL){showDat(dptr->dptr);}
    }
}

dat* loadDat(dat * dptr)
{   ifstream fin;
    fin.open("data.txt");
    int i;

    dat * lastDat;
    dat * new1;

    fin>>i;
    if(dptr!=NULL){lastDat=dptr;
                   while(lastDat->dptr!=NULL){ lastDat=lastDat->dptr;}
                  }
    while(!fin.eof())
        {
            new1 = new dat;
            new1->id  = i;
            new1->dptr=NULL;
        if(dptr==NULL){dptr=new1; lastDat=new1;}
        else{lastDat->dptr=new1; lastDat=new1;}
        fin>>i;
        }
    fin.close();
    return dptr;
}
