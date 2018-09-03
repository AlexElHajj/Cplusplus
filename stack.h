/*======================
Author: Alexandre El-hajj
desc: this is the header for a linked stack

=====================*/

#ifndef stack_h
#define stack_h

#include "data.h"
#include <iostream>
using namespace std;


class stack
{
public:
	stack();
	stack(const stack& aStack);
	~stack();

	const stack& operator= (const stack& aStack);
	
	bool push(const stack_entry*);
	bool pop();

	stack_entry* peek()const;
	bool isEmpty(void)const;

	friend ostream& operator<<(ostream& out, stack& stk);

	private:
	struct node
	{
		stack_entry coordPair;
		node * next;
	};

	node * top;

};
#endif
