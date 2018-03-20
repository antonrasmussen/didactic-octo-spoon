class eggcart
{
public:
    eggcart(){
            for(int i=0; i<12; i++){myeggs.push_back(true);}
             }
    ~eggcart(){}

    void whoops(default_random_engine * genptr)
        {
            uniform_int_distribution<int> wdist(0,11);
            int r=wdist(*genptr);
            myeggs[r]=false;
        }

    void display(){
                  for(int i=0; i<12; i++)
                    {
                    if(myeggs[i]){cout<<"egg#"<<i<<" is a good egg"<<endl;}
                    else{cout<<"Oh NO!! a cracked egg"<<endl;}
                    }
                  }


private:
vector<bool>myeggs;
};

class shipment
{
    public:
    shipment(){}
    shipment(int N)
        {
            for(int i=0; i<N; i++)
            {
            eggcart * new1;
            new1 = new eggcart;
            mycarts.push_back(*new1);
            }

        }
    void display()
    {
        citr=mycarts.begin();
        while(citr!=mycarts.end())
        {
            citr->display();
            citr++;
        }
    }
void OHMY(default_random_engine * genptr)
        {

            uniform_int_distribution<int> cdist(0,mycarts.size());
            int r=cdist(*genptr);

            for(int i=0; i<r; i++)
            {
                int s = cdist(*genptr);
                citr=mycarts.begin();
                for(int i=0; i<s; i++){citr++;}
                citr->whoops(genptr);
            }
        }
private:

    list<eggcart>mycarts;
    list<eggcart>::iterator citr;
};
