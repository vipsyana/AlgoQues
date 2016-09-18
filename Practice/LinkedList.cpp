
#include "stdafx.h"
#include "LinkedList.h"

void LinkedList::Init() {
	Clear();
	GenerateDefaultLinkedList();
}

void LinkedList::GenerateDefaultLinkedList()
{
	InsertNodeAtEnd(new Node(10));
	InsertNodeAtEnd(new Node(60));
	InsertNodeAtEnd(new Node(30));
	InsertNodeAtEnd(new Node(13));
	InsertNodeAtEnd(new Node(45));
	InsertNodeAtEnd(new Node(30));
	InsertNodeAtEnd(new Node(5));
	InsertNodeAtEnd(new Node(23));
	InsertNodeAtEnd(new Node(45));
	InsertNodeAtEnd(new Node(11));
	InsertNodeAtEnd(new Node(88));
	InsertNodeAtEnd(new Node(79));
	InsertNodeAtEnd(new Node(2));
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

void LinkedList::DeleteNode(Node *t) {

	if (t != NULL) {
		t->SetNULL();
		delete t;
	}
	t = NULL;
}

//node starts from 1st
Node* LinkedList::GetKthNode(int k) {

	int count = 0;
	Node *i = start;
	while (i != NULL) {
		count++;
		if (count == k)
			return i;

		i = i->GetNext();
	}
}
//This function deletes aall nodes of the linked list
void LinkedList::Clear() {
	if (start !=NULL && end != NULL) { 
		Node *t = start;

		while (start != NULL) {
			t = start->GetNext();
			DeleteNode(start);
			start = t;
		}
		start = NULL;
		end = NULL;
	} 
}

/*
Delete the duplicate node from the linked list. 

input: Empty list, 1 node, 3 node, 
*/
void LinkedList::DeleteDuplicate() {

	//Clear existing linked list
	Clear();

	//Create example
	InsertNodeAtEnd(new Node(30));
	InsertNodeAtEnd(new Node(13));
	InsertNodeAtEnd(new Node(30));
	InsertNodeAtEnd(new Node(5));
	InsertNodeAtEnd(new Node(5));
	InsertNodeAtEnd(new Node(30));

	DisplayLinkedList();

	/*
	Logic 1: Comparing every pointer with every other pointer value. O(n^2)
	Logic 2: Using hash table, to store already visited data and it found delete current pointer. Space O(n) and running time is O(n)
	*/

	//Logic 1
	cout << endl << " LinkedList::DeleteDuplicate()  ";
	Node *i=start, *j;

	if (i->GetNext() == NULL) {
		DisplayLinkedList();
		return; 
	}

	Node *prev=NULL;
	for (; i != NULL;i=i->GetNext()) {
		prev = i;
		for (j = i->GetNext(); j != NULL; j = j->GetNext()) {
			
			if (i->GetData() == j->GetData()) {
				//Delete j

				Node *t = j->GetNext();
				DeleteNode(j);
				prev->SetNext(t);
				j = prev;
			}
			prev = j;
		}
	}

	DisplayLinkedList();
}

void LinkedList::Reverse() {

	Init();

	cout << endl << "Before : LinkedList::Reverse ";
	DisplayLinkedList();

	Reverse(start, end);
	Node *t = start;
	start = end;
	end = start;

	//Following is traditional way of reversing linked list
	//Node *prev = NULL, *i = start,*t=NULL;

	//while (i != NULL) {		
	//	t = i->GetNext();
	//	i->SetNext(prev);
	//	prev = i;
	//	i = t;
	//}
	//start = prev;

	cout << endl << "After: LinkedList::Reverse ";
	DisplayLinkedList();
}

void LinkedList::Reverse(Node *st,  Node *end) {
	
	Node*t1=st, *t2=end->GetNext(), *t3=NULL,*tend= end->GetNext();

	do {
		t3 = t1->GetNext();
		t1->SetNext(t2);
		t2 = t1;
		t1 = t3;
	}while (t1!= tend);
}


void LinkedList::ReverseKNodes(int k=2) {

	Init();
	cout << endl << "Before:: LinkedList::ReverseKNodes ";
	DisplayLinkedList();
	int count = 0;

	Node *i = start,*t=start,*prevSt=NULL;
	Node* prev = NULL;
	while (i != NULL && t!=NULL) {
		
		count++;
		if (count == k) {

			if (t == start)
				start = i;
			
			Node *nt = i->GetNext();
			Reverse(t, i);

			if (prevSt != NULL)
				prevSt->SetNext(i);
			prevSt = t;
			
			i = t;
			
			//This is ASSERT
			if (t->GetNext() != nt)
			{
				//something went wrong in the reverse logic.
			}

			t = nt; // set new start
		
			count = 0;			
			
			if (i == NULL) 
				break;
			
		}

		prev = i;
		i = i->GetNext();
	}
	
	end = prev;

	cout << endl << "After:: LinkedList::ReverseKNodes ";
	DisplayLinkedList();
}