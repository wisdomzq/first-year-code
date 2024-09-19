#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
ull base=131;
ull mod=321512533461616;
ull prime=233317;
ull a[10005];
char s[10001];
ull hashi(char p[])
{
    int len=strlen(p);
    ull ans=0;
    for(int i=0;i<len;i++)
    {
         ans=(ans*base+(ull)s[i])%mod+prime;
    }
    return ans;
}
int main()
{
     int n,ans=1;
     cin>>n;
     for(int i=1;i<=n;i++)
     {
        cin>>s;
        a[i]=hashi(s);
     } 
     sort(a+1,a+n+1);
      for(int i=1;i<n;i++)
    {
 	if(a[i]!=a[i+1])
 	ans++;
    }
    cout<<ans;
}