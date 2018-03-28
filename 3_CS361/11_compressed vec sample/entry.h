class entry
{
public:
    entry(){row=0; col=0; val=0;}

    entry(int r, int c, double v){row=r; col=c; val=v;}
    ~entry(){}

    double getval(){return val;}
    int getcol(){return col;}

    void display(){cout<<"("<<row<<", "<<col<<", "<<val<<")";}
private:
    int row;
    int col;
    double val;
};

class rvec
{
public:
    rvec(){}
    ~rvec(){}
    list<entry>::iterator getbegin(){return myRow.begin();}
    list<entry>::iterator getend(){return myRow.end();}
    void addEntry(entry * eptr)
    {
        myRow.push_back(*eptr);
    }

    void display()
    {
        ritr = myRow.begin();
        cout<<"<";
        while(ritr!=myRow.end())
        {
            ritr->display();

            ritr++;
            if(ritr!=myRow.end()) cout<<", ";
        }
        cout<<">"<<endl;
    }

    void sum(rvec r1, rvec r2)
    {
        int c1, c2;
        double v1, v2;
        entry * eptr;
        list<entry>::iterator r1itr;
        list<entry>::iterator r2itr;
        r1itr=r1.getbegin();
        r2itr=r2.getbegin();

        while( (r1itr!=r1.getend())||(r2itr!=r2.getend()) )
        {
            c1=r1itr->getcol();
            c2=r2itr->getcol();
            v1=r1itr->getval();
            v2=r2itr->getval();
            if(c1==c2)
            {
                eptr=new entry(0,c1,v1+v2);
                myRow.push_back(*eptr);
                r1itr++;
                r2itr++;

            }
            else if(c1<c2)
            {
                eptr=new entry(0,c1,v1);
                myRow.push_back(*eptr);
                r1itr++;
            }
            else
            {
                eptr=new entry(0,c2,v2);
                myRow.push_back(*eptr);
                r2itr++;
            }
        }
        if(r1itr==r1.getend())
        {
            while(r2itr!=r2.getend())
                {c2=r2itr->getcol();
                 v2=r2itr->getval();
                 eptr=new entry(0,c2,v2);
                 myRow.push_back(*eptr);
                }
        }
        else
            {
                while(r1itr!=r1.getend())
                {c1=r1itr->getcol();
                 v1=r1itr->getval();
                 eptr=new entry(0,c1,v1);
                 myRow.push_back(*eptr);
                }

            }
    }
private:
    list<entry> myRow;
    list<entry>::iterator ritr;
};
