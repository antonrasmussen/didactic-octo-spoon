class dog
{
public:
    dog(){next = NULL;}
    dog(string b, string n, int i){breed = b; name = n; next = NULL; id = i;}
    ~dog(){cout<<"YELP!"<<endl;}

    string getbreed(){return breed;}
    string getname(){return name;}
    dog * getnext(){return next;}

    void setbreed(string b){breed = b;}
    void setname(string n){name = n;}
    void setnext(dog * n){next = n;}

    void display(){cout<<"#"<<id<<" "<<name<<" the famous "<<breed<<endl;}
    void showpack(){display();
                   if(next!=NULL){next->showpack();}
                   }
private:
    string breed;
    string name;
    int id;
    dog * next;


};
