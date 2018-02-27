#include<iostream>
#include<string>

/** https://codegolf.stackexchange.com/questions/125117/diagonal-alphabet */

using namespace std;

void blankOutputter(int i);

int main()
{
    char alpha [26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    for(int i = 0; i < 26; i++)
    {
        cout << alpha[i] << endl;
        cout << " ";
        blankOutputter(i);
    }
    return 0;
}


void blankOutputter(int i)
{
    char blank = ' ';

    for(int j = 0; j < i; j++)
    {
        cout << blank;
    }
}
