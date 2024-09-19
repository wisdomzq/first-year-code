#include<iostream>
using namespace std;
void sort(int p[],int q)  
{  
        for(int i=1;i<=q;i++)  
        for(int j=i+1;j<=q;j++)  
        if(p[i]>p[j])  
        {  
            int temp;  
            temp=p[j];  
            p[j]=p[i];  
            p[i]=temp;  
        }  
}  
int main()
{
     int m,n,a[105],b[105],ans=0;
     cin>>m>>n;
     for(int i=1;i<=m;i++)cin>>a[i];
     for(int i=1;i<=n;i++)cin>>b[i];
     if(m>n)cout<<"bit is doomed!"<<endl;
     else{
        sort(a,m);
        sort(b,n);
        int k=0,p=1,k1=0;
        while(k<m)
        {
            k++;
            while(a[k]>b[p]&&p<=n)
                 p++;
            if(p<=n)
            ans+=b[p],k1++;
            p++;
        }
        if(k1==m)cout<<ans<<endl;
        else
        cout<<"bit is doomed!"<<endl;
     }
}