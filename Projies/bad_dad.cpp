
/**

This program is inspired by the program this young buck made:
https://softwareengineering.stackexchange.com/questions/97785/my-dad-is-impatient-with-the-pace-of-my-learning-to-program-what-do-i-do

*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    /// Have a user enter a word.
    /// Each letter will have a value associated with it based on its place in the alphabet.
    /// Print out the sum of the word's total value (the sum of each letter's value)

    char mychars[] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int myints[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};

    multimap<int,char> myMap;
    for(int i=0; i<26; i++)
    {
        myMap.insert(pair<int,char>(myints[i], mychars[i]));
    }
    // show map content:
    for (map<int,char>::iterator it=myMap.begin(); it!=myMap.end(); ++it)
    {
        cout << (*it).first << " => " << (*it).second << '\n';
    }

    string userWord = "";
    cout << endl;
    cout << "Enter a word: ";
    cin >> userWord;
    cout << endl;

    vector<char> stringToCharList;

    int wordSum = 0;

    cout << endl;
    cout << "My Entered String:" << endl;
    cout << endl;
    for(int i = 0; i < userWord.length(); i++)
    {
        stringToCharList.push_back(userWord[i]);
        cout << stringToCharList[i];
        for (map<int,char>::iterator it=myMap.begin(); it!=myMap.end(); ++it)
        {
            if(stringToCharList[i] == (*it).second)
            {
                wordSum += (*it).first;
            }
        }
    }
    cout << endl;
    cout << endl;
    cout << "Your word total is: " << wordSum << endl;

    return 0;
}
