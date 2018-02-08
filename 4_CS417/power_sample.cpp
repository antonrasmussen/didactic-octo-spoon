/// -4 10 7 5

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double A[2][2];
    A[0][0]=-4.0;
    A[0][1]=10.0;
    A[1][0]=7.0;
    A[1][1]=5.0;

    double x[2], xnew[2];
    x[0]=1;
    x[1]=1;
    xnew[0]=0.0;
    xnew[1]=0.0;

    double rho=0.0;
    double rhoOld=100.0;
    int i=0;
    while(fabs(rhoOld-rho)>.001)
    {   if(i>0){rhoOld=rho;}
        xnew[0]=(A[0][0]*x[0]) +(A[0][1]*x[1]);
        xnew[1]=(A[1][0]*x[0]) +(A[1][1]*x[1]);

        if(fabs(xnew[1])>fabs(xnew[0])){rho=xnew[1];}
        else {rho=xnew[0];}
        x[0]=xnew[0]/rho;
        x[1]=xnew[1]/rho;


        cout<<"Rho: "<<rho<<"   x["<<x[0]<<", "<<x[1]<<"]"<<endl;
    i++;
    }
    cout<<"Solution"<<endl;
    cout<<"after "<<i<<" iterations"<<endl;
      cout<<"Rho: "<<rho<<"   x["<<x[0]<<", "<<x[1]<<"]"<<endl;
    return 0;
}
