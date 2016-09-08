#pragma once
#include "stdafx.h"

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
		cout << q.top() << ", ";
		q.pop();
	}
}