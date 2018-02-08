class dog
{
public:
    dog(){}
    dog(string b, string n){breed = b; name = n;}
    ~dog(){cout<<"YELP!"<<endl;}

    string getbreed(){return breed;}
    string getname(){return name;}

    void setbreed(string b){breed = b;}
    void setname(string n){name = n;}

    void display(){cout<<name<<" the famous "<<breed<<endl;}
private:
    string breed;
    string name;


};
