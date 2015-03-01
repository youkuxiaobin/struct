/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  array template 
 *
 *        Version:  1.0
 *        Created:  2015年02月25日 16时03分33秒
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
class Array
{
    private:
        int size;
        T* element;

    public:
        Array(int size);
        ~Array()
        {
            if (size> 0)
            {
                delete[] element;
            }
        }
        Array(const Array<T>& t1);

        int Size()
        {
            return size;
        }
        T& operator[](int index);
        Array<T>& operator+(Array<T>& t1);
        Array<T>& operator-(Array<T>& t1);
};

template <class T>
Array<T>& Array<T>::operator+(Array<T>& t1)
{
    if (t1.Size() != size)
    {
        return *this;
    }

    int i = 0;
    for (; i<size; i++)
    {
        element[i] += t1[i];
    }
    return *this;
}
template <class T>
Array<T>& Array<T>::operator-( Array<T>& t1)
{
    if (t1.Size() != size)
    {
        return *this;
    }

    int i = 0;
    for (; i<size; i++)
    {
        element[i] -= t1[i];
    }
    return *this;
}
template <class T>
Array<T>::Array(int len)
{
    if (len > 0)
    {
        size = len;
        element = new T[size];
    }
}

template <class T>
Array<T>::Array(const Array& t1)
{

    if (t1.Size() > 0)
    {
        if (size > 0)
        {
            delete[] element;
        }

        element = new T[t1.Size()];
        for (int i=0; i<t1.Size(); i++)
        {
            element[i] = t1[i];
        }

    }
}

template <class T>
T& Array<T>::operator[](int index)
{
    if (index >= 0 && index < size)
    {
        return element[index];
    }
}

int main(int argc, char** argv)
{
    int i=0;
    Array<int> a(10);
    Array<int> b(10);
    for(; i<10;i ++)
    {
        a[i] = i;
        b[i] = 10-i;
    }

    a=a+b;
    for (i=0; i<10; i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}

