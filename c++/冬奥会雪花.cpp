#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
char a[2200][2200];
int b[2200][2200];
void search(int,int,int);
int main()
{
    int n;
    cin>>n;
    memset(b,0,sizeof(b));
    if(n==1)cout<<"*"<<endl;
    if(n==2){
        cout<<"  *  "<<endl;cout<<"* * *"<<endl;cout<<"  *  "<<endl;
    }
    if(n>2)
    {
        int k=pow(3,n-1),mid,m=n-2;
        mid=(k+1)/2;
        for(int i=1;i<=k;i++)
          for(int j=1;j<=k;j++) a[i][j]=' ';
         a[mid][mid]='*';
         for(int i=1;i<=k;i++)a[i][mid]='*',a[mid][i]='*';
         while(m>0)
         {
             int k1=pow(3,m),cal;
             cal=k1;
             m--;
             while(mid-cal>0)
             {
                b[mid][mid+cal]++,b[mid][mid-cal]++,b[mid+cal][mid]++,b[mid-cal][mid]++;
                cal+=k1; 
             }      
         }//标记迭代数
       for(int i=1;i<=k;i++)
       {
        if(b[i][mid]>0)search(b[i][mid],i,mid);
        if(b[mid][i]>0)search(b[mid][i],mid,i);
       }
       for(int i=1;i<=k;i++)
       {
        for(int j=1;j<=k;j++) 
        {
            if(j==k)cout<<a[i][j];
            else cout<<a[i][j]<<" ";
        }
        cout<<endl;
       }
    }  
}
void search(int n,int i,int j)//n为b[i][j]对应的值
{
     int num=pow(3,n);
     num=(num-1)/2;
     for(int k=1;k<=num;k++)a[i+k][j]='*',a[i-k][j]='*',a[i][j+k]='*',a[i][j-k]='*';
     while(n>1)//中间轴以外的进行标记
     {
        int num1=pow(3,n-1),k1;
        k1=num1;
        while(num-k1>0)
        {
            search(n-1,i-k1,j),search(n-1,i+k1,j),search(n-1,i,j-k1),search(n-1,i,j+k1);
            k1+=num1;
        }
        n--;
     }
}