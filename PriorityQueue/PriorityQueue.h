#ifndef  PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <vector>
using namespace std;

template <class T>
class PriorityQueue
{
private:
	vector<T> vec;
	int vecIndex;
	bool parentInvariant(const int);
	bool childInvariant(const int);
	void swap(const int&, const int&);
	int checkEquality(const int&, const int&) const;
	int traverse(const T&) const;

public:
	PriorityQueue(int size = 1);
	bool isEmpty() const;
	bool isFull() const;
	void getFront(T&) const;
	int getCapacity() const;
	int getSize() const;
	void add(const T);
	T poll();
	bool remove(const T&);
	void traverse(void(*pf)(T)) const;

};
#endif