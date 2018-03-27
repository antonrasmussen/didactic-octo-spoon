#ifndef COUNTER_H
#define COUNTER_H

class Counter
{
protected:
	int count;
	
public:
	Counter();
	void increment();
	int getC() const;
	
	
	~Counter();

};

class HoursCounter: public Counter {
public: 
	void increment(){
		count = (count + 1) % 24;
	}
};

#endif // COUNTER_H
