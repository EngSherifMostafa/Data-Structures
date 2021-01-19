#include <iostream>
#include "QueueLinked.cpp"
using namespace std;

int main()
{
    int ele;
    QueueLinked<int> q;
    if(q.isEmpty())
        cout<<"Queue is empty"<<endl;
    else
        cout<<"Queue is not empty"<<endl;

    q.enQueue(5);
    q.enQueue(15);
    q.enQueue(25);
    q.enQueue(35);
    q.enQueue(45);
    q.traverse();

    if(q.isEmpty())
        cout<<"Queue is empty"<<endl;
    else
        cout<<"Queue is not empty"<<endl;

    q.getFront(ele);
    cout<<"front element: "<<ele<<endl;

    q.deQueue(ele);
    cout<<"deQueue element: "<<ele<<endl;

    q.getFront(ele);
    cout<<"front element: "<<ele<<endl;

    return 0;
}
