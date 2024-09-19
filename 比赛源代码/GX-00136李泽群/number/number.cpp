#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int ans=0;
	gets(a);
	for(int i=0;i<strlen(a);i++)
		if(a[i]=='1')
			ans++;
		cout<<ans;
		fclose(stdin);
		fclose(stdout);
		return 0;
}