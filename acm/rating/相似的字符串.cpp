#include<iostream>
using namespace std;
char a[10][10];
int n,m;
bool tot=false;
void func(int arr[],int total,int k=0)    //轮流更换第n位和n到total-1位
{
    for(int i=k;i<total;i++)
    {
        if(k==total-1)    //在此对排列好的数组进行下一步操作
        {
            bool judge=true;
            for(int p=0;p<total-1;p++)
            {
               int error=0;
               if(judge==true)
               for(int j=0;j<m;j++)
               {
                 if(a[arr[p]][j]!=a[arr[p+1]][j])error++;
                 if(error>1)
                 {
                    judge=false;
                    break;
                 }
               } 
            }
            if(judge==true)
               {
                tot=true;
                cout<<"Yes";
                return;
               }
            return;
        }
        int t=arr[i]; arr[i]=arr[k]; arr[k]=t; //swap(a[k],a[i]);
        if(tot!=true) func(arr,total,k+1);
        t=arr[i]; arr[i]=arr[k]; arr[k]=t;
    }
}
int main()
{
    cin>>n>>m;
    int b[10];
    for(int i=1;i<=n;i++)
    cin>>a[i];
    for(int i=0;i<n;i++)b[i]=i+1;
    func(b,n);
    if(tot==false)cout<<"No";
}