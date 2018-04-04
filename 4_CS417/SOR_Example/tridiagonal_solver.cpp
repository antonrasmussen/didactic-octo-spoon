// Developed by Michalis Zervos - All rights reserved
// http://michal.is/

/*
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR AND/OR COPYRIGHT HOLDER BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#define MAXITER 5000

#include <iostream>
#include "LinearSystem.h"
using namespace std;

int selection(int *, double *);
int readSize();
bool readData(LinearSystem *t);
void autoCreateExample1(LinearSystem *t);
void autoCreateExample2(LinearSystem *t, int n, double a);

int main(int argc, char *argv[])
{
	LinearSystem ls;
	double e = 0.0000005;
	double t, w, tb, wb;
	int n = 10;
	double a = 0.1;
	int iter;
	int minIter = MAXITER;

	// Print menu and read input
	int sel = selection(&n, &a);
	if (sel == 1)
	{
		int size = readSize();
		ls.Init(size);
		readData(&ls);
	}
	else
	{
		if (sel == 2)
			autoCreateExample1(&ls);
		else if (sel == 3)
			autoCreateExample2(&ls, n, a);
		else if (sel == 4)
			autoCreateExample2(&ls, n, a); 
	}


	for (t = 0.1; t <= 1.9; t += 0.2)
	{
		for (w = 0.1; w <= 1.9; w += 0.2)
		{
			// ESOR
			iter = ls.ESOR(t, w, e, MAXITER);
			if (iter > 0 && iter < minIter)
			{				
				minIter = iter;
				tb = t;
				wb = w;
			}
			cout << "t = " << t << ". w = " << w << ". Iterations = " << iter << endl;
		}
	}

	// If solution found
	if (minIter != MAXITER)
	{
		ls.ESOR(tb, wb, e, MAXITER);
		cout << endl;
		if (ls.size <= 10)
		{
			// If it's not very large, print everything
			cout << ls << endl;
		}
		else
		{
			// Otherwise just print the solution
			cout << "X = (";
			for (int i = 0; i < ls.size - 1; i++)
				cout << ls.solution[i] << ", ";
			cout << ls.solution[ls.size-1] << ")" << endl;
		}

		cout << endl << "tb = " << tb << ". wb = " << wb << ". Min iterations = " << minIter << endl;
	}
	else
		cout << "No solution found in " << MAXITER << " iterations." << endl;


	return 0;
}


int selection(int *n, double *a)
{
	int sel;

	do
	{
		cout << "Select: " << endl;
		cout << "1) Input data manually" << endl;
		cout << "2) Automatic (example1)" << endl;
		cout << "3) Automatic (example2) with n = 10, a = 0.1" << endl;
		cout << "4) Automatic (example2) with custom n, a" << endl;
		cin >> sel;
	} while(sel < 1 || sel > 4);

	if (sel == 4)
	{
		do {
			cout << "Select n ( 10, 100, 1000 ): ";
			cin >> *n;
		} while (*n != 10 && *n != 100 && *n != 1000);

		do
		{
			cout << "Select a ( 0.1, 0.5, 1 ): ";
			cin >> *a;
		} while (*a != 0.1 && *a != 0.5 && *a != 1);
		
	}
	return sel;
}


int readSize()
{
	int n;

	cout << "Enter size: ";
	cin >> n;

	return n;
}


bool readData(LinearSystem *t)
{
	int n = t->size;

	cout << "Enter: b1 c1" << endl;
	cin >> t->coef[1][0] >> t->coef[2][0];

	for (int i = 1; i < n-1; i++)
	{
		cout << "Enter: a" << i+1 << " b" << i+1 << " c" << i+1 << endl;
		cin >> t->coef[0][i] >> t->coef[1][i] >> t->coef[2][i];
	}

	cout << "Enter: a" << n << " b" << n << endl;
	cin >> t->coef[0][n-1] >> t->coef[1][n-1];
	
	cout << "Enter ";
	for (int i = 0; i < n; i++)
		cout << "d" << i << " ";
	cout << endl;

	for (int i = 0; i < n; i++)
		cin >> t->d[i];

	return true;
}

void autoCreateExample1(LinearSystem *t)
{
	/*------------ Example 1 ------------*/
	double coefs[3][5] = {	
	{0, -3, 1, -1, -4},
	{7, 9, 3, 10, 6},
	{-3, 1, -1, -4, 0}
	};
	double d[5] = {10, -11, 3, -15, 10};

	
	t->Init(5);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 5; j++)
			t->coef[i][j] = coefs[i][j];

	for (int i = 0; i < 5; i++)
			t->d[i] = d[i];
	


}

void autoCreateExample2(LinearSystem *t, int size, double a)
{
	// ------------- Example 2 --------------
	t->Init(size);
	
	for (int i = 0; i < size; i++)
	{
		t->coef[1][i] = 4;
		t->coef[0][i] = -a;
		t->coef[2][i] = -a;
	}
	t->d[0] = 4-a; t->d[size-1] = 4-a;
	for (int i = 1; i <= size-2; i++)
		t->d[i] = 4-2*a;
}
