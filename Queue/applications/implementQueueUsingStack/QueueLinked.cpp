#include "Queuelinked.h"

template <class T>
bool QueueLinked<T>::isEmpty() const
{
    return s1.isEmpty();
}

template <class T>
bool QueueLinked<T>::isFull() const
{
    return s1.isFull();
}

template <class T>
void QueueLinked<T>::getFront(T &ele) const
{
	s1.getTop(ele);
}

template <class T>
void QueueLinked<T>::enQueue(T ele)
{
    if(s1.isEmpty()) s1.push(ele);
    else
    {
        s2.push(ele);

        while(!s1.isEmpty())
        {
            s1.pop(ele);
            s2.push(ele);
        }

        while(!s2.isEmpty())
        {
            s2.pop(ele);
            s1.push(ele);
        }
    }
}

template <class T>
void QueueLinked<T>::deQueue(T &ele)
{
    s1.pop(ele);
}

template <class T>
int QueueLinked<T>::queueLength() const
{
    return s1.stackSize();
}

template <class T>
void display(T x)
{
    cout<<x<<endl;
}

template <class T>
void QueueLinked<T>::traverse() const
{
    s1.traverse(&display);
}
