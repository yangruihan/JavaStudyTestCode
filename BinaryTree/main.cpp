//
//  main.cpp
//  BinaryTree
//
//  Created by 杨睿涵 on 14/11/17.
//  Copyright (c) 2014年 杨睿涵. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

///// 二叉树结构体
typedef struct TreeNode
{
    ElemType data;  // 数据域
    struct TreeNode * lchild;   // 左孩子
    struct TreeNode * rchild;   // 右孩子
} TreeNode , * BinaryTree;

///// 先序创建一颗二叉树
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

///// 先序遍历输出这颗二叉树
void preOrderPrintTree(BinaryTree bt)
{
    if(bt)  // 如果当前节点不为空
    {
        printf("%c ",bt ->data);   // 输出当前节点的数据域
        preOrderPrintTree(bt ->lchild); // 递归左孩子
        preOrderPrintTree(bt ->rchild); // 递归右孩子
    }
}

///// 计算该树节点数
int numberOfAllNode(BinaryTree bt)
{
    if(bt) // 如果当前节点不为空
    {
        // 当前节点为根时节点总个数 = 它左孩子为根时节点总个数 + 它右孩子为根时节点总个数 + 它本身
        return numberOfAllNode(bt ->lchild) + numberOfAllNode(bt ->rchild) + 1;
    }
    else // 如果当前节点为空，则返回0;
    {
        return 0;
    }
}

///// 计算该树中度为1的节点个数
int numberOfOneChildNode(BinaryTree bt)
{
    if(bt) // 如果当前节点不为空
    {
        if((!bt ->lchild && bt ->rchild) || (!bt ->rchild && bt ->lchild))
            // 如果当前节点没有左孩子或者右孩子，则加上当前节点，反之不加
        {
            return numberOfOneChildNode(bt ->rchild) + numberOfOneChildNode(bt ->rchild) + 1;
        }
        else
        {
            return numberOfOneChildNode(bt ->lchild) + numberOfOneChildNode(bt ->rchild);
        }
    }
    else // 如果当前节点为空，则返回0
    {
        return 0;
    }
}

///// 计算该树中度为2的节点个数
int numberOfTwoChildNode(BinaryTree bt)
{
    if(bt) // 如果当前节点不为空
    {
        if(bt ->lchild && bt ->rchild) // 如果当前节点左右孩子都存在的话，则加上当前节点，反之则不加
        {
            return numberOfTwoChildNode(bt ->lchild) + numberOfTwoChildNode(bt ->rchild) + 1;
        }
        else
        {
            return numberOfTwoChildNode(bt ->lchild) + numberOfTwoChildNode(bt ->rchild);
        }
    }
    else // 如果当前节点为空，则返回0
    {
        return 0;
    }
}

///// 计算该树中度为0的节点个数
int numberOfNoChildNode(BinaryTree bt)
{
    if(bt) // 如果当前节点不为空
    {
        if(!bt ->lchild && !bt ->rchild)
        {
            return numberOfNoChildNode(bt ->lchild) + numberOfNoChildNode(bt ->rchild) + 1;
        }
        else
        {
            return numberOfNoChildNode(bt ->lchild) + numberOfNoChildNode(bt ->rchild);
        }
    }
    else // 如果当前节点为空，则返回0
    {
        return 0;
    }
}

///// 计算树的深度
int deepOfTree(BinaryTree bt)
{
    if(bt) // 如果当前节点不为空，则深度为，max（左子树的深度，右子树的深度）+ 1
    {
        return deepOfTree(bt ->lchild) > deepOfTree(bt ->rchild) ?
        deepOfTree(bt ->lchild) + 1 : deepOfTree(bt ->rchild) + 1;
    }
    else // 如果当前节点为空，则深度为0
    {
        return 0;
    }
}

///// 判断两颗树是否相等
bool isSame(BinaryTree bt1, BinaryTree bt2)
{
    if(bt1 && bt2) // 如果两个都不为空
    {
        if(bt1 ->data != bt2 ->data) // 如果当前两个节点的数据域不同，则两棵树不相等
        {
            return false;
        }
        else // 如果当前两个节点的数据域相同，则分别比较他们的左子树和右子树
        {
            return (isSame(bt1 ->lchild, bt2 ->lchild) && isSame(bt1 ->rchild, bt2 ->rchild));
        }
    }
    else if((bt1 && !bt2) || (bt2 && !bt1)) // 如果两个其中有一个为空
    {
        return false;
    }
    else // 两个都为空
    {
        return true;
    }
}

///// 判断两棵树是否相似
bool isSimilar(BinaryTree bt1, BinaryTree bt2)
{
    if(bt1 && bt2) // 如果两个都为空或者都不为空，则相似
    {
        // 递归调用
        return (isSimilar(bt1 ->lchild, bt2 ->lchild) && isSimilar(bt1 ->rchild, bt2 ->rchild));
    }
    else if(!bt1 && !bt2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

///// 复制一颗二叉树
BinaryTree copyBinaryTree(BinaryTree bt)
{
    BinaryTree t;
    if(bt) // 如果bt不为空
    {
        t = (BinaryTree) malloc(sizeof(TreeNode));
        t ->data = bt ->data;
        t ->lchild = copyBinaryTree(bt ->lchild); // 递归复制左子树
        t ->rchild = copyBinaryTree(bt ->rchild); // 递归复制右子树
        
        return t;
    }
    else // 如果bt为空，则返回空
    {
        return NULL;
    }
}

int a[1000]; // 建立一个数组，用于存储二叉树中每层节点的个数

///// 一层一层的遍历
void cacuWidth(BinaryTree bt,int n)
{
    if(bt) // 如果当前节点不为空
    {
        a[n]++;
        cacuWidth(bt ->lchild, n+1);
        cacuWidth(bt ->rchild, n+1);
    }
    else
    {
        return;
    }
}

///// 计算该树的宽度
int widthOfBinaryTree(BinaryTree bt)
{
    int deep = deepOfTree(bt); // 计算出二叉树的深度
    cacuWidth(bt, 0); // 调用上面的方法
    int max = 0;
    int i = 0;
    
    for(i = 0;i < deep;i++)
    {
        printf("%d\n",a[i]);
        if(a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

///// 主函数
int main(int argc, const char * argv[]) {
    
    printf("请输入一棵树的先序序列（以下默认为先序输入）：\n");
    
    BinaryTree b;
    
    b = createBinaryTree();
    
    char tempc;
    
    scanf("%c",&tempc); // 把用户输入的回车读入，避免后面树输入错误
    
    printf("------------------\n");
    
    printf("先序遍历该树：\n");
    
    preOrderPrintTree(b);
    
    printf("\n");
    
    printf("------------------\n");

    printf("该树总节点个数为：");
    
    int AllNodeNumber = numberOfAllNode(b);
    
    printf("%d\n",AllNodeNumber);
    
    printf("------------------\n");
    
    printf("该树中度为1的节点个数为：");
    
    int OneChildNodeNumber = numberOfOneChildNode(b);
    
    printf("%d\n",OneChildNodeNumber);
    
    printf("------------------\n");
    
    printf("该树中度为2的节点个数为：");
    
    int TwoChildNodeNumber = numberOfTwoChildNode(b);
    
    printf("%d\n",TwoChildNodeNumber);
    
    printf("------------------\n");
    
    printf("该树中度为0的节点个数为：");
    
    int NoChildNodeNumber = numberOfNoChildNode(b);
    
    printf("%d\n",NoChildNodeNumber);
    
    printf("------------------\n");
    
    printf("该树的深度为：");
    
    int treeDeep = deepOfTree(b);
    
    printf("%d\n",treeDeep);
    
    printf("------------------\n");
    
    printf("判断两颗树是否相等：\n");
    
    printf("请输入树1：\n");
    
    BinaryTree t1;
    
    t1 = createBinaryTree();
    
    scanf("%c",&tempc); // 把用户输入的回车读入
    
    preOrderPrintTree(t1);
    
    printf("\n");
    
    printf("请输入树2：\n");
    
    BinaryTree t2;
    
    t2 = createBinaryTree();
    
    scanf("%c",&tempc); // 同上
    
    preOrderPrintTree(t2);
    
    printf("\n");
    
    if(isSame(t1, t2))
    {
        printf("两树相等\n");
    }
    else
    {
        printf("两树不相等\n");
    }
    
    printf("------------------\n");
    
    printf("判断两棵树是否相似：\n");
    
    printf("请输入树3：\n");
    
    BinaryTree t3;
    
    t3 = createBinaryTree();
    
    scanf("%c",&tempc); // 同上
    
    preOrderPrintTree(t3);
    
    printf("\n");
    
    printf("请输入树4：\n");
    
    BinaryTree t4;
    
    t4 = createBinaryTree();
    
    scanf("%c",&tempc); // 同上
    
    preOrderPrintTree(t4);
    
    printf("\n");
    
    if(isSimilar(t3, t4))
    {
        printf("两棵树相似\n");
    }
    else
    {
        printf("两棵树不相似\n");
    }
    
    printf("------------------\n");
    
    printf("请输入一颗需要复制的二叉树：\n");
    
    BinaryTree t5;
    
    t5 = createBinaryTree();
    
    scanf("%c",&tempc); // 同上

    BinaryTree t6;
    
    t6 = copyBinaryTree(t5);
    
    printf("复制后新树的先序遍历：\n");
    
    preOrderPrintTree(t6);
    
    printf("\n");
    
    printf("-------------------\n");
    
    printf("计算二叉树的宽度：\n");
    
    printf("请输入一颗二叉树：\n");
    
    BinaryTree t7;
    
    t7 = createBinaryTree();
    
    scanf("%c",&tempc);
    
    preOrderPrintTree(t7);
    
    printf("\n");
    
    int binaryTreeWidth = widthOfBinaryTree(t7);
    
    printf("该二叉树的宽度为：%d\n",binaryTreeWidth);
    
    printf("-------------------\n");
    
    return 0;
}
