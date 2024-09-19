#include<iostream>
#include<cmath>
using namespace std;
int cal[11]={0};
int main()
{
	int a,n,m,ans=0;
	cin>>a>>n;
	for(int i=1;i<=n;i++)
	{
		cal[i]=a;
		a--;
		if(a<0)a+=10;
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=i;j>=1;j--)
		{   m=cal[i-j+1];
			for(int k=1;k<=j-1;k++)
			m*=10;
			ans+=m;
		}
	}
	cout<<"sum="<<ans<<endl;
}
