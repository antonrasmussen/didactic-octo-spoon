#include <iostream>
#include <random>
#include <iomanip>
#include <ctime>
using namespace std;

void showmat(int N, double **A);
int main()
{

    default_random_engine gen(time(NULL));

int row, col, N, numr;
double val;
cout<<"how many rows and columns?"; cin>>N;

///how many nonzeros to add to a row is numdist
normal_distribution<double> numdist(2,1);
///coldist is their destination columns 0 to N
uniform_int_distribution<int> coldist(0,N-1);
///valdist is the random value being added to the target location
uniform_real_distribution<double> valdist(-100,100);
double **A;
A = new double* [N];
for(int r=0; r<N; r++)
{
    A[r]=new double[N];
}

for(int r=0; r<N; r++)
{
    for(int c=0; c<N; c++)
    {
        if(r!=c)A[r][c]=0.0;
        else A[r][c]=1.0;
    }
}
///now we begin adding non zeros.
double sum=0.0;
for(int r=0; r<N; r++)
{
    numr=(int)numdist(gen);

    for(int c=0; c<numr; c++)
    {
       col=coldist(gen);
       val = valdist(gen);
       sum=sum+val;
       A[r][col]=A[r][col]+val;
    }
    A[r][r]=A[r][r]+2.0*sum;
    sum=0.0;
}


showmat(N,A);

return 0;
}

void showmat(int N, double **A)
    {
        for(int r=0; r<N; r++)
        {
            for(int c=0; c<N; c++)
            {
                cout<<setw(8)<<A[r][c];
            }
            cout<<endl;
        }
    }



