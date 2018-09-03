/*==============
Author: Alexandre El-hajj
desc: this is the implementation to the 
stack_entry class

=================*/


#include "data.h"





/*

int main()
{

stack_entry test;

test.setX(5);
test.setY(3);

cout<<test.getX();
cout<<test.getY();

cout<<"test run";
return 1;
}
*/


stack_entry::stack_entry():x(0), y(0)
{
}

stack_entry::stack_entry(int x, int y) : x(x),y(y)
{

}

stack_entry::stack_entry(const stack_entry& coordPair)
{
	setX(coordPair.x);
	setY(coordPair.y);
	

}

const stack_entry& stack_entry::operator=(const stack_entry *coordPair)
{
	//if self copy, dont do anyhting
	if(this == coordPair)
		return *this;
	//make current object *this a copy passed in coordpair
	else
	{
	
	setX(coordPair->x);
	setY(coordPair->y);
	return *this;
	}

}

void stack_entry::setX(int x)
{
	this->x = x;
}

void stack_entry::setY(int y)
{
        this->y = y;
}


int stack_entry::getX(void) const
{
 return x;
}

int stack_entry::getY(void) const
{
 return y;
}

ostream& operator<<(ostream& out, const stack_entry& coordPair)
{
	out 	<<  coordPair.x
		<<   coordPair.y;
	return out;
}
