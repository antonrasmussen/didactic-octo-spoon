#include <iostream>
#include <fstream>
#include <cstdlib>
#include <random>
#include <ctime>
using namespace std;

int main()
{
    default_random_engine gen(time(NULL));
    normal_distribution<double> ndist(0,3);
    normal_distribution<double> n2dist(10,3);
    uniform_int_distribution<int> hnumdist(5,10);

    int rows, cols, mid, hills;
    int hx,hy;
    cout<<"input vals"<<endl;
    cin>>rows>>cols;
    mid=rows/2;
    cout<<"r = "<<rows<<" c = "<<cols<< endl;
    double ** A;
    A =new double *[rows];

    for(int i=0; i<rows; i++)
    {
        A[i]=new double[cols];
    }

    ///initial plane
    for(int r=0; r<rows; r++)
    {
        for(int c=0; c<cols; c++)
        {
           A[r][c]=r+(cols-c)+ndist(gen);
        }

    }
    uniform_int_distribution<int>hxdist(0,cols-1);
    uniform_int_distribution<int> hydist(0,rows-1);
    uniform_int_distribution<int> dice(1,6);
    hills=hnumdist(gen);
    cout<<"number of hills: "<<hills<<endl;
    int d;
    double fac;
    for(int h=0; h<hills; h++)
    {           d=dice(gen);
                if(d==1){fac=-10;}
                else if(d>4){fac=3;}
                else {fac=1;}
                cout<<"Hill factor: "<<fac<<endl;
        hx=hxdist(gen);
        hy=hydist(gen);
        for(int i=hx; i<hx+(cols/5); i++ )
        {cout<<" i= "<<i<<": ";

            for(int j=hy; j<hy+(rows/5); j++)
            {
                if((j<rows)&&(i<cols))
                {cout<<j<<" ";

                A[i][j]=A[i][j]+fac*n2dist(gen);}

            }
            cout<<endl;
        }

    }


 /*   ///add a low path through the terrain
  for(int i=0; i<cols; i++)
    {
        A[mid][i]=A[mid][i]+n2dist(gen);
    }

     for(int j=0; j<rows; j++)
    {
        A[j][mid]=0;
    }*/
    ofstream fout;
    fout.open("terrain.txt");

    for(int r=0; r<rows; r++)
    {
        for(int c=0; c<cols; c++)
        {
           fout<<A[r][c]<<" ";
        }
        fout<<endl;
    }
    fout.close();

    system("gnuplot command.txt");
    return 0;
}
