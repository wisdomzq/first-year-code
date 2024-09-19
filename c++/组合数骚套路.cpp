#include<iostream>
using namespace std;
long long p;
long long c(long long x,long long y)
{
	if(x==y||y==0) return 1;
	if(x<2*y) y=x-y;
	if(y>x) return 0;
	return c(x,y-1)*(x-y+1)/y;
}
long long c1(long long x,long long y)
{
	long long x1,y1,x2,y2;
	x1=x/p;
	y1=y/p;
	x2=x%p;
	y2=y%p;
	if(y2>x2) return 0;
	if(x1==y1||y1==0) return c(x2,y2)%p;
	else
	return (c1(x1,y1)*c(x2,y2))%p;
}
int main()
{
	long long n,m;
	cin>>n>>m>>p;
	cout<<c1(n,m)%p<<endl;
}
