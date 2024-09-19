#include<iostream>
using namespace std;
int a[1005][1005],n,ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)

            a[i][j]+=max(a[i-1][j-1],a[i-1][j]);
        
    }
    for(int i=1;i<=n;i++)
    ans=max(ans,a[n][i]);
    cout<<ans;
}