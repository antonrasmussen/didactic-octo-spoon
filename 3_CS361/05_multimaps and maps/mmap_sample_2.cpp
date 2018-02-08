
#include <iostream>
#include <map>
#include <fstream>
using namespace std;
#include "alpha.h"

int main ()
{
 multimap<char,alpha> mymultimap;
 multimap<char,alpha>::iterator mit;

 fstream fin;
 fin.open("mmap_data_2.txt",ios::in);

 alpha * aptr;
 char F, S;
 int N[4];
 fin>>F;
 while(!fin.eof())
 {
 fin>>S;
 for(int i=0; i<4; i++)
    fin>>N[i];
  aptr=new alpha(S, N[0], N[1], N[2], N[3]);
  // first insert function version (single parameter):
  mymultimap.insert ( pair<char,alpha>(F,*aptr) );
  fin>>F;
 }

 fin.close();
 mit = mymultimap.begin();
 while(mit!=mymultimap.end())
 {
     cout<<(*mit).first<<" maps to "; mit->second.display();
     mit++;
 }
 cout<<"what first? ";
 cin>>F;
 mit=mymultimap.begin();
 while(mit!=mymultimap.end())
 {
     if(mit->first==F)
    {
    cout<<(*mit).first<<" maps to "; mit->second.display();
    }
 mit++;
 }
 return 0;
}
