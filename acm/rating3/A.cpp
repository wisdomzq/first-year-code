#include<iostream>
#include<cstring>
using namespace std;
char a[105];
int main()
{
    cin>>a;
    int len=strlen(a);
    for(int i=len-1;i>=0;i--)
    {
        if(a[i]=='a')
        {
            cout<<i+1;
            return 0;
        }
        
    }
    cout<<-1;
}