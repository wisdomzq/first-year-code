#include<iostream>
#include<algorithm>
using namespace std;
struct stick{
    int l,w;
};
bool cmp(stick a,stick b)
{
    if(a.l==b.l) return a.w<b.w;
    return a.l<b.l;
}
bool use[5005];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int re_wid,ans=0;
        struct stick *s;
        s=new stick [n+2];
        for(int i=1;i<=n;i++)cin>>s[i].l>>s[i].w,use[i]=0;
        sort(s+1,s+1+n,cmp);
        
        for(int i=1;i<=n;i++)
        {
              if(use[i]==0){
                   re_wid=s[i].w;
                   for(int j=i+1;j<=n;j++)
                   {
                    if(s[j].w>=re_wid&&use[j]==0)re_wid=s[j].w,use[j]=1;
                   }
              }
        }
        for(int i=1;i<=n;i++)if(use[i]==0)ans++;
        cout<<ans<<endl;
        delete []s;

    }
}