#include<iostream>
#include<cmath>
using namespace std;
char judge(long long  k)
{
    double cal;
    k--;
    cal=sqrt(1+8*k);
    if(cal==(int)cal) return '1';
    return '0';
}
int main()
{
    long long n,m;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>m;
        cout<<judge(m)<<endl;
    }
}
