#include "Counter.h"

Counter::Counter()
{
	count = 0;
	
}

void Counter::increment() 
{
	++count;
}

int Counter::getC() const 
{
	return count;
}

Counter::~Counter()
{
}