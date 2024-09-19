#include<iostream>
using namespace std;
int main()
{
    int n,p,q,tmp,ans=2;
    cin>>n;
    p=1,q=1;
    while(1)
    {
       tmp=p,p=q%n,q=(tmp+q)%n;
       if(p==0&&q==1)
       {
        cout<<ans;
        return 0;
       }
       ans++;
    }
}