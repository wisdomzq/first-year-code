#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int member1;
	int member2;
	char member[101];
	double member4;
}b;
b fu={
		1,
		2,
		"member",
		4.0
	}; 
void func()
{
	printf("%d\n%d\n%s\n%f\n",fu.member1,fu.member2,fu.member,fu.member4);
}
int cal(int a,int b)
{
	return a+b;
}

int main()
{
	func();
		printf("%d\n",cal(fu.member1,fu.member2));
}
