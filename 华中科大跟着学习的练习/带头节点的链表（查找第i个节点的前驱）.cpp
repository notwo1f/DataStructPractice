#include<stdio.h>
#include<malloc.h>
typedef  int  ElemType;
typedef struct node
{
	ElemType data;
	struct node *next;
	
}node ,*Linklist;
#define LENG sizeof(struct node )

 
 Linklist GetNumLink(Linklist l,int i)
 {
 	int j=0;
 	Linklist p=l;
 	while(p->next!=NULL)
 	{
	 ++j;
	 
	 if(j==i)
	 {
	 	return p;
	 }	
	 p=p->next;
	 }
	 printf("ÄãµÄÎ»ÖÃÓĞÎó£¡"); 
 	
 	
 	return NULL;
 }
