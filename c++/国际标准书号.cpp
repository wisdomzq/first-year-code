#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char a[25];
    int len;
    cin>>a;
    len=strlen(a);
    if(len!=13&&len!=17)cout<<"非法的ISBN."<<endl;
    else 
    {
        if(len==13)
        {
            int ans=0,p=0;
            for(int i=0;i<len;i++)
            {
                if(a[i]>='0'&&a[i]<='9')
                {
                    p++;
                    ans+=(a[i]-'0')*(11-p);
                }  
            }
            if(p==10&&(ans%11==0))
                cout<<"合法的10位ISBN."<<endl;
                else cout<<"非法的ISBN."<<endl;
        }
        if(len==17)
        {
            int ans=0,p=0;
            for(int i=0;i<len;i++)
            {
                if(a[i]>='0'&&a[i]<='9')
                {
                    p++;
                    if(p%2==1)
                    ans+=(a[i]-'0')*1;
                    else
                    ans+=(a[i]-'0')*3;
                }  
            }
            if(p==13&&(ans%10==0))
                cout<<"合法的13位ISBN."<<endl;
                else cout<<"非法的ISBN."<<endl;
        }
    }
}