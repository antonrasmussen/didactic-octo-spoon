#include <iostream>
#include <string>

using namespace std;


int main()
{

    int a = 1;
    int b = 2;

    cout << endl;
    cout << endl;
    cout << "a = " << a << " and b = " << b << " so let's swap them!" << endl;

    /// Swap without using a temp variable
    a = a + b;
    b = a - b;
    a = a - b;

    cout << endl;
    cout << endl;
    cout << "After swapping . . . " << endl;
    cout << endl;
    cout << "a = " << a << " and b = " << b << " so did it work?" << endl;

    /// Alas, not sure how this would be done
    /// (outside of some kind of template, like the one below)
    /// for non-numeric types.

    /**

    template void swap ( T& a, T& b )
    {
        T c(a);
        a = b;
        b = c;
    }

    */


    return 0;

}
