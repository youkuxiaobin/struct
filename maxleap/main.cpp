/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  最大堆代码
 *
 *        Version:  1.0
 *        Created:  2015年02月26日 11时25分19秒
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
#include <stdio.h>
#include <errno.h>
#include <string.h>
using namespace std;

#define LOGDBG(fmt, args...) do {\
    printf("[%s:%d]%s   "fmt"\n", __FILE__, __LINE__, __FUNCTION__, ##args);\
}while(0);

#define LOGERR(fmt, args...) do {\
    printf("[%s:%d]%s   "fmt"(%s)\n", __FILE__, __LINE__, __FUNCTION__,  ##args, strerror(errno));\
}while(0);
template <typename T>
class Node
{
    public:
    int priority;
    T data;
};

template <class T>
class MaxLeap
{
    private:
        Node<T>* m_root;
        int m_len;      //数组现在的长度
        int m_uindex;//未使用索引位置
    public:
        MaxLeap(int len=20);
        ~MaxLeap();
        bool InsertMaxLeap(T data, int priority);
        bool DeleteMaxLeap(T &value);
        void Output();
};

template <class T>
MaxLeap<T>::MaxLeap(int len)
{
    m_root = new Node<T>[len];
    m_len = len;
    m_uindex = 0;
}

template <class T>
MaxLeap<T>::~MaxLeap()
{
    delete[] m_root;
}

template <class T>
bool MaxLeap<T>::InsertMaxLeap(T data, int priority)
{
    if (m_uindex >= (m_len - 1))
    {
        LOGDBG("Leap is full");
        return false; 
    }
    int index = m_uindex;

    while (index)
    {
        if (m_root[index/2].priority < priority)
        {
            m_root[index].data = m_root[index/2].data;
            m_root[index].priority = m_root[index/2].priority;
        }
        else
        {
            break;
        }
        index = index/2;
    }
    m_uindex++;
    m_root[index].data = data;
    m_root[index].priority = priority; 
    return true;
}

template <class T>
bool MaxLeap<T>::DeleteMaxLeap(T& value)
{
    if (m_uindex == 0)
    {
        LOGDBG("Delete Max Leap and MaxLeap is empty");
        return false;
    }
    value = m_root[0].priority;
    if (m_uindex == 1)
    {
        m_uindex--;
        return true;
    }
    int c = 1;
    m_uindex--;
    Node<T>* temp = &m_root[m_uindex];

    while(c <= (m_uindex-1))
    {
        if (c < (m_uindex-1) && m_root[c].priority < m_root[c+1].priority)
        {
            c++;//如果存在右节点，而且右节点比左节点还大
        }
        if (m_root[c].priority < temp->priority)
        {
            break;//找到大于子节点的根节点位置为c/2
        }
        m_root[c/2].data = m_root[c].data;
        m_root[c/2].priority = m_root[c].priority;
        c = 2*c;
    }
    m_root[c/2].data = temp->data;
    m_root[c/2].priority = temp->priority;
    return true;
}
template <class T>
void MaxLeap<T>::Output()
{
    int base = 1;
    int level = 0;
    for (int i=0;i<m_len; i++)
    {
        cout<<m_root[i].priority<<" ";
        if (i==level)
        {
            cout<<endl;
            base *=2;
            level += base;
        }
    }
}


int main(int argc, char** argv)
{
    MaxLeap<int> leap(20);
	int data, priority;
	for(int i = 0; i<20; i++)
	{
		cout<<"priority     "<<i<< endl;
		cin>>priority;
		leap.InsertMaxLeap(5, priority);
	}

    leap.Output();
    cout<<"###########"<<endl;
    int value;
    for (int j =0; j<20; j++)
    {
        leap.DeleteMaxLeap(value);
        cout<< value<<endl;
    }
    return 0;
}
