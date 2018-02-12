#include<iostream>
#include<iomanip>

using namespace std;

int main()
{


//    double ** matrixA;
//
//    /// Create the matrix
//    matrixA = new double *[3];
//
//    /// Have each of the new pointers point at a row of size n
//    for(int i=0; i<3; i++)
//    {
//        matrixA[i] = new double [3];
//    }

    /// Fill in the matrix
    double matrixA[3][3] = {{100.0, 0.2, 0.1}, {0.3, 100.0, 0.32}, {-0.7, 0.03, 100.0}};

    /// Print out the matrix

    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            cout << setw(15) << setprecision(10) << matrixA[i][j];
        }
        cout << endl; //end each row
    }

    /// Multiplying matrix A and x_sol and storing in array b_soln.


    ///> Step 1: Multiply b += A * x


    ///> Step 2: Compute sum of each row in b



    return 0;
}



