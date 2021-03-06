// Practice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graph.h"
#include "DataStructures.h"
#include "LinkedList.h"

void RunDS() {

	max_heap();
}

void RunGraph() {
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 0);
	g.addEdge(3, 2);

	g.BFS(3);
	g.DFS_Stack(3);
	g.DFS_Rec(3);
}

void RunLinkedList() {
	LinkedList list;
	list.DeleteDuplicate();
	list.Reverse();
	list.ReverseKNodes(5);
	
	list.RemoveLoop2();
}

int main()
{
	//RunGraph();
	
	RunLinkedList();

	cout << endl << endl << endl << "....... Press any key to exit program";
	_getch();
	return 0;
}

