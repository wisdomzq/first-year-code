#include<cstring>
#include<iostream>
using namespace std;
char a[2001],b[2001];
int a1[2001],b1[2001],c1[4005];
int main()
{
    cin>>a>>b;
    memset(a1,0,sizeof(a1));
    memset(b1,0,sizeof(b1));
    memset(c1,0,sizeof(c1));
    int len,lena=strlen(a),lenb=strlen(b);
    len=lena+lenb;
    for(int i=1;i<=lena;i++)  a1[i]=a[lena-i]-'0';
    for(int i=1;i<=lenb;i++)  b1[i]=b[lenb-i]-'0';
    for(int i=1;i<=lena;i++)
    for(int j=1;j<=lenb;j++)
    c1[i+j-1]+=a1[i]*b1[j];
    for(int i=1;i<len;i++)
    {
        if(c1[i]>9)
        c1[i+1]+=c1[i]/10,c1[i]%=10;
    }
    while(c1[len]==0&&len>1)len--;
    for(int i=len;i>=1;i--)cout<<c1[i];
}