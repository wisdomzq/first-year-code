#include<iostream>
using namespace std;
int main()
{
	int n,k,m,ans,p;
	m=0,ans=0,p=5;
	cin>>n;
	k=n;
	while(k>=5)
	{
		k/=5;
		m++;
	}
	for(int i=1;i<=m;i++)
	{   
	    k=n;
		ans+=k/p;
		p*=5;
	}
	cout<<ans<<endl;
}
