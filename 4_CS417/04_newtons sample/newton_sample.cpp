#include <iostream>
#include <cmath>
using namespace std;

double f(double x);
double ff(double x);
int main()
{
    ///fx = x^2 - 5
    ///ff = 2x
    double xold, xnew;
    xold = -50000;
    double tol = .00001;
    bool cont = true;
    int it=0;
    while(cont)
    {
       xnew = xold - (f(xold)/ff(xold));
       cout<<"New x = "<<xnew<<endl;
       if(abs(xnew-xold)<tol){cont = false;}
       xold = xnew;
       it++;
    }
    cout<<"final solution: "<<xnew<<" in "<<it<<" iterations"<<endl;
}

double f(double x)
{
    x = pow(x,3)-(7*pow(x,2))-(70*x)+400;
    return x;
}
double ff(double x)
{
    x = (3*pow(x,2))-(14*x)-70;
    return x;
}
