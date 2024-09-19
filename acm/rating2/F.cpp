// #include<iostream>
// using namespace std;
// int n,m;
// int main()
// {
//    cin>>n>>m;
//    for(int i=1;i<=n;i++)
// }
#include<iostream>
using namespace std;
int n,m,s[300005],t[300005];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>s[i];
    for(int i=1;i<=m;i++)
        cin>>t[i];
    int i=1;
    long long ans=0;
    while(s[1]==t[i] && i<=m) 
    {
        i++;
        ans++;
    }
    int l=-1,r=-1;
    for(int i=2;i<=n;i++)
        if(s[i]!=s[1])
        {
            l=i;
            break;
        }
    for(int i=n;i>=2;i--)
        if(s[i]!=s[1])
        {
            r=i;
            break;
        }
     
     
    if(r==-1 && i<=m)
    {
        cout<<-1<<endl;
        return 0;
    }
     
     
    int p;
    if(l-2<n-r) p=l-2;
    else p=n-r;
     
    if(i<=m)
    {
        ans+=p;
        int cur=!s[1];
        while(i<=m)
        {
            ans++;
            while(t[i]==cur && i<=m) 
            {
                i++;
                ans++;
            }
            cur=1-cur;
        }
    }

    cout<<ans<<endl;
    return 0;
}