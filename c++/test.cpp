#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int ans[101];
int a[101],n=0,k;
int i,j,rec[101],newn[101];
char ch[101];
bool judge(int k) //计算是否循环 
{
    int s[102];
    memset(s,0,sizeof(s));
    for (int i=1; i<=n; i++)
      for (int j=1; j<=newn[0]; j++)
        if (i+j-1 > k) break;
        else
        {
           s[i+j-1]+=a[i]*newn[j];
           s[i+j]+=s[i+j-1]/10;
           s[i+j-1]%=10;
        }
    if (s[k] == a[k]) return 1;
    return 0;
}
void mul() //累乘 关键思路 某一位出现11次，默认不循环
{
    int s[102];
    memset(s,0,sizeof(s));
    for (int i=1; i<=rec[0]; i++)
      for (int j=1; j<=newn[0]; j++)
        if (i+j-1 <= n)
        {
           s[i+j-1]+=rec[i]*newn[j];
           s[i+j]+=s[i+j-1]/10;
           s[i+j-1]%=10;
        }
    if (rec[0]+newn[0]-1 >= n) s[0]=n;
    else if (s[rec[0]+newn[0]] > 0) s[0]=rec[0]+newn[0];
    else s[0]=rec[0]+newn[0]-1;
    for (int i=0; i<=s[0]; i++)
      newn[i] = s[i];
}
void calc(int x) //单精*高精 
{    
    for (int i=1; i<=ans[0]; i++)
      ans[i]*=x;
    for (int i=1; i<=ans[0]; i++)
    {
        ans[i+1]+=ans[i]/10;
        ans[i]%=10;
    }
    while (ans[ans[0]+1] > 10)
    {
        ans[0]++;
        ans[ans[0]+1]+=ans[ans[0]]/10;
        ans[ans[0]]%=10;
    }
    if (ans[ans[0]+1] > 0) ans[0]++;
}
int main()
{
    scanf("%c",&ch[++n]);
    while (ch[n] != ' ')
      scanf("%c",&ch[++n]);
    scanf("%d",&k);
    n--;
    for (i=1; i<=n; i++)
      a[i]=ch[n+1-i]-'0';
    if (n > k) n=k;
    if (n < k) 
    {
      for (i=n+1; i<=k; i++)
        a[i] = 0;
      n = k;
    } //init
    for (i=1; i<=n; i++)
      rec[i]=a[i]; //last one 加数 
    rec[0]=n; 
    for (i=1; i<=n; i++)
      newn[i]=a[i]; 
    newn[0]=n; //rec^x (累乘器)
    ans[0]=1; ans[1]=1;
    for (i=1; i<=k; i++)
    {
        if (judge(i)) continue; //第i位相等 
        else for (j=2; j<=11; j++)
        {
            mul(); //累乘器 
            if (judge(i)) break;
        }
        if (j > 11) //无解 
        {
            cout<<-1<<endl;
            return 0;
        }        
        calc(j); //ans=ans*j;
        for (j=newn[0]; j>=0; j--)
          rec[j]=newn[j];
    }
    for (i=ans[0]; i>=1; i--)
      cout<<ans[i];
      cout<<endl;
    return 0;
}