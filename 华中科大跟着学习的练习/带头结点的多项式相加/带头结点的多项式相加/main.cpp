// ��ͷ��������ʵ�ֶ���ʽ�ļӷ�.cpp : �������̨Ӧ�ó������ڵ㡣


#include"malloc.h"
#include<stdio.h>
typedef struct node
{
	int coef, expn;
	struct node *next;
}node, *Linklist;
#define LENG sizeof(struct node )

Linklist addpoly(Linklist p1, Linklist p2)
{
	Linklist p3, p, q;
	Linklist pa = p1->next, pb = p2->next;
	p3 = (Linklist)malloc(LENG);
	p3->next = NULL;    //�½�ͷ���
	p = p3;

	if (p1->next)       //�ж϶���ʽ�Ƿ�Ϊ�գ���Ϊ�յĴ���
	{
		if (p2->next)
		{
			while (pa&&pb)
			{
				if (pa->expn < pb->expn)    //pa�е�һ���pb�е�һ��С
				{
					q = (Linklist)malloc(LENG);
					q->expn = pa->expn;
					q->coef = pa->coef;
					p->next = q;
					p = q;

				}
				else if (pa->expn == pb->expn)  //pa�е�һ����pb�е�һ�����ʱ
				{
					q = (Linklist)malloc(LENG);
					q->expn = pa->expn;   //����ָ��
					q->coef = pa->coef + pb->coef;   //����ϵ��Ϊ��������ʽ��Ӧ���ϵ��֮��
					p->next = q;
					p = q;

				}
				else
				{
					q = (Linklist)malloc(LENG);
					q->expn = pb->expn;     //����ָ��Ϊpb�е�һ���ָ��
					q->coef = pb->coef;
					p->next = q;
					p = q;
				}
			}
			// ��д pa���� pbΪ�յ�ʱ����ô����
			if (pa)
			{
				while (pa)
				{
					q = (Linklist)malloc(LENG);
					q->coef = pa->coef;
					q->expn = pa->expn;
					p->next = q;
					pa = pa->next;

				}
				p->next = NULL;
			}
			else
			{
				while (pb)
				{
					q = (Linklist)malloc(LENG);
					q->coef = pb->coef;
					q->expn = pb->expn;
					p->next = q;
					pb = pa->next;
				}

				p->next = NULL;
			}
		}
		else
			return p1;

	}

	else
	{
		if (p2->next)
		{
			return p2;
		}
		else
		{
			return NULL;
		}
	}
}