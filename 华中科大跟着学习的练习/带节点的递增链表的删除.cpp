#include<stdio.h>
#include<malloc.h> 
typedef int ElemType;
typedef struct  node 
{
	ElemType data;
	struct node * next;
}node,*Linklist;
#define LENG sizeof(struct node)
int DelElem(Linklist l,ElemType e);
int DelElemn(Linklist l,int i);

int create(Linklist l,ElemType e);
int main(void)
{
	Linklist head=(Linklist)malloc(LENG);
	head->next=NULL;
	ElemType e;
	Linklist p;
	int choose;
	while(getchar()!=EOF)
	{
	
	printf("1.����һ������������\t2.ɾ�������к����ض�Ԫ�صĽڵ�\t3.ɾ���ض�λ��i�Ľڵ�"); 
	printf("��������һ������");
	scanf("%d",&choose);
	switch (choose)
	{
		case 1:
			{	printf("��������һ��������\n");
				scanf("%d",&e);
				while(e!=EOF)
				{
				create(head,e);
				printf("��������һ������"); 
				scanf("%d",&e);
		
	 					} 
	 					break;
}
		case 2:
			{
				printf("\n��������Ҫɾ����Ԫ��\n:");
				scanf("%d",&e);
				if(DelElem(head,e))
					printf("\nɾ���ɹ�!");
				else
					printf("\nɾ��ʧ�ܣ�"); 
					break;
				
			}
		case 3:
			{
				//printf("��������Ҫɾ����Ԫ�ص�λ��\n");
				//scanf("%d",&location);
			}
		default:
			
	 p=head->next;
	  while(p!=NULL)
	 {
	 	printf("%d\t",p->data);
	 	p=p->next;
	 }
			}
	 } 
	
	 while(p!=NULL)
	 {
	 	printf("%d\t",p->data);
	 	p=p->next;
	 }
	 puts("\n");

	
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

int DelElem(Linklist l,ElemType e)
{
	Linklist p,q;
	p=l->next;
	q=l;
   while(p&&p->data!=e)
   {
   	q=p;
   	p=p->next;
   }
   
   q->next=p->next;
   free(p);
   
	
	
	
	
	return 1;
}
