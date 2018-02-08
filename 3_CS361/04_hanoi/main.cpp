#include <iostream>
#include <vector>
#include "hanoi.h"
using namespace std;
void showgame(vector<post>game);
void moveDisk(vector<post>&game);
int main()
{


   ///test the game board
   post * pptr;
   vector<post> game;

       pptr = new post();
       pptr->init(5);
       game.push_back(*pptr);
       delete pptr;
       pptr=new post();
       game.push_back(*pptr);
       delete pptr;
       pptr=new post();
       game.push_back(*pptr);

       showgame(game);
       moveDisk(game);
       showgame(game);

    return 0;
}
void showgame(vector<post>game)
{
    for(int i=0; i<3; i++)
    {
        cout<<"  Post # "<<i<<endl;
        game[i].display();
        cout<<"---------------"<<endl;
    }
}
void moveDisk(vector<post>&game)
{   int F, T;
    disk D;
    cout<<"move disk from what post? "; cin>>F;
    cout<<"move disk to what post? "; cin>>T;
    D=game[F].topDisk();
    game[T].addDisk(D);
    game[F].subDisk();
}
