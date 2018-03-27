#ifndef ANIMAL_H
#define ANIMAL_H


class Animal {
public:
  virtual string eats() {return "???";}
  string name() {return "Animal";}
};          

class Herbivore: public Animal {
public:
   virtual string eats() {return "plants";}
   string name() {return "Herbivore";}
};

class Ruminant: public Herbivore {
public:
   virtual string eats() {return "grass";}
   string name() {return "Ruminant";}
};       

class Carnivore: public Animal {
public:
   virtual string eats() {return "meat";}
   string name() {return "Carnivore";}
}; 

void show (string s1, string s2) {
          cout << s1 << " " << s2 << endl;
}          

#endif // ANIMAL_H