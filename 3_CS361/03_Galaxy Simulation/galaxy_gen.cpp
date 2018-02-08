#include <iostream>
#include <fstream>
#include <list>
#include <random>
#include <ctime>
#include <cmath>

using namespace std;
#include "star.h"
int main()
{
    fstream fout;
    fout.open("galaxy_data.txt",ios::out);

    list<star>galaxy;
    list<star>::iterator gitr;

    default_random_engine gen;
    uniform_real_distribution<double> Adist(0,6.28);
    uniform_real_distribution<double> Rdist(0,16);


    star * sptr;
    double a, b, r;
    int num;
    cout<<"How many stars? "; cin>>num;

    for(int i=0; i<num; i++)
    {
        a=Adist(gen);
        b=Adist(gen);
        r=Rdist(gen);
        sptr=new star(i,a,b,r);

        galaxy.push_back(*sptr);
    }


    gitr=galaxy.begin();
    while(gitr!=galaxy.end())
    {
        gitr->display();
        r=gitr->getradius();
        a=gitr->getalpha();
        b=gitr->getbeta();
        fout<<a<<" "<<b<<" "<<r<<endl;
        gitr++;
    }

    fout.close();

    system("gnuplot command.txt");
    return 0;
}
