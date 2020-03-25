#ifndef __QUEUE_CPP

#define __QUEUE_CPP
#include "queue.h"

template <class T>
Queue<T>::Queue()
{
        ListItem<T> *queuehead = list.getHead();
        queuehead=NULL;
        ListItem<T> *queuetail = list.getTail();
        queuetail=NULL;

}

template <class T>
Queue<T>::Queue(Queue<T>& otherQueue)
{
     for (int i=0; i<otherQueue.length(); i++)
    {
        T temp = otherQueue.dequeue();
        otherQueue.enqueue(temp);
        this->enqueue(temp);
    }
}

template <class T>
Queue<T>::~Queue()
{
    ListItem<T>* temp;
    ListItem<T> *queuehead = list.getHead();
    while(queuehead!=NULL)
    {
        temp=queuehead;
        queuehead=queuehead->next;
        delete temp;
    }
}

template <class T>
void Queue<T>::enqueue(T item)
{
    list.insertAtHead(item);
}

template <class T>
T Queue<T>::front()
{
    ListItem<T> *tempfront = list.getTail();
    return tempfront->value;
}

template <class T>
T Queue<T>::dequeue()
{
    ListItem<T> *tempdelete = list.getTail();
    T temp = tempdelete->value;
    list.deleteTail();
    return temp;
}

template <class T>
int Queue<T>::length()
{
    list.length();
}

template <class T>
bool Queue<T>::isEmpty()
{
    ListItem<T> *temp = list.getHead();
    if(temp==NULL)
        return true;
        return false;
}


#endif
