#include <iostream>
#include "PriorityQueue.h"
using namespace std;

void display(int x)
{
	cout << x << "\t";
}

int main()
{
	typedef vector<int>::iterator itr;
	itr f, r;
	PriorityQueue <int> q(3);
	q.add(5);
	q.add(1);
	q.add(8);
	q.add(1);
	q.add(-8);
	q.add(9);
	q.add(0);

	q.traverse(display);
	cout << endl;

	q.poll();
	q.poll();
	q.poll();

	q.traverse(display);
	cout << endl;

	q.remove(15);
	q.remove(1);

	q.traverse(display);
	cout << endl;

	system("pause");
	return 0;
}