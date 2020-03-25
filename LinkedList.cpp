#ifndef __LIST_CPP
#define __LIST_CPP

#include <cstdlib>
#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList()
{
     head=NULL;
     tail=NULL;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& otherLinkedList)
{
    head=NULL;
    tail=NULL;
    ListItem<T>* temp = otherLinkedList.tail;
    while(temp!=NULL)
    {
        insertAtHead(temp->value);
        temp=temp->prev;
    }
}

template <class T>
LinkedList<T>::~LinkedList()
{
    ListItem<T> *temp;
    while(head!=NULL)
    {
        temp=head;
        head = head->next;
        delete temp;
    }
}

template <class T>
void LinkedList<T>::insertAtHead(T item)
{
    ListItem<T> *temp = new ListItem<T>(item);

    if (head == NULL)
    {
        head=temp;
        tail = temp;
    }
    else
    {
        head->prev=temp;
        temp->next = head;
        head = temp;
    }
}

template <class T>
void LinkedList<T>::insertAtTail(T item)
{
    ListItem<T> *temp = new ListItem<T>(item);
    if (head==NULL)
    {
        head=temp;
        tail = head;
    }
    else
    {
    tail->next = temp;
    temp->prev=tail;
    tail = temp;
    }
}

template <class T>
void LinkedList<T>::insertAfter(T toInsert, T afterWhat)
{
    ListItem<T> *temp = searchFor(afterWhat);
    ListItem<T> *temp_2 = new ListItem<T>(toInsert);
    if(temp->value == afterWhat)
    {
        temp_2->next = temp->next;
        temp_2->prev = temp;

        if (temp == tail)   // If afterWhat is at end
        {
            tail = temp_2;
        }
        else
        {
            temp->next->prev = temp_2;
        }
        temp->next = temp_2;
    }
}


template <class T>
ListItem<T>* LinkedList<T>::getHead()
{
    return head;
}

template <class T>
ListItem<T>* LinkedList<T>::getTail()
{
    return tail;
}

template <class T>
ListItem<T> *LinkedList<T>::searchFor(T item)
{
    ListItem<T> *temp = head;
    while (temp!=NULL)
    {
        if (temp->value==item)
        {
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}

template <class T>
void LinkedList<T>::deleteElement(T item)
{
    ListItem<T> *temp= searchFor(item);
    if(temp==NULL)
        {
            return;
        }
    else if(temp==head)
    {
        deleteHead();
    }
    else if(temp==tail)
    {
        deleteTail();
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        temp=NULL;
    }
}

template <class T>
void LinkedList<T>::deleteHead()
{
    if(head->next==NULL)
    {
        head=NULL;
        tail=NULL;
    }
    else
    {
        ListItem<T> *temp = head;
        head=head->next;
        head->prev=NULL;
        delete temp;
    }

}

template <class T>
void LinkedList<T>::deleteTail()
{
    if(head == NULL)
        return;
    else if(head->next == NULL)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        tail = tail->prev;
        delete tail->next;
        tail->next=NULL;
    }
}

template <class T>
int LinkedList<T>::length()
{
    int counter = 0;
    ListItem<T> *temp = head;
    while(temp != NULL)
    {
        temp = temp->next;
        counter++;
    }
    return counter;
}


#endif
