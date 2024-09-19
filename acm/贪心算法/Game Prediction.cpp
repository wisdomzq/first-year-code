#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,ci=0;
    while(cin>>m>>n)
    {
        ci++;
        if(n==0&&m==0)break;
        bool cd[1001]={0};
        int maxx=m*n;
        int *card;
        card=new int [n+3];
        for(int i=1;i<=n;i++)cin>>card[i],cd[card[i]]=1;
        sort(card+1,card+1+n,cmp);
        int ans=0;
        while(cd[maxx])maxx--;
        for(int i=1;i<=n;i++)
        {
            if(card[i]>=maxx) ans++;
            else maxx--;
            while(cd[maxx])maxx--;
        }
        // while(card[i]==maxx)
        //    {
        //     i++,ans++,maxx--;
        //     if(i>=n) break;
        //    }
        //    int lans=0;
        // while(i<=n)
        // {
        //     while(maxx>card[i])lans--,maxx--;
        //      while(card[i]==maxx)
        //    {
        //     i++,lans++,maxx--;
        //     if(i>n)break;
        //    } 
        //    if(lans>0) ans+=lans,lans=0;
        // }
           cout<<"Case "<<ci<<": "<<ans<<endl; 
        }
    }
