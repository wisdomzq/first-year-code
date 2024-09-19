#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char a[2000005];
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        cin>>a;
        int len=strlen(a),p=0;
        while(p<len)
        {
            if(p==len-1)p++,cout<<"Y"<<endl;
            else
            {
               if(a[p]>='a'&&a[p]<='z')
                {
                   if(a[p]-a[p+1]==32||(a[p]-a[p+1]==1&&a[p]!='a'))
                   p++;
                   else
                   {
                    cout<<"N"<<endl;
                    break;
                   }
                }
                if(a[p]>='A'&&a[p]<='Z')
                {
                    if(a[p+1]-a[p]==32||(a[p+1]-a[p]==1&&a[p]!='Z'))
                   p++;
                   else
                   {
                    cout<<"N"<<endl;
                    break;
                   }
                }
            }
        }
    }
}