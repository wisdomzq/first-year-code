#include<stdio.h>
#include<stdlib.h>
void func(int *p)
{
	for(int i=0;i<5;i++)
	printf("arr[%d]=%d\n",i,*(p+i));
}
int main()
{
	int a[5]={1,2,3,4,5};
	int *p=a;
	printf("%d\n",*p);
	func(p);
}

