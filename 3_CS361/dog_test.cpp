#include <iostream>
#include <string>
using namespace std;

#include "dog.h"

int main()
{
dog D1;
D1.setname("rover");
D1.setbreed("chihuahua");
D1.display();


dog * dptr;
dptr = new dog("German Shepherd", "Tosca");
dptr->display();
delete dptr;

return 0;
}
