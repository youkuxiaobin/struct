/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  链表插入删除
 *
 *        Version:  1.0
 *        Created:  2015年03月01日 11时11分27秒
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
#include <errno.h>
#include <string.h>
#include <stdio.h>
using namespace std;

#define LOGDBG(fmt, args...) do {\
    printf("[%s:%d]%s   "fmt"\n", __FILE__, __LINE__, __FUNCTION__, ##args);\
}while(0);

#define LOGERR(fmt, args...) do {\
    printf("[%s:%d]%s   "fmt"(%s)\n", __FILE__, __LINE__, __FUNCTION__,  ##args, strerror(errno));\
}while(0);

template <class T>
class Node
{
    public:
        T data;
        Node<T>* next;
};

template <class T>
class Link
{
    private:
        Node<T>* m_root;
        int m_len;
        
    public:
        Link();
        ~Link();
        bool Add(T data);   //加一个节点
        bool Delete(T data);//删除一个节点
        void Output();      //调试输出
        void Reverse();     //普通的反转链表
        void ReverseRecur();//递归反转链表
        bool IsLinkCircle();//判断链表是否有环

    private:
        Node<T>* ReverseRecur(Node<T>* node);//递归反转链表内部函数
};

template <class T>
Link<T>::Link()
{
    m_root = NULL;
    m_len = 0;
}

template <class T>
Link<T>::~Link()
{
    Node<T>* temp = m_root;
    while (temp && m_len >0)
    {
        m_root = m_root->next;
        delete temp;
        temp = m_root;
        m_len --;
    }
    m_root = NULL;
}

template <class T>
bool Link<T>::Add(T data)
{
    Node<T>* node = new Node<T>();
    node->next = NULL;
    node->data = data;
    //注意链表为空的情况
    if (m_root == NULL)
    {
        m_root = node;
        return true;
    }
    node->next = m_root;
    m_root = node;
    m_len++;
    return true;
}

template <class T>
bool Link<T>::Delete(T data)
{
    Node<T> *current = m_root;
    Node<T> *front = m_root;
    while(current)
    {
        if (current->data == data)
        {
            break; 
        }
        else
        {
            front = current;
            current = current->next;
        }
    }
    if (current == NULL)
    {
        return false;
    }
    else if (current == front)
    {
        m_root = m_root->next;
        delete current;
    }
    else 
    {
        front->next = current->next;
        delete current;
    }
    return true;
}
template <class T>
void Link<T>::Output()
{
    Node<T>* temp = m_root;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

template <class T>
void Link<T>::Reverse()
{
    if (m_root == NULL || m_root->next == NULL)
    {
        //如果是空链表or链表只存在一个节点，那么就返回
        LOGDBG("Link table is empty");
        return;
    }

    Node<T>* front = m_root;
    Node<T>* next = m_root->next;
    Node<T>* temp = NULL;
    while (next)
    {
        temp = next->next;  //注意首先保存下一个节点地址
        next->next = front;
        front = next;
        next = temp;
    }

    m_root->next = NULL;
    m_root = front;
}

template <class T>
Node<T>* Link<T>::ReverseRecur(Node<T>* node)
{
    if (m_root == NULL && m_root->next == NULL)
    {
        return NULL;
    }
    if (node->next == NULL)
    {
        m_root->next = NULL;
        m_root = node;
        return node;
    }

    Node<T>* front = ReverseRecur(node->next);
    front->next = node;
    return node;
}
template <class T>
void Link<T>::ReverseRecur()
{
    ReverseRecur(m_root);
}

template <class T>
bool Link<T>::IsLinkCircle()
{
    Node<T>* one = m_root;
    Node<T>* two = m_root;
    while(two && two->next)
    {
        one = one->next;
        two = two->next->next;
        if (one == two)
        {
            return true;
        }
    }
    if (one == NULL || two == NULL)
    {
        return false;
    }
    return true;
}

int main(int argc, char** argv)
{
    Link<int> ln;
    int i =0; 
    int one;
    for (;i<20; i++)
    {
        ln.Add(i);
        ln.Output();
    }
    
    cout<<"#######################"<<endl;
    ln.Reverse();
    ln.Output();
    cout<<"#######################"<<endl;
    ln.ReverseRecur();
    ln.Output();
    cout<<"#######################"<<endl;
    LOGDBG("is exist circle (%s)", ln.IsLinkCircle()?"true":"false");
    cout<<"#######################"<<endl;
    for (i=0; i<20; i++)
    {
        ln.Delete(i);
        ln.Output();
    }
    return 0;
}
