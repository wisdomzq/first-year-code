#include<iostream>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
ll w[100005],n,p,q,tmp,wei,minn=1000000000005;
int main()
{
    cin>>n>>p>>q;
    for(int i=1;i<=n;i++)cin>>w[i];
    sort(w+1,w+1+n);
    if(p>q) tmp=q,q=p,p=tmp;//保证q>p
    for(int i=1;i<=n;i++)
    {
        tmp=q*w[i]/p;
        wei=lower_bound(w+1, w+1+n,tmp)-w;
        minn=min(minn,min(min(abs(q*w[i]-p*w[wei]),abs(q*w[i]-p*w[wei-1])),abs(q*w[i]-p*w[wei+1])));
        if(wei==n)break;
    }
    cout<<minn;
    

}