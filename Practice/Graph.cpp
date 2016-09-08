
#include "stdafx.h"
#include "Graph.h"
#include <stack>

void Graph::BFS(int s)
{
    bool *v = new bool[N]; // for N vertices tracking
    for (int i = 0; i < N; i++) {
        v[i] = false; // node is not yet visited.
    }
    cout << "BFS = ";

    list<int> q;
    list<int>::iterator itr;
    q.push_back(s);

    while (!q.empty()) {
        int newV = q.front(); //get front data but don't remove item from q
        q.pop_front(); //remove item from q
        cout << newV << ", ";
        v[newV] = true;

        //Get the adjacent of s
        for (itr = g[newV].begin(); itr != g[newV].end(); itr++) {
            //for each next vertex check if it is visited or not
            if (!v[*itr]) {// not visited
                q.push_back(*itr);
            }
        }
    }
    cout << endl << "....Done";
}

void Graph::DFSUtil(int s, bool *v) {

    cout << s << ",";
    v[s] = true;

    list<int>::iterator itr;
    for (itr = g[s].begin(); itr != g[s].end(); itr++) {
        if (!v[*itr])
            DFSUtil(*itr, v);
    }
}

void Graph::DFS_Rec(int s) {

    cout << endl<< "DFS rec version.."<<endl;
    bool *v = new bool[N];
    for (int i = 0; i < N; i++) {
        v[i] = false;
    }

    DFSUtil(s, v);
}

void Graph::DFS_Stack(int s) {

    bool *visited = new bool[N];

    for (int i = 0; i < N; i++)
        visited[i] = false;

    cout << "DFS (stack version)" << endl;

    stack<int> st;
    st.push(s);

    list<int>::iterator itr;
    
    while (!st.empty()) {
        s = st.top();
        st.pop();


        cout << s << ", ";
        visited[s] = true;

        for (itr = g[s].begin(); itr != g[s].end(); itr++) {
            if (!visited[*itr])
                st.push(*itr);
        }
    }
}