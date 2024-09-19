#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int k;
        if(i==1)
        cin.ignore();
        char a[30];
        memset(a,0,sizeof(a));
        int ans=0;
        bool big,small,num,other;
        big=small=num=other=false;
        gets(a);
        k=strlen(a);
        if(k<6)cout<<"Not Safe"<<endl;
        else
        for(int j=0;j<k;j++)
        {
            if((a[j]>='A')&&(a[j]<='Z'))big=true;
            else{
                 if((a[j]>='a')&&(a[j]<='z'))small=true;
                 else{
                    if((a[j]>='0')&&(a[j]<='9'))num=true;
                    else
                    other=true;
                 }
            }
        }
        if(other==true)ans++;
        if(num==true)ans++;
        if(big==true)ans++;
        if(small==true)ans++;
       if(ans==1)cout<<"Not Safe"<<endl;
       if(ans==2)cout<<"Medium Safe"<<endl;
       if(ans>=3)cout<<"Safe"<<endl;
    }
}