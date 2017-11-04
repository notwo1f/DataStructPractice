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
Linklist addpoly(Linklist p1, Linklist p2);   //�½�һ������ʵ�ֶ���ʽ�ļӷ����������½�������ĵ�ַ 
void create(Linklist l, int coef, int expn);  //ʵ��ÿ��������Ľڵ��㷨�� 

int main(void)
{
	Linklist p1, p2, p3, p;    //�������ʽ p1,p2,p3
	int coef, expn;
	p1 = (Linklist)malloc(LENG);
	p1->next = NULL;
	
	p2 = (Linklist)malloc(LENG);
	p2->next = NULL;
	/*===========================��������ʽp1=========================*/
	printf("�����������ʽp1��һ���\tϵ����ָ��\t������\n");
	scanf("%d,%d", &coef, &expn);
	while (expn != 0)
	{
		create(p1, coef, expn);
		puts("�������������ʽp1��һ���ʽ���䣺\n");
		scanf("%d,%d", &coef, &expn);
	}
	/*=========================��������ʽp2==========================*/
	puts("\n");
	printf("�����������ʽp2��һ���\tϵ����ָ��\t������\n");
	scanf("%d,%d", &coef, &expn);
	while (expn!=0)
	{
		create(p2, coef, expn);
		puts("�������������ʽp2��һ���ʽ���䣺\n");
		scanf("%d,%d", &coef, &expn);
	}

	p3 = addpoly(p1, p2);
	p = p3->next;
	/*===========================�����½��õĶ���ʽ==================*/
	printf("������Ϊ��\t");
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
					pa = pa->next;

				}
				else if (pa->expn == pb->expn)  //pa�е�һ����pb�е�һ�����ʱ
				{
					if ((pa->coef + pb->coef) != 0)
					{
						q = (Linklist)malloc(LENG);
						q->expn = pa->expn;   //����ָ��
						q->coef = pa->coef + pb->coef;   //����ϵ��Ϊ��������ʽ��Ӧ���ϵ��֮��
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
					q->expn = pb->expn;     //����ָ��Ϊpb�е�һ���ָ��
					q->coef = pb->coef;
					p->next = q;
					p = q;
					pb = pb->next;
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
	return p3;
}