#include<iostream>
#include<cmath>
#define ll long long
using namespace std;
ll x,y,k,wei=0,tmp,ju=2;
int main()
{
   cin>>x>>y>>k;
   x=x%y;
   tmp=x;
   while(wei<k)
   {
    x=tmp*10/y;
    tmp=tmp*10%y;
    wei++;
   }
   cout<<x;
   while(ju--)
   {
    x=tmp*10/y;
    tmp=tmp*10%y;
    cout<<x;
   }
}