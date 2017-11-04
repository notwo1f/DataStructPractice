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
Linklist GetNumLink(Linklist l,int i);   //�ҵ���I���ڵ�ǰ�Ľڵ�ĵ�ַ
void Insert(Linklist l,ElemType e,int i);

int main(void)
{
	int  choose;
	Linklist head;
	int i,e;
	while(getchar()!=EOF)
	{
	
	printf("1. �Ƚ��ȳ�\t2.�Ƚ����\t 3.����һ��Ԫ��\n ��������һ��ѡ�\t");
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
				printf("���룺\t ����Ԫ��,λ��\t���в���");
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
 	printf("��������һ��Ԫ��");
 	scanf("%d",&e);
 	while(e!=EOF)
 	{
 		p=(Linklist)malloc(LENG);
 		p->data=e;
 		q->next=p;
 		p->next=NULL;
 		q=p;
 		printf("��������һ������");
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
 	printf("��������һ��Ԫ��");
 	scanf("%d",&e);
 	while(e != EOF)
 	{
 		p=(Linklist)malloc(LENG);
 		p->data=e;
 		p->next=head->next;
 		head->next=p;
 		printf("��������һ��Ԫ��");
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
	 printf("���λ������"); 
 	
 	
 	return NULL;
 }
 
 void Insert(Linklist l,ElemType e,int i)//�� ��i��λ��ǰ���в��� 
 {
 	Linklist p=(Linklist)malloc(LENG);
 	Linklist q;
 	
 	p->data=e;
 	q=GetNumLink(l,i);
 	p->next=q->next;
 	q->next=p;
 	
 	
 	
 }
