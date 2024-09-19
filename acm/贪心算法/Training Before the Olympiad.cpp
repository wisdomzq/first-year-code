#include<iostream>
using namespace std;
#define ll long long
ll num[100005];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        ll ans=0,ji=0;//num统计奇数个数
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>num[i];
            ans+=num[i],ji+=num[i]%2;
            if(i==1)cout<<ans<<" ";
            else cout<<ans-ji/3-(ji%3==1)<<" ";
        }
        cout<<endl;
    }
}