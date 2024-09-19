#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
int a[300000],b[300000],c[300000],d[300000],e[100000];
string f[100001];
int main()
{
	freopen("work.in","r",stdin);
	freopen("work.out","w",stdout);
	int n,m,q,w=0;
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++)
		cin>>a[i]>>b[i];
	for(int i=1;i<=q;i++)
		cin>>c[i]>>d[i];
	for(int i=1;i<=m;i++)
		if(a[i]==1)e[++w]=b[i];
			for(int i=1;i<=q;i++)
				f[i]="No";
		for(int i=1;i<=q;i++)
		{
			for(int j=1;j<=w;j++)
				if(c[i]==e[j]||c[i]==1)
					f[i]="Yes";
			}
	for(int i=1;i<=q;i++)
		cout<<f[i]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}