class star
{

public:
    star(){}
    star(int i, double a, double b, double r)
        {id = i; alpha=a; beta=b; radius=r;}
    ~star(){}
    void display()
        {cout<<"#"<<id<<" ("<<alpha<<", "<<beta<<", "<<radius<<")"<<endl;}

    int getid(){return id;}
    double getalpha(){return alpha;}
    double getbeta(){return beta;}
    double getradius(){return radius;}
private:
    int id;
    double alpha;
    double beta;
    double radius;

    };
