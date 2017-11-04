#include<stdio.h>
#include<malloc.h>
typedef  int  ElemType;
typedef struct node
{
	ElemType data;
	struct node *next;
	
}node ,*Linklist;
#define LENG sizeof(struct node )

Linklist f_create();
Linklist b_create();
Linklist GetNumLink(Linklist l,int i);   //找到第I个节点前的节点的地址
void Insert(Linklist l,ElemType e,int i);

int main(void)
{
	int  choose;
	Linklist head;
	int i,e;
	while(getchar()!=EOF)
	{
	
	printf("1. 先进先出\t2.先进后出\t 3.插入一个元素\n 请你输入一个选项：\t");
	scanf("%d",&choose);
	switch (choose)
	{
		case 1:
		head=f_create();
		break;
		
		case 2:
			head=b_create();
			break;
		case 3:
			{
				printf("输入：\t 插入元素,位置\t进行插入");
				scanf("%d,%d",&e,&i);
				Insert(head,e,i);
				
			}
	}
	Linklist p=head->next;
	while(p!=NULL)
	{
		printf("%d\t",p->data);
		p=p->next;
	}
	puts("\n");
}
	return 0;
 } 
 
 Linklist f_create()
 {
 	Linklist head,p,q;
 	int e;
 	head=(Linklist)malloc(LENG);
 	q=head;
 	printf("请你输入一个元素");
 	scanf("%d",&e);
 	while(e!=EOF)
 	{
 		p=(Linklist)malloc(LENG);
 		p->data=e;
 		q->next=p;
 		p->next=NULL;
 		q=p;
 		printf("请你输入一个整数");
		scanf("%d",&e);
		
		 
 		
 		
	 }
	 
	 return head;
 	
 }
 
 
 Linklist b_create()
 {
 	Linklist head,p;
 	int e;
 	head=(Linklist)malloc(LENG);
 	head->next=NULL;
 	printf("请你输入一个元素");
 	scanf("%d",&e);
 	while(e != EOF)
 	{
 		p=(Linklist)malloc(LENG);
 		p->data=e;
 		p->next=head->next;
 		head->next=p;
 		printf("请你输入一个元素");
 		scanf("%d",&e);
	 }
	 
	 
	 return head;
	 
 	}
 	
 	 Linklist GetNumLink(Linklist l,int i)
 {
 	int j=0;
 	Linklist p=l;
 	
 	while(p->next!=NULL&&i>0)
 	{
	 ++j;
	
	 if(j==i)
	 {
	 	return p;
	 }	
	  p=p->next;
	 }
	 printf("你的位置有误！"); 
 	
 	
 	return NULL;
 }
 
 void Insert(Linklist l,ElemType e,int i)//在 第i个位置前进行插入 
 {
 	Linklist p=(Linklist)malloc(LENG);
 	Linklist q;
 	
 	p->data=e;
 	q=GetNumLink(l,i);
 	p->next=q->next;
 	q->next=p;
 	
 	
 	
 }
