#include<iostream>
#include<random>
#include<ctime>
#include<iomanip>

using namespace std;

/**
 *
 * Prepare an m x n 2D Matrix for storing doubles.
 * @param M an empty 2D Matrix of doubles, sized mRows x nCols
 * @param mRows int number of rows in M
 * @param nCols int number of cols in M
 * @return M the pointer to a new 2D Matrix
 *
 */
double ** initializeMatrix(double ** M, int mRows, int nCols);


/**
 *
 * Print an m x n 2D Matrix to the console.
 * @param A 2D Matrix of doubles, sized mRows x nCols
 * @param mRows int number of rows in A
 * @param nCols int number of cols in A
 *
 */
void printMatrix(string matrixName, double ** M, int mRows, int nCols);


/**
 *
 * Prepare an m x 1 2D Matrix to the console.
 * @param V a 1D Vector of doubles, sized mRows
 * @param mRows int number of rows in V
 * @return V the pointer to a new 1D Vector
 *
 */
double * initializeVector(double * V, int mRows);

double ** makeMatDiagDom(double ** A, int mRows, int nCols);

bool zeroRowCheck(double ** A, int mRows, int nCols);

int main()
{
    int n = 0;
    double ** A;
    double r1,r2;
    bool zeroRow = false;

    default_random_engine * genptr;
    genptr = new default_random_engine(time(NULL));
    uniform_real_distribution<double> r1dist(-100,100);
    uniform_real_distribution<double> r2dist(0,0);

    cout<<"Please enter the size n of the matrix (n x n)? ";
    cin >> n;
    cout << endl;

    ///Create the vectors
    A = initializeMatrix(A, n, n);


    ///Fill in the matrix with random doubles
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            r1 = r1dist(*genptr);
            r2 = r2dist(*genptr);
            A[i][j] = r1;
            //A[n-2][j] = r2; // Testing for a zero row
            //A[n-2][1] = 7; // Testing for ALL zero row
        }
    }



    /**



    */

    printMatrix("Initial Matrix A", A, n, n);

    makeMatDiagDom(A, n, n);

    printMatrix("Diagonalized Matrix A", A, n, n);

    ///A Row reduction algorithm that will enable
    ///us to analyze a system of linear equations.

    //Input: Any matrix, whether or not the matrix
    //is viewed as an augmented matrix for a linear
    //system

    //Cbeck that nonzero rows are above any rows of all zeros
    zeroRow = zeroRowCheck(A, n, n);
    if(zeroRow == true)
        cerr << "Zero row!" << endl;
    else
        cerr << "No zero rows, yo!" << endl;

    ///Needed: Find a way to swap rows

    //Each leading entry of a row is in a column to the right
    //of the leading entry of the row above it

    //All entries in a column below a leading entry are zeros

    ///If a matrix in echelon form satifies the following
    ///additional conditions, then it is in reduced echelon
    ///form (or reduced row echelon form)

    //The leading entry in each nonzero row is 1

    //Each leading 1 is the only nonzero entry in its column


    return 0;
}


/***



***/
double ** initializeMatrix(double ** M, int mRows, int nCols)
{
    /// >> Create the row pointers
    M = new double *[mRows];

    /// Have each of the new pointers point at a vector of size nCols
    for(int i = 0; i < mRows; i++)
    {
        M[i] = new double [nCols];
    }

    return M;

    delete M;
}


/***



***/
double * initializeVector(double * V, int mRows)
{
    /// >> Create the row pointers
    V = new double [mRows];

    return V;

    delete V;
}


/***



***/
void printMatrix(string matrixName, double ** M, int mRows, int nCols)
{
    cout << endl;
    cout << matrixName << ": " << endl;
    cout << endl;

    for(int i = 0; i < mRows; i++)
    {
        for(int j = 0; j < nCols; j++)
        {
            cout << setw(17) << setprecision(8) << M[i][j];
        }
        cout << endl;
    }

    cout << endl;
}


/***



***/
double ** makeMatDiagDom(double ** A, int mRows, int nCols)
{

   double * rowSum;
   rowSum = initializeVector(rowSum, mRows);

   /// Make diagonally dominant
   //    e.g. set the diagonal to 10*the sum of the absolute values in each row
   ///> Compute the sum of the absolute values in each row
   for(int i = 0; i < mRows; i++)
   {
        rowSum[i] = 0;
        for(int j = 0; j < nCols; j++)
        {
            rowSum[i] += abs(A[i][j]);
        }
        /// >> Multiply the sum by 10
        rowSum[i] *= 10;

    }

    ///> Set diagonal equal to that sum in that row
    for(int i = 0; i < mRows; i++)
    {
        for(int j = 0; j < nCols; j++)
        {
            if(i==j)
            {
                A[i][j] = rowSum[i];
            }
        }
    }
}


/***



***/
bool zeroRowCheck(double ** A, int mRows, int nCols)
{
    vector<double> matrixChecker;
    vector<double> zeroMatrix;

    for(int i = 0; i < mRows; i++)
    {
        for(int j = 0; j < nCols; j++)
        {
            matrixChecker.push_back(A[i][j]);
        }
    }

    cout << endl;
    cout << "Matrix Checker:" << endl;
    cout << endl;
    int counter = 0;
    for(int i = 0; i < mRows; i++)
    {
        for(int j = 0; j < nCols; j++)
        {
            //cerr << setw(17) << setprecision(8) << matrixChecker[counter];
            if(matrixChecker[counter] == 0)
            {
                //cerr << setw(17) << setprecision(8) << "  Zero Entry  ";
                zeroMatrix.push_back(matrixChecker[counter]);
                if(zeroMatrix.size() == nCols)
                {
                    //cerr << setw(7) << setprecision(8) << "  Zero Row  ";
                    return true;
                }
            }
            counter++;
        }
        //cerr << endl;
    }
    return false;

}
