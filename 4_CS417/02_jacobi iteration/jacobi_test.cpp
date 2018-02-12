#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream fout;
    fout.open("data.txt",ios::out);
    double b[2]={11,13};
    double xold[2]={1,1};
    double xnew[2]={0,0};
    double Dinv[2]={0.5,0.142857};
    double R[2][2]={ {0, 1.0},{5.0, 0}};
    double sum;
    for(int k=0; k<25; k++)
        {
        for(int i=0; i<2; i++)
        {
            sum = 0.0;
            sum = sum + R[i][0]*xold[0]+R[i][1]*xold[1];
            xnew[i]=Dinv[i]*(b[i]-sum);
        }
        cout<<"("<<xnew[0]<<", "<<xnew[1]<<")"<<endl;
        xold[0]=xnew[0];
        xold[1]=xnew[1];
        fout<<xold[0]<<endl;
        }
    fout.close();
    return 0;
}
