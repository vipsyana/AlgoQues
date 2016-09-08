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

public: 

    LinkedList() {
        start = NULL;
        end = NULL;
		GenerateDefaultLinkedList();
    }

	void DeleteNode(Node *currentNode);
	void Clear();
	void GenerateDefaultLinkedList(void);
	void InsertNodeAtStart(Node *newNode);
	void InsertNodeAtEnd(Node *newNode);
	void DisplayLinkedList(void);

	void DeleteDuplicate(void);
};
