/*-- ListLinked.cpp------------------------------------------------------------
   This file implements the ListLinked member functions.
-------------------------------------------------------------------------*/
#include "ListLinked.h"
#include <cstddef>
#include <iostream>
using namespace std;

/* Constructor  */
ListLinked::ListLinked()
{
		first = NULL;
}

/* destructor - clean up memory for remaining nodes in list */
ListLinked::~ListLinked()
{
	Node* temp;
	temp = first;
	while (temp != NULL)
	{
		Node* save = temp;
		temp = temp->next;
		delete save;
	}
}


/* empty */
bool ListLinked::empty()
{
	if (first == NULL)
		return true;
	else
		return false;
}

/* display */
void ListLinked::display()
{
	Node* temp;
	temp = first;
	while (temp != NULL)
	{
		cout << temp->data << ",";
		temp = temp->next;
	}
	cout << endl;
}

/* insert element in position */
void ListLinked::insert(ElementType e, ElementType preptr_value = 0)
{
	Node* newptr = new Node(e);
	if (first == NULL) //insert the very first element
	{
		if (preptr_value == 0)
		{
			newptr->next = NULL;
			first = newptr;
		}
		else
		{
			cout << "Location Error!!";
		}
	}
	else
	{
		if (preptr_value == 0) //insert on the first position when some elements existed
		{
			newptr->next = first;
			first = newptr;
		}
		else //most cases belongs to this situation
		{
			Node* preptr;
			preptr = first;

			bool found = false;

			while (preptr != NULL && found == false)  //runs through each node 
													//until preptr_value is found or end of list is reached
			{
				if (preptr->data == preptr_value)
				{
					found = true;

					newptr->next = preptr->next;  //links new node to next node
					preptr->next = newptr; //links previous node to new node

				}
				else
				{
					preptr = preptr->next;  //traverses through list
				}

			}
				if (found == false)
				{
					cout << "Error: Value of " << preptr_value << " is not found in this list!" << endl;
				}
		}
	}
}

/* Remove specified element from the list at a specific position */
void ListLinked::erase(ElementType preptr_value)
{
	if(first==NULL)
	{
		cout << "List is empty!" << endl;
	}
	else if (preptr_value==0) //delete the first element
	{
		Node* ptr = first;
		first = ptr->next;
		delete(ptr);
	}
	else  //for most cases
	{
		Node* preptr;
		preptr = first;
		bool found = false;
		while (preptr != NULL && found == false)  //runs through each node until preptr_value is found or end of list is reached
		{
			if (preptr->data == preptr_value)
			{
				if (preptr->next == NULL)  //if preptr_value is last node
				{
					found = true;
					cout << "Error: There is no number to erase after " << preptr_value << "." << endl;
				}
				else
				{
					found = true;

					//bypasses and deletes node after preptr
					Node* ptr = preptr->next;
					preptr->next = ptr->next;
					delete(ptr);
				}
			}
			else
			{
				preptr = preptr->next;  //traverses through list
			}
		}
		if (found == false)
		{
			cout << "Error: Value of " << preptr_value << " is not found in this list!" << endl;
		}
	}
}

