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
int main(void)
{
	Linklist head=(Linklist)malloc(LENG);
	head->next=NULL;
	ElemType e;
	Linklist p;
	printf("请你输入一个整数"); 
	scanf("%d",&e);
	while(e!=EOF)
	{
		create(head,e);
		printf("请你输入一个整数"); 
		scanf("%d",&e);
		
	 } 
	 p=head->next;
	 while(p!=NULL)
	 {
	 	printf("%d\t",p->data);
	 	p=p->next;
	 }
	
	
	return 0;
}

int create(Linklist l,ElemType e)
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
