#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
    int n,m,len,num,base=0,p=0;
    char s[2000],t[2000];
    cin>>n;
    cin>>s>>m;
    len=strlen(s);
    for(int i=len-1;i>=0;i--)
    {
        if(s[i]>='A')num=s[i]-'A'+10;
        else num=s[i]-'0';
        base+=num*pow(n,p);
        p++;
    }
    int leng=0;
    while(base>m)
    {
        num=base%m;
        if(num>9) t[leng]='A'+num-10;
        else t[leng]='0'+num;
        base/=m;
        leng++;
    }
        num=base%m;
        if(num>9) t[leng]='A'+num-10;
        else t[leng]='0'+num;
        for(int i=leng;i>=0;i--)cout<<t[i];

}