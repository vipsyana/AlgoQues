// Practice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graph.h"
#include <queue>

class greater {
public:
    bool operator()(int a, int b) {
        return a > b;
    }
};

typedef bool(*CompareFun)(int, int);

bool greatFunction(int a, int b) {
    return a > b;
}
//understanding max heap data structure
void max_heap() {
    //priority_queue<int, vector<int>, greater>q; 
    priority_queue<int, vector<int>, CompareFun>q(greatFunction);
    q.push(5);    
    q.push(2);
    q.push(15);
    q.push(5);
    q.push(55);

    cout << "Priority content = ";
    while (!q.empty()) {
        cout << q.top() <<  ", ";
        q.pop();
    }
}

int main()
{
    max_heap();
    list<int> mylist;

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2); 
    g.addEdge(2, 3);
    g.addEdge(3, 0);    
    g.addEdge(3, 2);

    g.BFS(3);
    g.DFS_Stack(3);
    g.DFS_Rec(3);

    return 0;
}

