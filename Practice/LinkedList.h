/**

Contains all classes and members related to linkedlist problems

**/
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

class Node {
    Node *f;
    int data;
};

class LinkedList {
    Node *start;
    Node *end;

public: 

    LinkedList() {
        start = NULL;
        end = NULL;
    }

    LinkedList(Node *t) {
        start = t;
        end = t;
    }

    void GenerateDefaultLinkedList();
    void InsertNodeAtStart();
    void InsertNodeAtEnd();

};
