/**

Contains all classes and members related to linkedlist problems

**/
#pragma once
#include "stdafx.h"

class Node {
	Node *next;
	Node *previous;
	int data;

public:

	Node() {
		next = NULL;
		previous = NULL;
		data = 0;
	}

	Node(int d) {
		next = NULL;
		previous = NULL;
		data = d;
	}

	void SetNext(Node *t) {
		next = t;
	}

	Node* GetNext() {
		return next;
	}

	Node* GetPrevious() {
		return previous;
	}

	void SetPrevious(Node *t) {
		previous = t;
	}

	void SetNULL() {
		next = NULL;
		previous = NULL;
	}

	void SetData(int d) {
		data = d;
	}
	
	int GetData() {
		return data;
	}
};

class LinkedList {
    Node *start;
    Node *end;
	void GenerateDefaultLinkedList(void);
	void Init();



public: 

    LinkedList() {
        start = NULL;
        end = NULL;
		GenerateDefaultLinkedList();
    }

	//returns valid pointer of kth node from start.
	Node* GetKthNode(int k);

	void DeleteNode(Node *currentNode);
	void Clear();

	void InsertNodeAtStart(Node *newNode);
	void InsertNodeAtEnd(Node *newNode);
	void DisplayLinkedList(void);

	void DeleteDuplicate(void);
	
	//reverse existing linked list till
	void Reverse();

	//reverses linked list from start to end pointer and changes pointer value at end
	void Reverse(Node *st, Node *end);

	void ReverseKNodes(int k);
};
