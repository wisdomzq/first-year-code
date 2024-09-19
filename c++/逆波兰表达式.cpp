#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    char a[500];
    long double num[100];
    int k,p1=0,p2=-1;
    memset(num,0,sizeof(num));
    gets(a);
    k=strlen(a);
    while(p1<k)
    {
            int m=1;
            if((a[p1]>='0'&&a[p1]<='9')||(a[p1]=='-'&&(a[p1+1]>='0'&&a[p1+1]<='9')))
            {
               if(a[p1]=='-')p1++,m=-1;
               p2++;
               num[p2]=a[p1]-'0';
               p1++;
               while(a[p1]!=' ')
              {
                 num[p2]*=10;
                 num[p2]+=a[p1]-'0';
                 p1++;
              }
              num[p2]*=m;
            }
            if(a[p1]=='+')
            {
                p1++;
                num[p2-1]=num[p2-1]+num[p2];
                p2--;
            }
            if(a[p1]=='-')
            {
                p1++;
                num[p2-1]=num[p2-1]-num[p2];
                 p2--;
            }
            if(a[p1]=='*')
            {
                p1++;
                num[p2-1]=num[p2-1]*num[p2];
                p2--;
            }
            if(a[p1]=='/')
            {
                p1++;
                num[p2-1]=num[p2-1]/num[p2];
                 p2--;
            }
            p1++;
    }
    cout<<num[p2]<<endl;
}