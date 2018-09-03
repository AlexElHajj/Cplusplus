/*==============
Author: Alexandre El-hajj
desc: implementation of 
linked based stack

============*/

#include "stack.h"
#include <fstream>
#include <cassert>


/*
int main()
{

stack* s = new stack();


s->push(stack_entry(4,4));
s->push(stack_entry(3,2));
cout << "after push -- "<<*s;




cout<<"test22";
return 1;
}
*/

stack::stack():top(NULL)
{
}

stack::stack(const stack& aStack)
{
	if(aStack.top == NULL) 
		top = NULL;
	else
	{
		//copy first node
		top = new node;
		assert(top != NULL); //check allocation
		top->coordPair = aStack.top->coordPair;

		//copy the rest of the list
		node * destNode = top;				//points to the last node in new stack
		node * srcNode = aStack.top->next;  //points to node in aStack
		while(srcNode != NULL) //or while (srcNode)
		{
			destNode->next = new node;
			assert(destNode->next != NULL); //check allocation
			destNode = destNode->next;
			destNode->coordPair = srcNode->coordPair;

			srcNode = srcNode->next;
		}
		destNode->next = NULL;
	}		
	
}

const stack& stack::operator= (const stack& aStack)
{
        if(this == &aStack)
                return *this;
        else
        {
                //release dynamically allocated memory held by current object
                node * curr = top;
                while(top)
                {
                        curr = top->next;
                        delete top;
                        top = curr;
                }

                //make *this a deep copy of "aStack"
                if(!aStack.top)
                        top = NULL;
                else
                {
                        //copy the first node
                        top = new node;
                        assert(top != NULL);
                        top->coordPair = aStack.top->coordPair;

                        //copy the rest of the stack
                        node * destNode = top;
                        node * srcNode = aStack.top->next;

                        while(srcNode)
                        {
                                destNode->next = new node;
                                assert(destNode->next);
                                destNode = destNode->next;
                                destNode->coordPair = srcNode->coordPair;

                                srcNode = srcNode->next;
                        }
                        destNode->next = NULL;
                }

                return *this;
        }
}



stack::~stack()
{
    node * curr = top;
	while(top)
	{
		curr = top->next;
		delete top;
		top = curr;
	}
	top = NULL;
}



bool stack::push(const stack_entry *entry)
{
	//create new node
	node * newNode = new node;
	newNode->coordPair = entry;
	newNode->next = NULL;

	//add on top
	newNode->next = top;
	top = newNode;

	return true;
}

bool stack::pop()
{
	//empty stack, has nothing to pop
	node * temp;
	if(isEmpty())
		return false;
	else
	{
		//stack_entry = top->coordPair;
		temp = top;
		top = top->next;
		delete temp;
		return true;
	}
}

bool stack::isEmpty () const
{
	return top==NULL;
}

stack_entry* stack::peek() const
{
	
	
	if(isEmpty())
		return NULL;
	else
	{
		return &top->coordPair;
		
	}
}

ostream& operator<<(ostream& out, stack& stk)
{
	stack::node* curr;

	cout << "Data in the stack: " << endl << endl;
	for(curr = stk.top; curr; curr = curr->next)
		//we can use << on data object because we overload << in the data class
		cout << '\t' << curr->coordPair << endl;

	return out;
}

