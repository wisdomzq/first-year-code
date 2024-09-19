#include<iostream>
#include<algorithm>
using namespace std;
struct cow{
    int begin,end;
}c[30000];
bool cmp(cow a,cow b)
{
    return a.end>b.end;
}
int main()
{
    int n,t,ans=0;
    cin>>n>>t;
    for(int i=1;i<=n;i++)cin>>c[i].begin>>c[i].end;
    sort(c+1,c+1+n,cmp);
    // if(c[1].end<t)cout<<-1;
    for(int i=1,j=1;i<=n;)
    {
        int minn=1000005;
        while(j<=n&&c[j].end>=t)
        {
            minn=min(minn,c[j].begin);
            j++;
        }
        if(minn>t)
            break;
        ans++;
        if(minn<=1)
        {
            cout<<ans;return 0;
        }
        i=j;t=minn-1;
    }
    cout<<-1;
   
}
