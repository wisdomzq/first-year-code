#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char a[200],op,b[200],c[200];
    int n,k,fu=0;
    cin>>a>>op>>n;
    k=strlen(a);
    for(int i=0;i<k;i++)
    if(a[i]=='.')
    {
        fu=i;break;
    }
    if(fu==0)
    {
        for(int i=0;i<k;i++)b[i]=a[i];
        for(int i=k;i<200;i++)b[i]='0';
    }
    else{
        for(int i=0;i<fu;i++)
    b[i]=a[i];
    for(int i=fu+1;i<k;i++)
    b[i-1]=a[i];
     for(int i=k-1;i<200;i++)b[i]='0';
    }
    //开始输出
    if(n>=0)
    {
      if(fu!=0) 
      {
        for(int i=0;i<fu+n;i++)c[i]=b[i];
    c[fu+n]='.';
    for(int i=fu+n;i<=fu+n+7;i++)c[i+1]=b[i];
    int p1=0;
    if(c[0]=='-')
    {
        p1=1;
        while(c[p1]=='0'&&c[p1+1]!='.')p1++;
        cout<<"-";
        for(int i=p1;i<=fu+n+8;i++)cout<<c[i]; 
    }
    else
    {
       while(c[p1]=='0'&&c[p1+1]!='.')p1++; 
       for(int i=p1;i<=fu+n+8;i++)cout<<c[i]; 
    }
      }
      //排除没有小数点的情况
      else
      {
        for(int i=0;i<k+n;i++)cout<<b[i];
        cout<<".00000000";
      }
    }
    if(n<0)
    {
        if(fu!=0)
        {
            if(b[0]=='-')fu--;
        if((fu+n-1)>=0)
        {
           int p3=0;
            while(b[p3]=='0')p3++;
            for(int i=p3;i<=fu+n-1;i++)cout<<b[i];
            cout<<".";
            for(int i=fu+n;i<=fu+n+7;i++)cout<<b[i];
        }
        else
        {
            int ji=0,ans=0;
            if(b[0]=='-')cout<<b[0],ji=1;
            cout<<"0.";
            for(int i=1;i<=-n-fu;i++)
            {
                cout<<"0",ans++;
                if(ans==8)break;
            }
            for(int i=ans+1;i<=8;i++)
            {
                 cout<<b[i-ans-1+ji];
            }
        }
        }
        else 
        {
            if(b[0]!='-')
            {
               if(k+n>0)
               {
                for(int i=0;i<=k+n-1;i++)cout<<b[i];
                cout<<".";
                for(int i=k+n;i<=k+n+7;i++)cout<<b[i];
               } 
               else{
                int p2=0;
                cout<<"0.";
                for(int i=0;i<-k-n;i++)cout<<"0",p2++;
                for(int i=p2;i<8;i++)cout<<b[i-p2];
               }
            }
            else
            {
                cout<<"-";
                for(int i=0;i<200;i++)b[i]=b[i+1];
                k--;
                if(k+n>0)
               {
                for(int i=0;i<=k+n-1;i++)cout<<b[i];
                cout<<".";
                for(int i=k+n;i<=k+n+7;i++)cout<<b[i];
               } 
               else{
                int p2=0;
                cout<<"0.";
                for(int i=0;i<-k-n;i++)cout<<"0",p2++;
                for(int i=p2;i<8;i++)cout<<b[i-p2];
               }
            }
        }
    }
  cout<<endl;  
}
