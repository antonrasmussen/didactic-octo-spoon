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

#include "LinearSystem.h"

LinearSystem::LinearSystem()
{
	this->size = -1;
}

LinearSystem::LinearSystem(int n)
{
	Init(n);
}


LinearSystem::~LinearSystem()
{
	delete this->solution;
	delete this->d;
	for (int i = 0; i < 3; i++)
	{
		delete this->coef[i];
	}
}

void LinearSystem::Init(int n)
{
	if (this->size == -1 && n > 0)
	{
		this->size = n;
		this->solution = new double[n];
		this->d = new double[n];
		for (int i = 0; i < 3; i++)
		{
			this->coef[i] = new double[n];
		}
		this->solved = false;
	}
}

bool LinearSystem::IsInitialized()
{
	return (this->size != -1);
}

int LinearSystem::ESOR(double t, double w, double e, int maxIter)
{
	if (!IsInitialized())
		return false;

	int itCount = 0;
	int i;
	int n = this->size;
	double *xOld = new double[n];
	double *xCur = new double[n];
	double s1 = 0, s2 = 0, s3 = 0;
	
	this->solved = false;

	for (i = 0; i < n; i++)
		xOld[i] = this->d[i];

	while (itCount <= maxIter)
	{
		for (i = 0; i < n; i++)
		{
			s1 = s2 = s3 = 0;

			// a[i] = coef[0][i]
			// b[i] = coef[1][i] (elements on diagonal)
			// c[i] = coef[2][i]

			if (i > 0)
			{
				s1 = -coef[0][i]/coef[1][i]*xCur[i-1];
				s2 = -coef[0][i]/coef[1][i]*xOld[i-1];
			}

			if (i < n-1)
			{
				s3 = -coef[2][i]/coef[1][i]*xOld[i+1];
			}

			// SOR
			//xCur[i] = (1 - w) * xOld[i] + w * (s1 + s3 + (double)d[i]/coef[1][i]);
			
			// ESOR
			xCur[i] = (1 - t) * xOld[i] + w * s1 + (t - w) * s2 + t * s3 + t*d[i]/coef[1][i];
		}

		itCount++;
		if (Convergence(xCur, xOld, e, n))
		{
			this->solved = true;
			break;
		}

		for (i = 0; i < n; i++)
			xOld[i] = xCur[i];
	}

	if (this->solved)
	{
		for (i = 0; i < n; i++)
		{
			if (!IsValidNumber(xCur[i]))
			{
				//cout << "Couldn't determine solution" << endl;
				this->solved = false;
				break;
			}
		}

		if (this->solved)
		{
			for (i = 0; i < n; i++)
			{
				this->solution[i] = xCur[i];
			}
		}
	}

	delete xOld;
	delete xCur;

	if (solved)
		return itCount;
	else
		return -1;
}

bool LinearSystem::Convergence(double *x1, double *x2, double e, int size)
{
	// If at least one of the differences is larger than e, then there is no convergence
	for (int i = 0; i < size; i++)
	{
		if ( abs(x1[i] - x2[i]) >= e )
			return false;
	}

	return true;
}

bool LinearSystem::IsSolved()
{
	return this->solved;
}

// Format output
ostream& operator<<(ostream& output, const LinearSystem& ls)
{
	for (int i = 0; i < ls.size; i++)
	{
		for (int j = 0; j < ls.size; j++)
		{
			if (j == i - 1)
				output << setw(7) << ls.coef[0][i];
			else if (j == i)
				output << setw(7) << ls.coef[1][i];
			else if (j == i + 1)
				output << setw(7) << ls.coef[2][i];
			else 
				output << setw(7) << "0";
		}
		output << setw(7) << "|" << setw(7) << ls.d[i] << endl;
	}

	if (ls.solved)
	{
		output << "Solution:" << endl;
		output << "X = [ ";
		for (int i = 0; i < ls.size-1; i++)
		{
			output << ls.solution[i] << ", ";
		}
		output << ls.solution[ls.size-1] << " ]";
	}

	return output;
}


bool LinearSystem::IsValidNumber(double x)
{
	return ( (x == x) && x <= DBL_MAX && x >= -DBL_MAX);
}
