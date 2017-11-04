#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h> 
typedef int ElemType;
typedef struct  node 
{
	ElemType data;
	struct node * next;
}node,*Linklist;
#define LENG sizeof(struct node) 
int create(Linklist l,ElemType e);
int link(Linklist La,Linklist Lb);
int main(void)
{
	Linklist  a=(Linklist)malloc(LENG),b=(Linklist)malloc(LENG);
	a->next= NULL;
	b->next = NULL;
	ElemType e1,e2;
	
	printf("请你输入一个用于整数创建链表La:\n");
	scanf("%d",&e1);
	while(e1!=EOF)
	{
		create(a,e1);
		printf("\n请你输入一个用于整数创建链表La:\n");
		scanf("%d",&e1);
		
	 } 
	 	printf("请你输入一个用于整数创建链表Lb:\n");
	scanf("%d",&e2);
	while(e2!=EOF)
	{
		create(b,e2);
		printf("\n请你输入一个整数用于创建链表Lb:\n");
		scanf("%d",&e2);
	 } 
	 if(link(a,b))
	 {
	 	printf("link成功！\n");
	 	
	 }
	 else
	 {
	 	printf("link 失败"); 
	 }
	 
	 Linklist p;
	 p=a->next;
	 while(p)
	 {
	 	printf("%d\t",p->data);
	 	p=p->next;
	 }
	 printf("\n");
	
	
	return 0;
}



int create(Linklist l,ElemType e)  // 创建一个递插入算法增的链表的 
{
	Linklist p,q;
	q=l;
	p=l->next;
	Linklist j=(Linklist)malloc(LENG);
	while(p&&e>p->data)
	{
		q=p; 
		p=p->next;
	}
	j->data=e;
	j->next=p;
	q->next=j;
	return 1;
	
	
	
	
}


int link(Linklist La,Linklist Lb)
{
	Linklist pa,pb,pc;
	pa=La;
	pb=pa->next;
	pc=Lb->next;
	while(pb&&pc)
	{
		if(pb->data <= pc->data)
		{
			pa->next=pb;
			pa=pb;
			pb=pb->next; 
		}
		else
		{
			pa->next=pc;
			pa=pc;
			pc=pc->next;
		}
	}
	if(pb)
	{
		pa->next=pb;
	}
	else
	{
		pa->next=pc;
	}
	return 1;
}



