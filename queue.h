/*==========================
author: Alexnadre El-hajj
desc: header for a link implemented queue


==========================*/

#ifndef queue_H
#define queue_H
#include <iostream>
using namespace std;

class queue
{
public:
	queue();
	queue(const queue& aQueue);
	~queue();
	
	const queue& operator= (const queue& aQueue);
	
	bool enqueue(const int&);
	int dequeue();
	
	bool peek(int&)const;
	bool isEmpty(void) const;

	friend ostream& operator<<(ostream& out, queue& q);

private:
	struct node
	{
		int scanResult;
		node * next;
	};
	node * front;
	node * rear;

};
#endif
