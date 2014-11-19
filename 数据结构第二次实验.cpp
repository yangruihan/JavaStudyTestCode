#include <stdio.h>
#include <stdlib.h>

///// �ṹ��
typedef struct LNode
{
    int coe;    ///ϵ��
    int exp;    ///ָ��
    struct LNode * next;
} LNode, *LinkList;

///// ������
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
		printf("�������%d���ϵ����ָ����\n",i+1);
        scanf("%d%d",&p -> coe,&p -> exp);
        p -> next = NULL;
        h -> next = p;
        h = h -> next;
    }
}

///// �������
void printList(LinkList L)
{
    LNode * p = L -> next;
	int i = 1;

	if(!p)
	{
		printf("�ñ�Ϊ�ձ�");
		return;
	}

    while(p)
    {
        printf("��%d�{coe=%d,exp=%d}\n",i++,p -> coe,p -> exp);
        p = p -> next;
    }
    printf("\n");
}

///// �ϲ�����
void mergeTwoList(LinkList &La,LinkList &Lb)
{
    LNode * ha = La -> next;
    LNode * hb = Lb -> next;

    while(ha && hb)
    {
        if(ha -> exp > hb -> exp) ///���ha��ָ������hb��ָ������ôhbֱ�Ӽӵ�ha��ǰ��
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
        else if(ha -> exp < hb -> exp) ///���ha��ָ��С��hb��ָ������ôha����ƶ�һλ
        {
            ha = ha -> next;
        }
        else ///���ha��ָ������hb��ָ������ôha��hb��ϵ�����
        {
            int result = ha -> coe + hb -> coe;
            if(0 == result) ///����������0,��ôɾ���������ڵ�
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
            ///������������0
            ha -> coe = result;
            LNode * pb = hb;
            ha = ha -> next;
            hb = hb -> next;
            free(pb); ///�ͷ�hb�ڵ�
        }
    }
    if(hb) ///���hbδ�����꣬���hbΪ�����Ĳ��ֽӵ�ha�ĺ���
    {
        LNode * p = La;
        while(p -> next)
        {
            p = p -> next;
        }
        p -> next = hb;
    }
}

///// �жϱ��Ƿ�Ϊ����
bool listIsAsc(LinkList L)
{
	LNode * p = L;
	while(p -> next)
	{
		if(p -> next -> exp < p -> exp) ///�����ǰ�ڵ����һ���ڵ��ָ��С�ڵ�ǰ�ڵ��ָ������ñ�Ϊ���򣬷���false
		{
			return false;
		}
		p = p -> next;
	}
	return true;
}

///// ������
int main()
{
	int numberA, numberB;
	printf("������a��b����");
	while(scanf("%d%d",&numberA,&numberB))
	{
		printf("-----------------------------------------\n");

		LinkList a;
		printf("a��\n");
		creatList(a,numberA);
		//printList(a);

		LinkList b;
		printf("b��\n");
		creatList(b,numberB);
		//printList(b);

		if(!listIsAsc(a) || !listIsAsc(b)) ///�жϱ�a�ͱ�b�Ƿ�Ϊ����
		{
			printf("�Բ���������ı�ȫ����������������\n");
			printf("-----------------------------------------\n");
			printf("������a��b����");
			continue;
		}

		mergeTwoList(a,b);

		printf("�ϲ�����Ϊ��\n");
		printList(a);

		printf("-----------------------------------------\n");

		printf("������a��b����");
	}
	return 0;
}
