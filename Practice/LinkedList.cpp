
#include "stdafx.h"
#include "LinkedList.h"

void LinkedList::GenerateDefaultLinkedList()
{
	InsertNodeAtEnd(new Node(10));
	InsertNodeAtEnd(new Node(60));
	InsertNodeAtEnd(new Node(30));
	InsertNodeAtEnd(new Node(13));
	InsertNodeAtEnd(new Node(45));
	InsertNodeAtEnd(new Node(30));
	InsertNodeAtEnd(new Node(5));
	DisplayLinkedList();
}

void LinkedList::InsertNodeAtStart(Node *newNode)
{

	if (start == NULL) {
		start = newNode;
		end = newNode;
		return;
	}

	start->SetPrevious(newNode);
	newNode->SetNext(start);
	start = newNode;

}

void LinkedList::InsertNodeAtEnd(Node *newNode)
{
	// this is first node in the linked list
	if (start == NULL || end == NULL)  {
		end = newNode;
		start = end;
		return;
	}

	//if linked list already has end node
	end->SetNext(newNode);
	newNode->SetPrevious(end);
	end = newNode;
}


void LinkedList::DisplayLinkedList() 
{
	cout << endl << "Linked list = ";

	if (start == NULL || end == NULL) {
		cout << " Empty Linked list";
		return;
	}

	Node *iPtr = start;

	while (iPtr != NULL) {

		cout<< iPtr->GetData() << "," ;
		iPtr = iPtr->GetNext();
	}

	cout << " /EOLL" << endl;
}