#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
int cal(int x,int y,int z)
{
	return x*y+z;
}
int a[110][110];
int main()
{
	freopen("souvenir.in","r",stdin);
	freopen("souvenir.out","w",stdout);
	int t,n,m,ans;
	cin>>t>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=t;j++)
			cin>>a[i][j];
		if(t==1)
		{
			cout<<m;
			return 0;
			}
			if(n==1)
			{
			for(int i=1;i<=t;i++)
			{
					if(a[1][i]<a[1][i+1]&&(i+1)<=t)
					{
						ans=cal(m/a[1][i],a[1][i+1],m%a[1][i]);
						m=ans;
					}
				}
			cout<<ans;
				return 0;}
		fclose(stdin);
	fclose(stdout);
	return 0;		
}

