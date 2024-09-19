#include<iostream>
using namespace std;
#define ll long long
#define MOD 998244353 
char a[500005];
int n,m;
ll tot;
ll cal(int x)
{
    ll ans=x*x*x+3*x*x+2*x;
    ans/=6;
    return ans%MOD;
}
void find0(int h,int r)
{
    if(h>=r)return;
    ll p=0;
    bool find=false;
    while(a[h]!='0'&&h<r)h++;
    for(int i=h;i<=r;i++)
    {
        if(a[i]=='w')
        find=true;
        if(a[i]=='0'&&find==true)
        p++,find=false;
        if(a[i]==')')tot+=cal(p),tot%=MOD;
        if(a[i]=='(')find0(i,r);
    }

}
int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0),cout.tie(0);
   cin>>n>>m;
   cin>>a;
   int num,be,en;
   while(m--)
   {
    cin>>num;
    char op;
    if(num==1)
    {
    cin>>be>>en;
    be--,en--;
    cin>>op;
        if(en>=n)en=n-1;
        if(be>=n)be=n-1;
    for(int i=be;i<=en;i++)a[i]=op;
 
    }
    if(num==2)
    {
        tot=0;
        cin>>be>>en;
        be--,en--;
        if(en>=n)en=n-1;
        if(be>=n)be=n-1;
        while(a[be]!='('&&be<en)be++;
        find0(be,en);
        cout<<tot<<endl;
    }
   }
} 