/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  stack link struct
 *
 *        Version:  1.0
 *        Created:  2015年02月26日 07时20分48秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  liyankun (), liyankun@baidu.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
using namespace std;

template <typename T>
class Node
{
    public:
        Node* next;
        T data;
};

template <class T>
class Stack
{
    private:
        Node<T>* m_front;
        int m_size;
    public:
        Stack();
        ~Stack();
        bool Add(T data);
        T Delete();
        T Top();
        int GetLength();
};

template <class T>
Stack<T>::Stack()
{
    m_front = NULL;
    m_size = 0;
}

template <class T>
Stack<T>::~Stack()
{
    Node<T> *temp = m_front;
    while(temp)
    {
        m_front = m_front->next;
        delete temp;
        temp = m_front;
        m_size --;
    }
}

template <class T>
bool Stack<T>::Add(T data)
{
    Node<T>* ne = new Node<T>;
    ne->next = NULL;
    ne->data = data;
    if(m_front == NULL && m_size == 0)
    {
        m_front = ne;
        m_size++;
    }
    else
    {
        ne->next = m_front;
        m_front = ne;
        m_size++;
    }
    return true;
}
template <class T>
T Stack<T>::Delete()
{
    if (m_size == 0)
        throw 1;
    Node<T>* temp = m_front;
    m_front = m_front->next;
    m_size--;
    T data = temp->data;
    return data;
}


template <class T>
T Stack<T>::Top()
{
    if (m_size == 0)
        throw 1;
    return m_front->data;
}

template <class T>
int Stack<T>::GetLength()
{
    return m_size;
}
int main(int argc, char** argv)
{
	Stack<int> a;
	int i = 0;
	for(;i < 20 ; i++)
	{
		a.Add(i);
		cout<<"Top "<<i<<"  "<<a.Top()<<endl;
	}
	int size = a.GetLength();
	cout<<"***********size = "<<size<<"*************"<<endl;
	for(i = 0; i<size; i++)
	{
		cout<<"Top "<<i<<"  "<<a.Top()<<endl;
		a.Delete();
	}
	cout<<"call xigou before"<<endl;
	return 0;
}
