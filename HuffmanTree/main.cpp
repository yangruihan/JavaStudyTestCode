//
//  main.cpp
//  HuffmanTree
//
//  Created by 杨睿涵 on 14/11/18.
//  Copyright (c) 2014年 杨睿涵. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

///// 二叉树结构体
typedef struct TreeNode
{
    ElemType data; /// 数据域
    struct TreeNode * lchild; /// 左孩子
    struct TreeNode * rchild; /// 右孩子
} TreeNode,* BinaryTree;

///// 用于存储用户输入的数据个数
int number;

///// 函数声明
bool isEmpty(int a[number][2]);
int min(int a[number][2]);

///// 构建一颗HuffmanTree函数
// bt:树的根节点
// a[][]:数据
void createHuffmanTreeNode(int a[number][2])
{
    if (!isEmpty(a))
    {
        int min1 = min(a); /// 找到当前a数组中最小的一个值
        int min2 = min(a); /// 找到当前a数组中第二小的值
        
        
    }
}

///// 找到数组中最小的那个值
int min(int a[number][2])
{
    int i = 0;
    int n = 0;
    int minNumber = 32767;
    
    for (i = 0; i < number; i++)
    {
        if (1 == a[i][1] && a[i][0] < minNumber)
        {
            minNumber = a[i][0];
            n = i;
        }
    }
    
    a[n][1] = 0;
    return minNumber;
}


///// 判断数组是否为空函数
bool isEmpty(int a[number][2])
{
    int i;
    for (i = 0; i < number; i++)
    {
        if (a[i][1] != 0)
        {
            return false;
        }
    }
    return true;
}

///// 读取用户输入的数据
void inputData(int a[number][2])
{
    int i;
    for (i = 0; i < number; i++)
    {
        scanf("%d",&a[i][0]);
        a[i][1] = 0;
    }
}

///// 输出用户输入的数据
void outputData(int a[number][2])
{
    int i;
    for (i = 0; i < number; i++)
    {
        printf("%d ",a[i][0]);
    }
    printf("\n");
}

///// 主函数
int main(int argc, const char * argv[]) {
    
    printf("欢迎使用HuffmanTree生成器！\n");
    
    printf("请输入需要生成的数据个数n：");
    
    number = 0;
    
    scanf("%d",&number);
    
    printf("请输入数据：\n");
    
    printf("--------------------------\n");
    
    int a[number][2];
    
    inputData(a);
    
    outputData(a);
    
    BinaryTree b;
    
    createHuffmanTree(a);

    return 0;
}
