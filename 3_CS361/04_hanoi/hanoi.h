#include <iostream>
#include <stack>
using namespace std;

class disk
{
public:
    disk(){}
    disk(int s){Val=s;}
    ~disk(){}

    int getVal(){return Val;}
    void setVal(int s){Val=s;}
    void display(){cout<<"Disk# "<<Val<<endl;}
private:
    int Val;
};
class post
{
public:
    post(){}
    ~post(){}
    void display()
        {
           while(!contents.empty())
           {
               contents.top().display();
               ///move all the contents to temp stack
               temp.push(contents.top());
               contents.pop();
           }
           while(!temp.empty())
           {

                contents.push(temp.top());
                temp.pop();
           }
        }
        void addDisk(disk d){contents.push(d);}
        disk topDisk(){return contents.top();}
        void subDisk(){contents.pop();}
    void init(int i)
    {
        if(contents.empty())
        { while(i!=0)
           {dptr = new disk(i);
           contents.push(*dptr);
           i--;
           }
        }
    }
private:
    disk* dptr;
    stack<disk>contents;
    stack<disk>temp;



};
