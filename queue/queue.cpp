/*
 * =====================================================================================
 *
 *       Filename:  queue.cpp
 *
 *    Description:  队列的简单实现
 *
 *        Version:  1.0
 *        Created:  2015年02月25日 21时38分24秒
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
template <class T>
class Node
{
    public:
    struct Node* next;
    T data;
};

template <class T>
class Queue
{
    private:
        Node<T>* m_front;
        Node<T>* m_rear;
        int m_size;
    public:
        Queue();
        ~Queue();
        bool Add(T data);
        T Delete();
};

template <class T>
Queue<T>::Queue()
{
    m_front = NULL;
    m_rear = NULL;
    m_size = 0;
}

template <class T>
Queue<T>::~Queue()
{
    Node<T>* temp = m_front;
    while(temp)
    {
        m_front = m_front->next;
        delete temp;
        temp = m_front;
    }
    m_front= NULL;
}
template <class T>
bool Queue<T>::Add(T data)
{
    Node<T>* temp = new Node<T>;
    temp->next = NULL;
    temp->data = data; 
    if (m_size == 0)
    {
        m_front = temp;
        m_rear = temp;
        m_size++;
    }
    else
    {
        temp->next = m_rear->next;
        m_rear->next = temp;
        m_rear = temp;
        m_size++;
    }
    return true;
}

template <class T>
T Queue<T>::Delete()
{
    if (m_size == 0)
    {
        throw 1;
    }
    else
    {
        T data = m_front->data;
        Node<T>*temp = m_front;
        m_front = m_front->next;
        delete temp;
        m_size --;
        return data;
    }
}

int main(int argc, char** argv)
{
    Queue<int> A;
    int i = 0;
    for(; i< 20;i++)
    {
        A.Add(i);
    }
    cout<<"*********split************"<<endl;
    for(i = 0; i<20; i++)
    {                                                                                                                                                              
        cout<<"Delete element is "<<A.Delete()<<endl;
    }
    cout<<"main func finish"<<endl;
    return 0;
}
