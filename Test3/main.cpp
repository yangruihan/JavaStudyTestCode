//
//  main.cpp
//  Test3
//
//  Created by 杨睿涵 on 14/11/26.
//  Copyright (c) 2014年 杨睿涵. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

const int MAX_TREE_NODE = 100;
const int OK = 10001;
const int ERROR = OK + 1;

typedef char ElemType;  // 定义一个数据类型

// 二叉树结构体
typedef struct TreeNode
{
    ElemType data; // 数据域
    struct TreeNode * lchild; // 左孩子
    struct TreeNode * rchild; // 右孩子
}TreeNode, * BinaryTree;

// 链表节点
typedef struct QueueNode
{
    BinaryTree treeNode; // 存储的二叉树节点
}QueueNode;

// 队列
typedef struct Queue
{
    QueueNode queueNode[MAX_TREE_NODE]; // 节点数组
    int head; // 头指针
    int tail; // 尾指针
}Queue;

// 初始化队列
int initQueue(Queue &q)
{
    q.head = 0;
    q.tail = 0;
    
    return OK;
}

// 入队操作
int inQueue(Queue &q, BinaryTree t)
{
    if(q.tail < MAX_TREE_NODE)
    {
        q.queueNode[q.tail++].treeNode = t;
        return q.tail;
    }
    else
    {
        printf("队列已满，无法入队\n");
        return ERROR;
    }
}

// 出队操作
BinaryTree outQueue(Queue &q)
{
    if(q.head == q.tail)
    {
        printf("队列已空，无法出队\n");
        return NULL;
    }
    else
    {
        return q.queueNode[q.head++].treeNode;
    }
}

// 判断队列是否为空
bool queueIsEmpty(Queue &q)
{
    if(q.tail == q.head)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 先序创建一颗二叉树
BinaryTree createBinaryTree()
{
    BinaryTree newTree;
    
    char c;
    
    scanf("%c",&c);
    
    if (c == '#') // 如果当前读到的字符是#，代表它是叶子节点，没有孩子
    {
        newTree = NULL;
    }
    else    // 如果不是叶子节点
    {
        newTree = (BinaryTree) malloc(sizeof(TreeNode)); // 在内存中开辟新的空间
        newTree -> data = c; // 将当前输入的值存储到当前节点的数据域中
        
        // 递归调用
        newTree -> lchild = createBinaryTree();
        newTree -> rchild = createBinaryTree();
    }
    
    return newTree; // 返回根节点
}

// 先序遍历输出这颗二叉树
int preOrderPrintTree(BinaryTree bt)
{
    if(bt)  // 如果当前节点不为空
    {
        printf("%c ",bt ->data);   // 输出当前节点的数据域
        preOrderPrintTree(bt ->lchild); // 递归左孩子
        preOrderPrintTree(bt ->rchild); // 递归右孩子
    }
    
    return OK;
}

// 将动态存储的二叉树转换成静态链式二叉树
int changeToStatic(BinaryTree bt, Queue q)
{
    // 如果根节点为空，则为一颗空树
    if(!bt)
    {
        printf("该树为一颗空树\n");
        return ERROR;
    }
    
    initQueue(q); // 将队列初始化
    
    inQueue(q, bt); //  将根节点加入队列
    
    // 如果根节点既没有左孩子也没有右孩子，则直接输出根节点
    if(! bt -> lchild && ! bt -> rchild)
    {
        BinaryTree tempTree = outQueue(q);
        
        printf("%c： 左孩子：无 右孩子：无\n",tempTree -> data);
    }
    
    // 当队列不空得时候循环执行
    while (!queueIsEmpty(q)) {
        
        BinaryTree tempTree = outQueue(q); // 队头出队列
        
        printf("%c： ",tempTree -> data);
        
        // 如果该节点有左孩子
        if(tempTree -> lchild)
        {
            printf("左孩子：%d/%c ",inQueue(q, tempTree -> lchild), tempTree -> lchild -> data);
        }
        else
        {
            printf("左孩子：无 ");
        }
        
        // 如果该节点有右孩子
        if(tempTree -> rchild)
        {
            printf("右孩子：%d/%c ",inQueue(q, tempTree -> rchild), tempTree -> rchild -> data);
        }
        else
        {
            printf("右孩子：无 ");
        }
        
        printf("\n");
        
    }
    return OK;
}


int main(int argc, const char * argv[]) {
    BinaryTree bt;
    
    bt = createBinaryTree();
    
    preOrderPrintTree(bt);
    
    printf("\n");
    
    Queue q;
    
    changeToStatic(bt, q);
    
    return 0;
}
