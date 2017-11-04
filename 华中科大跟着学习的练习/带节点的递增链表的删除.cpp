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
	
	printf("1.构建一个递增的链表\t2.删除链表中含有特定元素的节点\t3.删除特定位置i的节点"); 
	printf("请你输入一个整数");
	scanf("%d",&choose);
	switch (choose)
	{
		case 1:
			{	printf("请你输入一个整数！\n");
				scanf("%d",&e);
				while(e!=EOF)
				{
				create(head,e);
				printf("请你输入一个整数"); 
				scanf("%d",&e);
		
	 					} 
	 					break;
}
		case 2:
			{
				printf("\n请你输入要删除的元素\n:");
				scanf("%d",&e);
				if(DelElem(head,e))
					printf("\n删除成功!");
				else
					printf("\n删除失败！"); 
					break;
				
			}
		case 3:
			{
				//printf("请你输入要删除的元素的位置\n");
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
