#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
bool judge(long long x)
{
    long long y=sqrt(x);
    for(long long i=2;i<=y+1;i++)
    if(x%i==0)return 0;
    return 1;
}
int main()
{
    int n;
    cin>>n;
    if(n==1)cout<<"None";
    if(n>=2)cout<<3<<endl;
    int p=3;
    while(n>2&&p<=n)
    {
       long long num=pow(2,p)-1;
       if(judge(num)==1)cout<<num<<endl;
       p+=2;
    }
    
}