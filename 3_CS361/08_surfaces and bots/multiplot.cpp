#include<iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    fstream fout;
    fout.open("data1.txt",ios::out);

    int k;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            k=i+j;
            fout<<k<<" ";
        }
    fout<<endl;
    }

    fout.close();
    system("gnuplot command.txt");
    return 0;
}
