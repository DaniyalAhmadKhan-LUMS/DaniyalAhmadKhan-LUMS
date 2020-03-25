#ifndef __STACK_CPP
#define __STACK_CPP
#include "stack.h"

template <class T>
Stack<T>::Stack()
{

}

template <class T>
Stack<T>::Stack(Stack<T>& otherStack)
{
    Stack<T> copyingstack;
    while ( !otherStack.isEmpty())
    {
        copyingstack.push(otherStack.pop());
    }
    while ( !copyingstack.isEmpty() )
    {
        T I1 = copyingstack.pop();
        push(I1);
        otherStack.push(I1);
    }
}
template <class T>
Stack<T>::~Stack()
{
}

template <class T>
void Stack<T>::push(T item)
{
    list.insertAtHead(item);
}

template <class T>
T Stack<T>::top()
{
    if(list.getHead()==NULL)
        return T();
    else
    {
        return list.getHead()->value;
    }
}

template <class T>
T Stack<T>::pop()
{
    T poptop =top();
    list.deleteHead();
    return poptop;
}

template <class T>
int Stack<T>::length()
{
    return list.length();
}

template <class T>
bool Stack<T>::isEmpty()
{
   if(list.length()==0)
   {
    return true;
   }
   else
   {
    return false;
   }
}

#endif
