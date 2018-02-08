#include <iostream>
using namespace std;


class object
{
    public:
        object(){}
        ~object(){}
        double getx(){return x;}
        double gety(){return y;}
        void setx(double a){x=a;}
        void sety(double a){y=a;}
        void display(){cout<<"("<<x<<", "<<y<<")"<<endl;}
    private:
        double x;
        double y;
};
