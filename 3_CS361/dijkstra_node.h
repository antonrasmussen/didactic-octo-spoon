
struct data
{
    int i;
    char c;
    bool operator < (const data& rtside) const
    {
        if(i<rtside.i){return false;}
        return true;
    }
};


class node
{public:

node(){}
node(char c){S=c;}

void add2map(int i, char c){
    mydest.insert(pair<int,char>(i,c) );
}
void display(){

    cout<<"Source: "<<S<<endl;
    myitr=mydest.begin();
    while(myitr!=mydest.end())
    {
        cout<<" cost: "<<(*myitr).first<<" to "
                        <<(*myitr).second<<endl;
        myitr++;
    }
}
char getS(){return S;}

data getnext(){data * dptr;
               myitr=mydest.begin();
               dptr= new data;
               dptr->i=(*myitr).first;
               dptr->c=(*myitr).second;
               mydest.erase(myitr);
               return *dptr;}

int getNdest(){return mydest.size();}

private:
char S;
multimap<int,char>mydest;
multimap<int,char>::iterator myitr;


};
