#include<iostream>
using namespace std;
#define ll long long
ll a[100005],b[100005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m,l,r;
    cin>>n;
    b[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=b[i-1]+a[i];
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>l>>r;
        cout<<b[r]-b[l-1]<<endl;
    }
}
