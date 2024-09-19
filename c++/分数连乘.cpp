#include<iostream>
using namespace std;
long long gcd(long long p,long long q)
{
	long long m,n,k;
	if(p>q)
	n=p,m=q;
	else 
	n=q,m=p;
	if(n%m==0||m%n==0)	
		m=m<n?m:n;
	while((k=n%m)!=0)
	{	
		n=m;
		m=k;
	}
	return m;
}
int main()
{
	int x; 
	long long a[10001],b[100001],a1,b1,l;
	a1=1,b1=1;
	cin>>x;
	for(int i=1;i<=x;i++)
	cin>>a[i]>>b[i];
	for(int i=1;i<=x;i++)
	if(a[i]==0)
	{
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=x;j++)
		{
			l=gcd(a[i],b[j]);
			a[i]/=l;
			b[j]/=l;
		}
	}
    for(int i=1;i<=x;i++)
    	a1*=a[i],b1*=b[i];
    if(a1%b1==0)cout<<a1/b1<<endl;
    else
    {
   	l=gcd(a1,b1);
	a1/=l;
    b1/=l;
    cout<<a1<<"/"<<b1<<endl;
	}
}
