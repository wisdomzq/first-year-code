#include<iostream>
using namespace std;
int a[200005],n,l,r,maxn,minn;
bool judge=false;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
         cin>>n;
         for(int i=1;i<=n;i++)cin>>a[i];
         minn=1,maxn=n,l=1,r=n;
         judge=true;
         while(1)
         {
            if(l>r)
            {
                judge=false;cout<<-1<<endl;break;
            }
            if(a[r]==maxn){
                maxn--;r--;continue;
            }
            if(a[r]==minn)
            {
                minn++;r--;continue;
            }
            if(a[l]==maxn)
            {
                maxn--;l++;continue;
            }
            if(a[l]==minn)
            {
                minn++;l++;continue;
            }
            break;
         }
         if(judge)cout<<l<<" "<<r<<endl;
             }
}
