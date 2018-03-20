#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    int rows, cols, mid;
    cout<<"input vals"<<endl;
    cin>>rows>>cols;
    mid = cols/2;
    cout<<"r = "<<rows<<" c = "<<cols<<" Mid = "<<mid<<endl;
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
           A[r][c]=10;
        }

    }
    ///add a low path through the terrain
    for(int i=0; i<cols; i++)
    {
        A[mid][i]=0;
    }

     for(int j=0; j<rows; j++)
    {
        A[j][mid]=0;
    }
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

    system("gnuplot command2.txt");
    return 0;
}
