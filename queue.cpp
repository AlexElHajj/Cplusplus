/*==========
Author:Alexandre El-hajj
desc: This is thee impelemntation 
for a queue class

=======*/


#include "queue.h"
#include <fstream>
#include <cassert>

/*
int main()
{

queue* s = new queue();

s->enqueue(5);
s->enqueue(6);
s->enqueue(5);
s->enqueue(2);



}
*/

queue::queue():front(NULL), rear(NULL)
{
}

queue::queue(const queue& aQueue):front(NULL), rear(NULL)
{
	if(aQueue.front == NULL) 
	{
		front = rear = NULL;
	}
	else
	{
		//copy first node
		front = new node;
		assert(front != NULL); //check allocation
		front->scanResult = aQueue.front->scanResult;

		//copy the rest of the queue
		node * destNode = front;				//points to the last node in new queue
		node * srcNode = aQueue.front->next;    //points to node in aQueue
		while(srcNode != NULL) //or while (srcNode)
		{
			destNode->next = new node;
			assert(destNode->next != NULL); //check allocation
			destNode = destNode->next;
			destNode->scanResult = srcNode->scanResult;

			srcNode = srcNode->next;
		}
		destNode->next = NULL;

		//set rear pointr
		rear = destNode;
	}	
}

const queue& queue::operator= (const queue& aQueue)
{
	if(this == &aQueue)
		return *this;
	else
	{
		//release dynamically allocated memory held by current object
		node * curr = front;
		while(front)
		{
			curr = front->next;
			delete front;
			front = curr;
		}

		//make a deep copy of aQueue
		if(aQueue.front == NULL) 
		{
			front = rear = NULL;
		}
		else
		{
			//copy first node
			front = new node;
			assert(front != NULL); 
			front->scanResult = aQueue.front->scanResult;

			//copy the rest of the queue
			node * destNode = front;				//points to the last node in new queue
			node * srcNode = aQueue.front->next;    //points to node in aQueue
			while(srcNode != NULL) //or while (srcNode)
			{
				destNode->next = new node;
				assert(destNode->next != NULL); //check allocation
				destNode = destNode->next;
				destNode->scanResult = srcNode->scanResult;

				srcNode = srcNode->next;
			}
			destNode->next = NULL;

			//set rear pointr
			rear = destNode;
		}	
		return *this;
	}
}


queue::~queue()
{
	node * curr = front;
	while(front)
	{
		curr = front->next;
		delete front;
		front = curr;
	}
	front = rear = NULL;
}

bool queue::enqueue(const int& aScan)
{	
	//add to the rear 	
	node * newNode = new node;
	assert(newNode);
	newNode->scanResult = aScan;
	newNode->next = NULL;

	if(rear == NULL)
		front = rear = newNode;
	else
	{
		rear->next = newNode;
		rear = newNode;			//update rear
	}

	return true;
}

int queue::dequeue ()
{
	
	int results;
	//empty stack, has nothing to pop
	if(isEmpty())
		return false;
	else
	{
		node * temp = front;
		if(front == rear) //the only node
			front = rear = NULL;
		else
			front = front->next;

		temp->next = NULL;
		results = temp->scanResult;
		delete temp;
		return results;
	}
}

bool queue::isEmpty () const
{
	return front == NULL;
}

bool queue::peek (int& aScan)const
{
	if(isEmpty())
		return false;
	else
	{
		aScan = front->scanResult;
		return true;
	}
}

ostream& operator<<(ostream& out, queue& q)
{
	queue::node* curr;

	cout << "Data in the queue: " << endl << endl;
	for(curr = q.front; curr; curr = curr->next)
		//we can use << on data object because we overload << in the data class
		cout << '\t' << curr->scanResult << endl;

	return out;
}
