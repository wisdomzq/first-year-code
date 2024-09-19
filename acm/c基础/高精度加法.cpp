#include<bits/stdc++.h>
#include<cstring>
#include<iostream>
using namespace std;
char a[1001],b[1001];
int a1[1001],b1[1001],c1[1001];
int main()
{
    cin>>a>>b;
    memset(a1,0,sizeof(a1));
    memset(b1,0,sizeof(b1));
    memset(c1,0,sizeof(c1));
    int len,lena=strlen(a),lenb=strlen(b);
    len=(lena>lenb)?lena:lenb;
    for(int i=0;i<lena;i++)  a1[i]=a[lena-i-1]-'0';
    for(int i=0;i<lenb;i++)  b1[i]=b[lenb-i-1]-'0';
        for(int i=0;i<len;i++)
	 {
	 	c1[i]+=a1[i]+b1[i];
	 	c1[i+1]=c1[i]/10;
	 	c1[i]%=10;
	 }
     if(c1[len]==0)len--;
     for(int i=len;i>=0;i--)cout<<c1[i];
}