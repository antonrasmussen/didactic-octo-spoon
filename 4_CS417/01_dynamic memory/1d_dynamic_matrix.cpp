#include <iostream>
using namespace std;
int main()
{
    ///this is the same as if you knew s=8
    ///and did:   double A[8];

int s; ///size
double * A;
cout<<"how long is the vector?"<<endl;
cin>>s;
///create the vector
A=new double [s];
///fill the vector
for(int i=0; i<s; i++)
{
    A[i]=i+10;
}
///display the contents
for(int i=0; i<s; i++)
{
    cout<<"A["<<i<<"] = "<<A[i]<<endl;
}


return 0;}
