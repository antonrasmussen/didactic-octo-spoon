class alpha
{
public:
    alpha(){}
    alpha(char s, int i, int j, int k, int l)
        {
        S= s;
        N[0]=i;
        N[1]=j;
        N[2]=k;
        N[3]=l;
        }
    ~alpha(){}
    void setS(char s){S=s;}
    void setN(int n[4]){for(int i=0; i<4; i++)N[i]=n[i];}

    char getS(){return S;}
    void getN(int n[4]){for(int i=0; i<4; i++)n[i]=N[i]; }

    void display()
    {
        cout<<S<<" N["<<N[0]<<", "<<N[1]<<", "<<N[2]
            <<", "<<N[3]<<"]"<<endl;
    }
private:
    char S;
    int N[4];
};