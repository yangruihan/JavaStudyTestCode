#include <stdio.h>
#include <stdlib.h>

///// 结构体
typedef struct LNode
{
    int coe;    ///系数
    int exp;    ///指数
    struct LNode * next;
} LNode, *LinkList;

///// 创建表
void creatList(LinkList & L , int n)
{
    L = (LinkList) malloc (sizeof(LNode));
    L -> next = NULL;

    LNode * h = L;

    int i;
    LNode * p;

    for(i = 0;i < n;i++)
    {
        p = (LinkList) malloc (sizeof(LNode));
		printf("请输入第%d项的系数和指数：\n",i+1);
        scanf("%d%d",&p -> coe,&p -> exp);
        p -> next = NULL;
        h -> next = p;
        h = h -> next;
    }
}

///// 输出函数
void printList(LinkList L)
{
    LNode * p = L -> next;
	int i = 1;

	if(!p)
	{
		printf("该表为空表！");
		return;
	}

    while(p)
    {
        printf("第%d项：{coe=%d,exp=%d}\n",i++,p -> coe,p -> exp);
        p = p -> next;
    }
    printf("\n");
}

///// 合并函数
void mergeTwoList(LinkList &La,LinkList &Lb)
{
    LNode * ha = La -> next;
    LNode * hb = Lb -> next;

    while(ha && hb)
    {
        if(ha -> exp > hb -> exp) ///如果ha的指数大于hb的指数，那么hb直接加到ha的前面
        {
            LNode * p = La;
            LNode * p1 = hb -> next;
			
            while(p -> next != ha)
            {
                p = p -> next;
            }
            p -> next = hb;
            hb -> next = ha;
            hb = p1;
        }
        else if(ha -> exp < hb -> exp) ///如果ha的指数小于hb的指数，那么ha向后移动一位
        {
            ha = ha -> next;
        }
        else ///如果ha的指数等于hb的指数，那么ha和hb的系数相加
        {
            int result = ha -> coe + hb -> coe;
            if(0 == result) ///如果结果等于0,那么删除这两个节点
            {
                LNode * pa = ha;
                LNode * pb = hb;

				LNode * p = La;
				while(p -> next != ha)
				{
					p = p -> next;
				}
				p -> next = ha -> next;

                ha = ha -> next;
                hb = hb -> next;
                free(pa);
                free(pb);
                continue;
            }
            ///如果结果不等于0
            ha -> coe = result;
            LNode * pb = hb;
            ha = ha -> next;
            hb = hb -> next;
            free(pb); ///释放hb节点
        }
    }
    if(hb) ///如果hb未遍历完，则把hb为遍历的部分接到ha的后面
    {
        LNode * p = La;
        while(p -> next)
        {
            p = p -> next;
        }
        p -> next = hb;
    }
}

///// 判断表是否为升序
bool listIsAsc(LinkList L)
{
	LNode * p = L;
	while(p -> next)
	{
		if(p -> next -> exp < p -> exp) ///如果当前节点的下一个节点的指数小于当前节点的指数，则该表不为升序，返回false
		{
			return false;
		}
		p = p -> next;
	}
	return true;
}

///// 主函数
int main()
{
	int numberA, numberB;
	printf("请输入a，b表长：");
	while(scanf("%d%d",&numberA,&numberB))
	{
		printf("-----------------------------------------\n");

		LinkList a;
		printf("a表：\n");
		creatList(a,numberA);
		//printList(a);

		LinkList b;
		printf("b表：\n");
		creatList(b,numberB);
		//printList(b);

		if(!listIsAsc(a) || !listIsAsc(b)) ///判断表a和表b是否都为升序
		{
			printf("对不起，你输入的表不全是升序，请重新输入\n");
			printf("-----------------------------------------\n");
			printf("请输入a，b表长：");
			continue;
		}

		mergeTwoList(a,b);

		printf("合并后结果为：\n");
		printList(a);

		printf("-----------------------------------------\n");

		printf("请输入a，b表长：");
	}
	return 0;
}
