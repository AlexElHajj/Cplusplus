/*=================
Author: Alexandre El-hajj
Desc: This is the header file for stack_entry dataType

================*/

#ifndef data_h
#define data_h
#include <iostream>
using namespace std;
class stack_entry
{

public:
	stack_entry();
	stack_entry(int x, int y);
	stack_entry(const stack_entry& coordPair); //copy constructor: "make current object a copy of "coordPait""
//	~stack_entry(); not needed no allocated

	int getX(void) const;
	int getY(void) const;

	void setX(int x);
	void setY(int y);

	const stack_entry& operator=(const stack_entry *coordPair); //overload assignment oper
	friend ostream& operator<<(ostream& out, const stack_entry& coordPait );

	private:
		int x;
		int y;




};



#endif	


