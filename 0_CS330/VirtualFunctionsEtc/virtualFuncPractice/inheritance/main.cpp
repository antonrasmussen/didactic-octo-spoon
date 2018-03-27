#include <iostream>
#include <string>
using namespace std;
#include "Animal.h"

int main()
{
	cout  << "Hello" << endl;
	
	Animal a, *paa, *pah, *par;
	Herbivore h, *phh;
	Ruminant r;
	paa = &a; phh = &h; pah = &h; par = &r;
 
	show(a.name(), a.eats());      // AHRC ?pgm
	show(paa->name(), paa->eats()); // AHRC ?pgm
	show(h.name(), h.eats());        // AHRC ?pgm
	show(phh->name(), phh->eats()); // AHRC ?pgm
	show(pah->name(), pah->eats()); // AHRC ?pgm
	show(par->name(), par->eats()); //AHRC ?pgm
	
	return 0;
}
