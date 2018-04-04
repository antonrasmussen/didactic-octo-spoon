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

#pragma once
#include <iostream>
#include <ios>
#include <iomanip>
#include <cfloat>
#include <cmath>

using namespace std;

class LinearSystem
{
	friend ostream& operator<<(ostream& output, const LinearSystem& ls);

private:
	bool solved;
	bool IsInitialized();
	bool Convergence(double *x1, double *x2, double e, int size);
	bool IsValidNumber(double x);

public:
	double *coef[3]; /* a[], b[], c[] */
	double *solution;
	double *d;
	int size;

	LinearSystem();
	LinearSystem(int size);
	~LinearSystem();
	
	void Init(int size);
	bool IsSolved();
	int ESOR(double t, double w, double e, int maxIter);


};

