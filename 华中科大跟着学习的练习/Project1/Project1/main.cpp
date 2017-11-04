#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<malloc.h>
#include<windows.h>
typedef struct node
{
	int coef;
	int expn;
	struct node *next;

}node, *Linklist;
#define LENG sizeof(struct node)
Linklist addpoly(Linklist p1, Linklist p2);   //新建一个链表实现多项式的加法，并返回新建的链表的地址 
void create(Linklist l, int coef, int expn);  //实现每个项递增的节点算法。 

int main(void)
{
	Linklist p1, p2, p3, p;    //定义多项式 p1,p2,p3
	int coef, expn;
	p1 = (Linklist)malloc(LENG);
	p1->next = NULL;
	
	p2 = (Linklist)malloc(LENG);
	p2->next = NULL;
	/*===========================构建多项式p1=========================*/
	printf("请你输入多项式p1的一项（按\t系数，指数\t）输入\n");
	scanf("%d,%d", &coef, &expn);
	while (expn != 0)
	{
		create(p1, coef, expn);
		puts("请你再输入多项式p1的一项格式不变：\n");
		scanf("%d,%d", &coef, &expn);
	}
	/*=========================构建多项式p2==========================*/
	puts("\n");
	printf("请你输入多项式p2的一项（按\t系数，指数\t）输入\n");
	scanf("%d,%d", &coef, &expn);
	while (expn!=0)
	{
		create(p2, coef, expn);
		puts("请你再输入多项式p2的一项格式不变：\n");
		scanf("%d,%d", &coef, &expn);
	}

	p3 = addpoly(p1, p2);
	p = p3->next;
	/*===========================遍历新建好的多项式==================*/
	printf("计算结果为：\t");
	while (p!= NULL)
	{
		printf("%d*X^%d", p->coef, p->expn);
		if (p->next&&p->next->coef>0)
		{
			printf("+");
		}
		p = p->next;
	}
	
	system("pause");
	return 0;
}

void create(Linklist l, int coef, int expn)
{
	Linklist p, q, j;
	p = l->next;
	q = l;
	while (p&&expn>p->expn)
	{
		q = p;
		p = p->next;
	}
	if (p&&expn==p->expn)
	{
		p->coef += coef;

	}
	else
	{
		j = (Linklist)malloc(LENG);
		j->coef = coef;
		j->expn = expn;
		q->next = j;
		j->next = p;
	}

}



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
					pa = pa->next;

				}
				else if (pa->expn == pb->expn)  //pa中的一项与pb中的一项相等时
				{
					if ((pa->coef + pb->coef) != 0)
					{
						q = (Linklist)malloc(LENG);
						q->expn = pa->expn;   //设置指数
						q->coef = pa->coef + pb->coef;   //设置系数为两个多项式对应项的系数之和
						p->next = q;
						p = q;
						pa = pa->next;
						pb = pb->next;
					}
					else
					{
						pa = pa->next;
						pb = pb->next;
					}

				}
				else
				{
					q = (Linklist)malloc(LENG);
					q->expn = pb->expn;     //设置指数为pb中的一项的指数
					q->coef = pb->coef;
					p->next = q;
					p = q;
					pb = pb->next;
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
	return p3;
}