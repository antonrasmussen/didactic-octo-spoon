#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <string>

#include "magazineCollection.h"

using namespace std;

///Randomized test of LL functionality
//const int MIN = -10;
//const int MAX = 10;
//int randomInt(int min=MIN, int max=MAX);
//MagazineCollection generateRandomCollection(int n);

MagazineCollection getMusicMagCollection(int n);

int main(int argc, char** argv)
{

    ///Randomized test of LL functionality
//    int seed        = 0; // Seed for random number generation
//    int toGenerate  = 0; // Number of nodes to generate
//
//    // If a seed was passed from the command line,
//    // parse it. Otherwise default to ctime
//    if( argc >= 2 ) {
//         seed = atoi( argv[1] );
//    }
//    else {
//        seed = time( NULL );
//    }
//     // If a node  count was passed from the command line,
//    // parse it. Otherwise default to 10
//    if( argc >= 3 ) {
//       toGenerate = atoi( argv[2] );
//    }
//    else {
//        toGenerate = 10;
//    }
//     srand( seed );

     /// Create a Magazine Collection
     MagazineCollection modernDrummerMags; // Just ModernDrummer Magazine

     string magazineName, issueDate;
     int uniqueID = 0;
     cout << "Your current collection is: " << modernDrummerMags << endl;
     cout << endl;
     cout << "Which magazine would you like to add to the collection (Magazine Name, issueDate(MM/YYYY)?: ";
     cin >> magazineName >> issueDate;

     /// Convert input to uniqueID
    if((magazineName == "MD") && (issueDate == "02/1984"))
    {
        uniqueID = 76035;
        modernDrummerMags.appendMagazine(uniqueID);
        cout << endl;
        cout << "After adding in your new mag, your current collection is: " << modernDrummerMags << endl;
    }
    else
    {
        cout << endl;
        cout << "Sorry, we don't have that magazine in our inventory!" << endl;
    }





     //MagazineCollection drumMags = getMusicMagCollection(); // Just Drum! Magazine

     //cout << drumMagazineMags;

     //MagazineCollection drumheadMags = getMusicMagCollection(); // Just Drumhead Magazine

     //cout << drumheadMags;

     //MagazineCollection drumsetMagazines = modernDrummerMags;


     //drumsetMagazines.appendCollection() > for later implementation




    ///Randomized test of LL functionality
    //MagazineCollection randomInts = generateRandomCollection(toGenerate); // Randomized


    ///Randomized test of LL functionality
//    cout << randomInts;
//
//    MagazineCollection randomCopy = randomInts;
//
//    randomCopy.appendMagazine(337);
//
//    cout << randomCopy;
//    cout << randomInts;

    return 0;
}

MagazineCollection getMusicMagCollection(int n)
{
    MagazineCollection ll;
    // Create a LL of 1 node
    ll.appendMagazine(n);

    return ll;

}



///Randomized test of LL functionality
//int randomInt( int min, int max )
//{
//
//    // Generate a number in the range 0-1
//    double x = (1.0 * rand() / RAND_MAX);
//     // Compute scaling factor
//    int s = max - min + 1;
//     // Multiply x by the scaling factor and shift
//    // by adding min
//    return ( x * s ) + min;
//}
//
//MagazineCollection generateRandomCollection(int n)
//{
//    MagazineCollection LL;
//     // Generate a Linked List (LL) of 10 Nodes
//    for( int i = 0; i < n; i++ ){
//        ll.appendMagazine( randomInt() );
//    }
//     return ll;
//
//}
