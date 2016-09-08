/**

	Contains all classes and members related to graph problems

**/

#pragma once
#include "stdafx.h"

/*
Graph is representated by simply list
*/

class Graph {

    int N;//total number of vertices in the graph
    list<int> *g; //graph array. = list<int> a[10]; array of list

private:
    void DFSUtil(int s, bool *v);

public:
    Graph(int n = -1) {
        if (n <= 0) return;
        N = n;
        g = new list<int>[N];
    }

    void addEdge(int a, int b) {
        g[a].push_back(b);
    }

    void BFS(int s);

    //DFS using stack implimentation
    void DFS_Stack(int s);

    //DFS using recursiving implementation
    void DFS_Rec(int s);

};