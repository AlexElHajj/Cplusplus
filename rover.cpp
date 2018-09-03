/*==========================
Author: Alexandre El-hajj
description: this is the rover class
=============================*/


#include "rover.h"
#include "scandata.h"
#include <iostream>

using namespace std;

/*================
private: 
	

==============*/

/*
int main(){

rover* rovers;
rovers= new rover;

rovers->deploy();
rovers->move(7,7);
rovers->move(2,7);
rovers->move(2,2);
rovers->move(1,1);
rovers->corescan();

rovers->dock();
cout<<"test run";

return 1;
}
*/
rover::rover(){

}

rover::rover(int Id, int maxResult)
{
	this->ID = Id;
}

rover::~rover(){
}

/*================
func: IDdisplay
desc:provides the rovers self identification
type: void
================*/
void rover::IDdisplay()
{
 cout<< "Rover (ID"<< ID << ")";
}

/*================
func: rover
desc:deploys rover on new 
mission
type: void
================*/

void rover::deploy()
{
	IDdisplay();
 	cout<<"deploying " <<endl;
	IDdisplay();
	cout<< "ready for use" <<endl;

	
	stack_entry* location = new stack_entry;	
	location->setX(0);
	location->setY(0);	
	recall.push(location);
	delete location;

}

/*==============
func: move
des: moves rover to new 
coordinates
type:void
vars: int x, int y
x =xCoordinate
y =yCoordinate
=========*/
void rover::move(int x, int y)
{
	

	IDdisplay();
	
	cout<<" moving to location " <<x <<"," <<y <<endl;
	stack_entry* location = new stack_entry;
	
	location->setX(x);
	location->setY(y);
	xC = x;
	yC = y;	

	recall.push(location);

	delete location;	


}


/*=============
func: corescan
desc: this performs a corescan
and stores results
type:void
============*/

void rover::corescan()
{


int scan;
scan = scandata::getScandata(xC,yC);
scanR.enqueue(scan);

}


/*=================
func: dock
desc:return rover to base
and report back
type:void
=================*/

void rover::dock()
{

	int xout;
	int yout;

	IDdisplay();
	cout<<" returning to base... "<<endl;

	while(!recall.isEmpty())
	{
		xout = recall.peek()->getX();
		yout = recall.peek()->getY();
		IDdisplay();
		cout<<"moving to "<<xout<< ","<<yout<<endl;
		recall.pop();
	}
	IDdisplay();
	cout << "docked."<<endl;


	IDdisplay();
	cout<< " at base, sending results" <<endl;
	while (!scanR.isEmpty()){

	IDdisplay();
	cout<< "result: " <<scanR.dequeue() << endl;

	}
	cout<<"Mission complete, powering off"<<endl;

}



