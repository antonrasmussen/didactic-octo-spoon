#include<iostream>
#include<map>
#include <list>
#include <queue>
#include <random>
#include <ctime>
using namespace std;
#include "node.h"

int main()
{   data D;
    node * nptr;
    list<node>nList;
    list<node>::iterator nitr;

    list<data>Solution;
    list<data>::iterator sitr;

    priority_queue<data>PQ;
    ///please note..queues do NOT have iterators.

    default_random_engine gen(time(NULL));
    uniform_int_distribution<int> Sdist(1,5);   ///random number of edges
    uniform_int_distribution<int> Ddist(0,6);   ///random destination
    uniform_int_distribution<int> Cdist(1,10);  ///randomized cost
    char c = 'A';
    char c2;

    int cost;

    ///Create the 'random' list of nodes, each with their own multimap
    for(int i=0; i<5; i++)
    {

        nptr=new node(c);
        int k = Sdist(gen);
        for(int j=0; j<k; j++)
        {   c2=c;
            while(c2==c){
            c2 = 'A'+Ddist(gen);}
            cost = Cdist(gen);
            nptr->add2map(cost, c2);
        }
        nList.push_back(*nptr);
        c++;
    }

    nitr=nList.begin();
    while(nitr!=nList.end())
    {
        nitr->display();
        nitr++;
    }
///******************************implement djikstra's

    int Num;
    char C;
    ///init solution with cost 0 from initial node 'A'
    cout<<"enter starting location"<<endl;
    cin>>C;
    D.i=0;
    D.c=C;
    Solution.push_back(D);
    cout<<"0,start data struct added to solution"<<endl;
    ///find the start node in the node list
    nitr=nList.begin();
    for(int i=0; i<nList.size(); i++)
    {
        if(nitr->getS()==C){i=nList.size()+1;}
        else{nitr++;}
    }
    nitr->display();

    Num = nitr->getNdest();
    ///retrieve all destinations from current source and push to PQ
    for(int i=0; i<Num; i++)
    {
      D=nitr->getnext();
      PQ.push(D);
    }
///testing contents of PQ
///temporary vars
    char target;
    bool found;
    cout<<"entering djikstra's algorithm, nList, Solution and PQ initialized"<<endl;
    ///--------------------------------------begin the algorithm
    while(!PQ.empty())
    {
    target = PQ.top().c;
    cout<<"looking for "<<target<<endl;
    ///check if currently in solution
    found=false;
    sitr=Solution.begin();
    while(sitr!=Solution.end())
    {
        if(target==sitr->c){found = true;
            cout<<"found "<<target<<" in solution already"<<endl;
            PQ.pop(); cout<<"pop and discard"<<endl;}
        sitr++;
    }

    ///if not in solution
    if (!found){
               D=PQ.top();

               ///ADD new 'data' to the solution
               Solution.push_back(D);
               cout<<D.i<<" "<<D.c<<" added to solution"<<endl;
               PQ.pop();
               /// is the char in the solution avail as a source?
               nitr=nList.begin();  ///we still have access to the last struct
               ///added to the solution...D
               found=false;

               while(nitr!=nList.end())
               {
                   if(nitr->getS()==D.c){found=true; break;}
                   nitr++;
               }

               if(found)
               {
                Num = nitr->getNdest();

                    for(int i=0; i<Num; i++)
                    {
                    D=nitr->getnext();
                    D.i=D.i+Solution.back().i;
                    PQ.push(D);
                    }

               }

            }
    }
cout<<" the final solution"<<endl;
    sitr=Solution.begin();
    while(sitr!=Solution.end())
    {
        cout<<sitr->i<<" "<<sitr->c<<endl;
        sitr++;
    }
    return 0;
}
