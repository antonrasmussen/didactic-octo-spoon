#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
using namespace std;
int main()
{
int s; ///number of rows
int t; ///number of columns
double r; ///a random double

/// default_random_engine gen;
default_random_engine * genptr;
genptr = new default_random_engine(time(NULL));
uniform_real_distribution<double> rdist(-100,100);

double ** A;
cout<<"how many rows?"<<endl;
cin>>s;
cout<<"how many columns?"<<endl;
cin>>t;

///create the vector
A=new double *[s];
///have each of the new pointers point at a vector of size t
for(int i=0; i<s; i++)
{
    A[i]=new double [t];
}

///fill in the matrix
for(int i=0; i<s; i++)
{
    for(int j=0; j<t; j++)
    {
        r=rdist(*genptr);
        A[i][j]=r;
    }
}

///display the contents
for(int i=0; i<s; i++)
{
    for(int j=0; j<t; j++)
         ///{cout<<setw(12)<<"A["<<i<<"]["<<j<<"] = "<<A[i][j];}
    {cout<<setw(8)<<setprecision(4)<<A[i][j];}
    cout<<endl;
}


return 0;}
