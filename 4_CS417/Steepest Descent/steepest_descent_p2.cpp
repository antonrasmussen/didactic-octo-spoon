#include <iostream>
#include <cmath>
using namespace std;
    ///partial derivative in X
double HprimeX(double x, double y);
    ///partial derivative in Y
double HprimeY(double x, double y);
    ///original equation (total function)
double HofXY(double x, double y);

int main()
{   double x, y, xnew, ynew, h, a, b;
    ///initial guess (4, -4)
    x=4.0;
    y=-4.0;

    ///xnew = x - h*HprimeX(x,y)
    ///ynew = y - h*HprimeY(x,y)

    a = HprimeX(x,y);
    b = HprimeY(x,y);
    cout<<"a = "<<a<<" and b = "<<b<<endl;

    ///and xnew =  4+4h
    ///and ynew = -6+4h
    ///substituting in H to get G(x,y)
    ///G = 136h^2 - 52h -8
    ///assume we solved for h= .191

    h=0.191;

    for(int i=0; i<10; i++)
    {
    xnew = x-(h*a);
    ynew = y-(h*b);
    cout<<"("<<xnew<<", "<<ynew<<")"<<endl;
    x=xnew;
    y=ynew;
    a = HprimeX(x,y);
    b = HprimeY(x,y);
    }
    return 0;
}

double HprimeX(double x, double y)
{
    double ans=0.0;
    ///2x-2y-4
    ans = (2*x)+(2*y)-4;
    return ans;
}

double HprimeY(double x, double y)
{
    ///  2x+4y+2
    double ans=0.0;
    ans = (2*x)+(4*y)+2;
    return ans;
}
double HofXY(double x, double y)
{
    ///x^2 - 4x + 2xy + 2y^2 + 2y + 14
    double ans=0.0;
    ans = pow(x,2.0)-(4*x)+(2*x*y)+2*(pow(y,2.0))+(2*y)+14;
    return ans;
}
