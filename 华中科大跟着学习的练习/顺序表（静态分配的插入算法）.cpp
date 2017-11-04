#include<stdio.h>
typedef int ElementType;
#define  MAX 10
typedef struct {
	 ElementType a[MAX];
	 int length;
}Sq,*Sqlist;

int Insert(Sqlist l,int i,ElementType e);
int main(void)
{
	Sq b;
	b.a[0]=1;
	b.a[1]=2;
	b.a[2]=3;
	b.a[3]=4;
	b.length=4;
	int location;
	ElementType e;
	scanf("%d,%d",&location,&e);
	if(Insert(&b,location,e))
	{
		for(int i=0;i<b.length;++i)
		{
			printf("%d",b.a[i]);
		}
	}
	else
	{
		puts("wrong");
	}
	
	return 0;
 } 
 
int Insert(Sqlist l,int i,ElementType e)
{
	if(i<1||i>l->length+1)
	{
		printf("location wrong");          //检验位置是否正确 
		return 0;
	}
	if(l->length>=MAX)                    //检验表是否已经填满 
	{
		puts("overflow!");
		return 0;
	}
	else
	{
		for(int b=l->length-1;b>=i-1;--b)     //执行插入算法 ，从最后一个元素开始往后移，直到要插入的位置 
		{
			l->a[l->length]=l->a[l->length-1];
		}
		l->a[i-1]=e;
		return 1;
	}
 } 
