#include<iostream>
using namespace std;
int be,m,k;
bool check(int mod)
{
    int p=(be+m-1)%mod;
    if(p>=k)
    {
        be=p;
        return 1;
    }
    return 0;
}
int main()
{
    bool judge;
    cin>>k;
    m=k+1;
    while(1)
    {
        be=0;
        judge=false;
        for(int i=0;i<k;i++)
        {
            while(!check(2*k-i))
            {
                judge=true;break;
            }
        }
        if(!judge) break;
        m++;
    }
    cout<<m;
}