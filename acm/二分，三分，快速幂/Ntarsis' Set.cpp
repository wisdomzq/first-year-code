#include<iostream>
#define ull unsigned long long
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        ull a[200005],ans=1,mark=0;
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++)cin>>a[i];
        while(k--)
        {
           ans+=mark;
           while(mark<n&&a[mark]<=ans)
           {
              ans++;
              mark++;
           }
        }
        cout<<ans<<endl;
    }
}