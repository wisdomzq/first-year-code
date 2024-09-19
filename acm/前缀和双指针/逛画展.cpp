#include<iostream>
using namespace std;
int a[1000005],b[2005],be,en,num,ans,be1,en1;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    be=1,en=1,num=1;b[a[1]]=1,ans=1000005;
    while(be<=en&&en<=n)
    {
        if(num==m)
        {
            if(ans>en-be+1)ans=en-be+1,be1=be,en1=en;
            b[a[be]]--;
            if(b[a[be]]==0)num--;
            be++;
        }
        else{
            en++;
            b[a[en]]++;
            if(b[a[en]]==1)num++;
        }
    }
    cout<<be1<<" "<<en1;
}