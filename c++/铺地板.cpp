#include<iostream>
using namespace std;
int a[1001][1001];
void put1(int k)
{
	if(k>=10)cout<<" "<<k;
	else cout<<"  "<<k;
}
void put2(int k)
{
	if(k>=10)cout<<k;
	else cout<<" "<<k;
}
int main()
{
	int n,m,k,p;
	p=1;
	cin>>n;
	k=1;
	a[1][1]=k;
	m=2;
	while(m<=n)
	{
		m++;
		for(int i=1;i<=m-1;i++)
		{
			k++;
			if(m%2==1) 
			a[i][m-i]=k;
			else
			a[m-i][i]=k;
		}
	}
	while(m<2*n)
	{
		m++;
		p++;
		for(int i=p;i<=n;i++)
		{
			k++;
			if(m%2==1)
			a[i][m-i]=k;
			else
			a[m-i][i]=k;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(j==1)put2(a[i][j]);
			else put1(a[i][j]);
			if(j==n)cout<<endl;
		}
	}
}
