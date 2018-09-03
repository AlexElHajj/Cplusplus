/*=========================
Author:Alexandre El-hajj
Date: July 17 2017
Desc: header file for a rover class
=========================*/



#ifndef rover_H
#define rover_H
#include <iostream>
#include "stack.h"
#include "queue.h"

using namespace std;

class rover
{
public:
	rover();
	rover(int Id, int maxResult);
	~rover();

	void deploy(); //deploys rover on new mission
	void move(int x, int y);//moves rover to new coordinates 
	void corescan();//performs corescan and stores results
	void dock();//this method returns to base and reports 
	void IDdisplay();

	int getCoordinates(int x , int y );
	

private:
	int ID;//rover identification
	int xC;// rover x-coordinate
	int yC;//rover y-coordinate
	queue scanR;
	stack recall;

};	
#endif
