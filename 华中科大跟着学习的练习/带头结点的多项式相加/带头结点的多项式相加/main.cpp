// 带头结点的链表实现多项式的加法.cpp : 定义控制台应用程序的入口点。


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
	p3->next = NULL;    //新建头结点
	p = p3;

	if (p1->next)       //判断多项式是否为空，和为空的处理
	{
		if (p2->next)
		{
			while (pa&&pb)
			{
				if (pa->expn < pb->expn)    //pa中的一项比pb中的一项小
				{
					q = (Linklist)malloc(LENG);
					q->expn = pa->expn;
					q->coef = pa->coef;
					p->next = q;
					p = q;

				}
				else if (pa->expn == pb->expn)  //pa中的一项与pb中的一项相等时
				{
					q = (Linklist)malloc(LENG);
					q->expn = pa->expn;   //设置指数
					q->coef = pa->coef + pb->coef;   //设置系数为两个多项式对应项的系数之和
					p->next = q;
					p = q;

				}
				else
				{
					q = (Linklist)malloc(LENG);
					q->expn = pb->expn;     //设置指数为pb中的一项的指数
					q->coef = pb->coef;
					p->next = q;
					p = q;
				}
			}
			// 待写 pa或者 pb为空的时候怎么处理。
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