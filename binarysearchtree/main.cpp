/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年02月27日 07时20分10秒
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

struct BinaryTreeNode
{
    int data;
    struct BinaryTreeNode* lchild;
    struct BinaryTreeNode* rchild;
};
BinaryTreeNode* g_root = NULL;
/*
 * 搜索值为value的节点，保存在pointer中
 */
bool Search(int value, BinaryTreeNode** pointer)
{
    if (g_root == NULL)
    {
        return false;
    }

    struct BinaryTreeNode* temp = g_root;
    while(temp)
    {
        if (temp->data > value)
        {
            temp = temp->lchild;
        }
        else if (temp->data < value)
        {
            temp = temp->rchild;
        }
        else
        {
            break;//found
        }
    }
    if (temp != NULL)
    {
        *pointer = temp;
        return true;
    }
    return false;
}
/* 
 * 插入值为value的节点
 */
bool Insert(int value)
{
    struct BinaryTreeNode* node = new struct BinaryTreeNode;
    node->data = value;
    node->lchild = NULL;
    node->rchild = NULL;

    struct BinaryTreeNode* parent = g_root;
    struct BinaryTreeNode* temp = g_root;

    while (temp)
    {
        parent = temp;
        if (value > temp->data)
        {
            temp = temp->rchild;
        }
        else if (value <= temp->data)
        {
            temp = temp->lchild;
        }
    }
    
    if (parent->lchild == NULL && parent->data > value)
    {
        parent->lchild = node;
    }
    else
    {
        parent->rchild = node;
    }

    return true;
}

/* 
 * 删除值为value的节点
 */
bool Delete(int value)
{
    struct BinaryTreeNode* temp = g_root;
    struct BinaryTreeNode* parent = g_root;
    
    while(temp)
    {

        if (value > temp->data)
        {
            parent = temp
            temp = temp->rchild;
        }
        else if (value < temp->data)
        {
            parent = temp
            temp = temp->lchild;
        }
        else
        {
            break;//found
        }
    }

    if (temp == NULL)
    {
        return false;
    }

    if (temp->lchild && temp->rchild)
    {
        //如果该节点存在左右节点,那么就找左孩子的最右节点
        struct BinaryTreeNode* l_parent = temp->lchild;
        struct BinaryTreeNode* r_node - temp->lchild;
        while(r_node->rchild)
        {
            l_parent = r_node;
            r_node = r_node->rchild;
        }
        temp->data = r_node->data;
        l_parent->rchild = r_node->lchild;
        delete r_node;

    }
    else if (temp->lchild)
    {
        //如果仅仅存在左节点
        if (parent->lchild == temp)
        {
            parent->lchild = temp->lchild;
        }
        else
        {
            parent->rchild = temp->lchild;
        }
        delete temp;
    }
    else if (temp->rchild)
    {
        //如果仅仅存在右节点
        if (parent->lchild == temp)
        {
            parent->lchild = temp->rchild;
        }
        else
        {
            parent->rchild = temp->rchild;
        }
        delete temp;
    }
    else
    {
        //如果删除的是叶子节点
        delete temp;
    }
}
