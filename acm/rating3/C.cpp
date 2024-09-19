#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        int n,one=0,num;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>num;
            if(num==1)one++;
        }
        if(one&1)cout<<"2B"<<endl;
        else cout<<"9S"<<endl;
        
    }
}