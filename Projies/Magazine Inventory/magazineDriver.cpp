#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <string>

#include "magazineCollection.h"

using namespace std;


const int MIN = -10;
const int MAX = 10;

int randomInt(int min=MIN, int max=MAX);

MagazineCollection generateList(int n);

int main(int argc, char** argv)
{
    int seed        = 0; // Seed for random number generation
    int toGenerate  = 0; // Number of nodes to generate

    // If a seed was passed from the command line,
    // parse it. Otherwise default to ctime
    if( argc >= 2 ) {
         seed = atoi( argv[1] );
    }
    else {
        seed = time( NULL );
    }
     // If a node  count was passed from the command line,
    // parse it. Otherwise default to 10
    if( argc >= 3 ) {
       toGenerate = atoi( argv[2] );
    }
    else {
        toGenerate = 10;
    }
     srand( seed );

     // Create a Magazine Collection
    MagazineCollection randomInts = generateList(toGenerate);

    cout << randomInts;

    MagazineCollection randomCopy = randomInts;

    randomCopy.appendMagazine(337);

    cout << randomCopy;
    cout << randomInts;

    return 0;
}

int randomInt( int min, int max )
{

    // Generate a number in the range 0-1
    double x = (1.0 * rand() / RAND_MAX);
     // Compute scaling factor
    int s = max - min + 1;
     // Multiply x by the scaling factor and shift
    // by adding min
    return ( x * s ) + min;
}

MagazineCollection generateList(int n)
{
    MagazineCollection ll;
     // Generate a Linked List (LL) of 10 Nodes
    for( int i = 0; i < n; i++ ){
        ll.appendMagazine( randomInt() );
    }
     return ll;

}
