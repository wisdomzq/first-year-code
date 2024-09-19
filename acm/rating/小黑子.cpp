#include<iostream>
#include<cstring>
#include<ctype.h>
using namespace std;
char a[10005];
int main()
{
    cin>>a;
    int len=strlen(a);
    for(int i=0;i<len;i++)
    {
        if((i+3<len)&&(tolower(a[i])=='j')&&(tolower(a[i+1])=='n')&&(tolower(a[i+2])=='t')&&(tolower(a[i+3])=='m'))
        {
            cout<<"yes";
            return 0;
        }
    }
    cout<<"no";
    return 0;
}