#include<iostream>
#include<cmath>
using namespace std;
int gcd(int a, int b){
    return a == b ? a:gcd(a>b ? a-b:a, b>a ? b-a:b);
}
int main()
{
    int x,y,num,ans=0;
    cin>>x>>y;
    num=y/x;
    if(y%x!=0)
    {
        cout<<0;
        return 0;
    }
    for(int i=1;i<=sqrt(num);i++)
       if(num%i==0&&gcd(num/i,i)==1) 
       {
        if(num/i!=i)ans+=2;
        else ans++;
       }
    cout<<ans;
}