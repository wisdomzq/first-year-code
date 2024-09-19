#include<iostream>
#include<cmath>
using namespace std;
int x;
int onefig(int n)
{
	int n1;
	n1=pow(x+1,n-1);
	return n1; 
}
int main()
{
	int a,b,cha,i,j,na,nb;
	bool ta,tb;
	ta=true;
	tb=true;
	i=0,j=0,na=0,nb=0;
	int a1[11],b1[11];
	cin>>x>>a>>b;
	while(a>0)
	{
		i++;
		a1[i]=a%10;
		a/=10;
	}
	while(b>0)
	{
		j++;
		b1[j]=b%10;
		b/=10;
	}
	//取每一位数
	for(int p=i;p>=2;p--)
	{
		if(a1[p]<=x)
		na+=a1[p]*onefig(p); 
		else
		{
			na+=(x+1)*onefig(p); 
			break;
		}
	 } 
	for(int p=j;p>=2;p--)
	{
		if(b1[p]<=x)
		nb+=b1[p]*onefig(p); 
		else
		{
		nb+=(x+1)*onefig(p);
		break;
		}
	 } 
	 for(int p=2;p<=j;p++)
	{
		if(b1[p]>x)
		tb=false;
	}
	if(tb==true)
	{
	for(int p=0;p<=b1[1];p++)
	{
		if(p<=x)nb++;
	}	
	}
	for(int p=2;p<=i;p++)
	{
		if(a1[p]>x)
		ta=false;
	}
	if(ta==true)
	{
	for(int p=0;p<=a1[1];p++)
	{
		if(p<=x)na++;
	}	
	}
	if((ta==true)&&(a1[1]<=x))nb++;
	cout<<nb-na<<endl;
}
