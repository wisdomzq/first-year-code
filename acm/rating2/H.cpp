#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define ll long long
vector<int> out[100005];
map<ll,int> m;
int n,q,x,y,dis;
bool tmp,visit[100005]={0};
int search(int be,int en)
{
    ll k;
    if(be>en) k=en*100000+be;
        else k=be*100000+en;
    map<ll,int>::iterator it;
     it=m.find(k);
    if(it==m.end())
    {
        int minn=100000005;
    for(int i=0;i<out[be].size();i++)
    {
        if(visit[out[be][i]])continue;
        visit[out[be][i]]=1;
        if(out[be][i]==en)    return 1;
        // cout<<out[be][i]<<" "<<en<<endl;
        minn=min(search(out[be][i],en),minn);
    }
    return minn+1;
    }
    else
    return it->second;
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n-1;i++)
    {
        cin>>x>>y;
        out[x].push_back(y),out[y].push_back(x);
    }
    while(q--)
    {
       ll jmap;
       for(int i=1;i<=n;i++)visit[i]=0;
        cin>>x>>y;
        dis=search(x,y);
        if(x>y) jmap=y*100000+x;
        else jmap=x*100000+y;
        m[jmap]=dis;
        if(dis&1) cout<<"Road"<<endl;
        else cout<<"Town"<<endl;
    }
}