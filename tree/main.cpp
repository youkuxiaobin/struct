/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  travel tree 
 *
 *        Version:  1.0
 *        Created:  2015年02月26日 17时55分25秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  liyankun (), liyankun@baidu.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stack>
#include <iostream>
using namespace std;

struct BinaryTree
{
    int data;
    BinaryTree* lchild;
    BinaryTree* rchild;
};

void InOrderTravel(struct BinaryTree* root)
{
    stack<struct BinaryTree*> mystack;
    mystack.push(root);
    BinaryTree* p;
    while(!mystack.empty())
    {
        while((p=mystack.top()) && p)
        {
            mystack.push(p->lchild);
        }
        mystack.pop();
        
        if (!mystack.empty())
        {
            p = mystack.top();
            mystack.pop();
            mystack.push(p->rchild);
        }
    }
}

