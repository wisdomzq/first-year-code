#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
char a,k;
int b,c,d;
scanf("%d",&b);
scanf(" %c",&a);
k=a+2*b+1;
for(int j=1;j<=b+1;j++)
{
d=2*(b+1-j);
for(int i=1;i<=d;i++)printf(" ");
for(int q=1;q<=j;q++)
{
if(a+d>'Z')d-=26;
if(a+d<'A')d+=26;
printf("%c",a+d);d++;
}
if((2*j-3)<=0)
{
printf("\n");continue;
}
for(int m=1;m<=(2*j-3);m++)printf(" ");
if(k>'Z')k-=26;
if(k<'A')k+=26;
printf("%c",k);
k=k+1;
printf("\n");
}
k=k-1;
for(int j=b;j>=1;j--)
{if(k>'Z')k-=26;

k=k-1;
d=2*(b+1-j);
for(int i=1;i<=d;i++)printf(" ");
for(int q=1;q<=j;q++)
{
	if(a+d>'Z')d-=26;
	if(a+d<'A')d+=26;
printf("%c",a+d);d++;
}
if((2*j-3)<=0)
{
printf("\n");continue;
}
for(int m=1;m<=(2*j-3);m++)printf(" ");
if(k<'A')k+=26;
printf("%c",k);
printf("\n");
}
}
