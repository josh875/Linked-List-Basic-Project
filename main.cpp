/*-- main.cpp------------------------------------------------------------
   This file is the driver for testing ListLinked
-------------------------------------------------------------------------*/
#include "ListLinked.h"
#include <iostream>
using namespace std;

/* main is the entrypoint into every C++ program */
int main() 
{
	ListLinked* ll = new ListLinked();
	ll->insert(10, 0);
	ll->display();
	ll->insert(20, 10);
	ll->insert(30, 20);
	ll->insert(40, 20);
	ll->insert(50, 30);
	ll->display();
	ll->insert(60, 50);
	ll->insert(70, 5);
	ll->display();
	ll->erase(30);
	ll->display();
	ll->erase(10);
	ll->display();
	ll->erase(50);
	ll->display();

	cin.get();
	return 0;

}