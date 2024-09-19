#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char a[60],op,b[60];
    int n,k,fu=0;
    cin>>a>>op>>n;
    k=strlen(a);
    bool dot=true;
     for(int i=k;i<61;i++)a[i]='0';
    //正数
    if(a[0]!='-')
    {   cout<<k<<endl;
        for(int i=0;i<k;i++)
    {
        if(a[i]=='.'){
            fu=i;
            dot=false;break;
        }
    }
    if(dot==true)
    {
        cout<<a[0];
        for(int i=1;i<=n;i++)cout<<"0";
        cout<<".00000000"<<endl;   
    }
    else
    {  
        if(n>=0)
        {
            int q=2;
            if(a[0]=='0')cout<<a[2],q++;
            else 
            {
                for(int i=0;i<fu;i++)
                cout<<a[i];
            }   
            for(int i=fu+1;i<=fu+n;i++)cout<<a[i];
            cout<<".";
            int ans=0;
            for(int i=fu+1+n;i<k;i++)
            {
                cout<<a[i],ans++;
                if(ans==8)break;
            }
            if(ans<8)
            for(int i=ans;i<8;i++)cout<<"0";
            cout<<endl;
        }
        else
        {
          cout<<"0.";
          for(int i=1;i<-n;i++)cout<<"0";
          int ans=1;
          cout<<a[0];
          for(int i=2;i<k;i++) 
          {
            cout<<a[i],ans++;
            if(ans==8)break;
          } 
          if(ans<8)
          for(int i=ans-n-1;i<8;i++)cout<<"0";
          cout<<endl;
        }
    }
    }
    //负数
    else
    {
        for(int i=0;i<k-1;i++)a[i]=a[i+1];
        k--;
        for(int i=k;i<61;i++)a[i]='0';
        cout<<"-";
        for(int i=0;i<k;i++)
    {
        if(a[i]=='.'){
            dot=false;break;
        }
    }
    if(dot==true)
    {
        cout<<a[0];
        for(int i=1;i<=n;i++)cout<<"0";
        cout<<".00000000"<<endl;   
    }
    else
    {
        if(n>=0)
        {
            int q=2;
            if(a[0]=='0')cout<<a[2],q++;
            else cout<<a[0];
            for(int i=q;i<=1+n;i++)cout<<a[i];
            cout<<".";
            int ans=0;
            for(int i=2+n;i<k;i++)
            {
                cout<<a[i],ans++;
                if(ans==8)break;
            }
            if(ans<8)
            for(int i=ans;i<8;i++)cout<<"0";
            cout<<endl;
        }
        else
        {
          cout<<"0.";
          for(int i=1;i<-n;i++)cout<<"0";
          int ans=1;
          cout<<a[0];
          for(int i=2;i<k;i++) 
          {
            cout<<a[i],ans++;
            if(ans==8)break;
          } 
          if(ans<8)
          for(int i=ans-n-1;i<8;i++)cout<<"0";
          cout<<endl;
        }
    }
    }
    
}