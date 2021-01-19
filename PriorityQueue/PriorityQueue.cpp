#include "PriorityQueue.h"

template<class T>
PriorityQueue<T>::PriorityQueue(int size):vecIndex(0)
{
	vec.resize(size);
}

template<class T>
bool PriorityQueue<T>::isEmpty() const
{
	return !vec.size();
}

template <class T>
bool PriorityQueue<T>::isFull() const
{
	return 0;
}

template <class T>
void PriorityQueue<T>::getFront(T &front) const
{
	//at has throw exception
	front = vec.at(0);
}
template <class T>
int PriorityQueue<T>::getCapacity() const
{
	return vec.capacity();
}

template <class T>
int PriorityQueue<T>::getSize() const
{
	return vec.size();
}

template <class T>
void PriorityQueue<T>::add(const T newItem)
{
	if (vecIndex == vec.capacity())
		vec.resize(vec.size() + 2);

	vec[vecIndex] = newItem;
	parentInvariant(vecIndex);
	childInvariant(vecIndex);

	vecIndex++;
}

template <class T>
T PriorityQueue<T>::poll()
{
	if (isEmpty()) return NULL;
	swap(0, vecIndex - 1);
	vec.erase(vec.end() - 1);
	vecIndex--;
	childInvariant(0);
	return vec.front();
}

template <class T>
bool PriorityQueue<T>::remove(const T &delItem)
{
	int delIndex = traverse(delItem);
	if (delIndex > -1)
	{
		swap(delIndex, vecIndex - 1);
		vec.erase(vec.end() - 1);
		vecIndex--;
		parentInvariant(delIndex);
		childInvariant(delIndex);
		return true;
	}
	return false;
}

template <class T>
void PriorityQueue<T>::traverse(void(*pf)(T)) const
{
	for (auto itr = vec.begin(); itr != vec.end(); itr++)
		(*pf)(*itr);
}



//private methods
//return true if parent valid
template <class T>
bool PriorityQueue<T>::parentInvariant(const int index)
{
	//index has no parent
	if (index == 0) return true;

	int parent = (index - 1) / 2;
	if (vec[parent] > vec[index])
	{
		swap(parent, index);
		parentInvariant(parent);
	}
	
	return true;
}

//return true if child valid
template <class T>
bool PriorityQueue<T>::childInvariant(const int index)
{
	//index has no child
	if (index == vec.size() - 1) return true;
	
	int left = (index * 2) + 1;
	int right = (index * 2) + 2;
	int smallestIndex = checkEquality(left, right);

	//index has no child
	if (smallestIndex == -1) return true;
	
	//left == right
	else if (smallestIndex == 0)
	{
		swap(left, index);
		childInvariant(left);
	}
	
	//smaller node swap with new node
	else if (vec[smallestIndex] < vec[index])
	{
		swap(smallestIndex, index);
		childInvariant(smallestIndex);
	}

	return true;
}

template <class T>
void PriorityQueue<T>::swap(const int &i , const int &j)
{
	if (i >= 0 && j >= 0 && i != j)
	{
		T temp = vec[i];
		vec[i] = vec[j];
		vec[j] = temp;
	}
}

template <class T>
int PriorityQueue<T>::checkEquality(const int &l, const int &r) const
{
	if (r > vec.size() - 1) //there is no right node
	{
		if (l > vec.size() - 1) return -1; //there is no left node
		else return l;
	}

	if (vec[l] == vec[r]) return 0;
	if (vec[l] > vec[r]) return r;
	return l;
}

template <class T>
int PriorityQueue<T>::traverse(const T& ele) const
{
	int findIndex = 0;
	for (auto itr = vec.begin(); itr != vec.end(); itr++, findIndex++)
		if (*itr == ele) return findIndex;
	
	return -1;
}

template class PriorityQueue<int>;