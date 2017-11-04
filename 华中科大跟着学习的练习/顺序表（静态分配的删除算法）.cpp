#include<stdio.h>

typedef int ElementType;
#define  MAX 10
typedef struct {
	 ElementType a[MAX];
	 int length;
}Sq,*Sqlist;
int Del(Sqlist l,int i);
 

int main(void)
{
	Sq b;
	b.a[0]=0;
	b.a[1]=1;
	b.a[2]=2;
	b.a[3]=3;
	b.length=4;
	int location;
	scanf("%d",&location);
	
	if(Del(&b,location))
	{
		printf("delete sucussfully!");
		
	}
	else
	{
		
		printf("something wrong!");
	}
	
	for(int i=0;i<b.length;++i)
	{
		printf("%d",b.a[i]);
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
 } 
 
 int Del(Sqlist l,int i)
 {
 	if(i<1||i>l->length)
 	{
 		printf("your location has problems");
 		
 		return 0;
	 }
	 
	for(int b=i;b<=l->length-1;++b)
	{
		l->a[b-1]=l->a[b];
		
	}
	
	--l->length;
	return 1;
 	
 	
 	
 	
 }
