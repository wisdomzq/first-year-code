#include <iostream>  
using namespace std;  
  
int maxLength(int* arr, int arrLen );  
int main(int argc, char *argv[])  
{  
    int i, n, a[100];  
  
    cin >> n;  
    for ( i=0; i<n; i++ )  
        cin >> a[i];  
    maxLength(a, n);  
    return 0;  
}  
int maxLength(int arr[],int n)
{
    int max=0,maxnum;
    if(n==1)
    {
        cout<<arr[0]<<","<<endl;
        return 0;
    }
    for(int i=0;i<n-1;i++)
    {
        int tmp[1000],p=1,k=i,num;
        tmp[0]=arr[i];
        bool ju=true;
        while(ju==true)
        {
             num=i;
             for(int j=0;j<p;j++)
             {
                if(arr[k+1]==tmp[j])
                ju=false;
             }
             if(ju==true)
             {
                k++;
                if(k>=n)break;
                tmp[p]=arr[k];
                p++;
             }
        }
       if(p>max) max=p,maxnum=i;
       p=1;
    }
    for(int j=maxnum;j<maxnum+max;j++)cout<<arr[j]<<",";
    cout<<endl;
    return 0;
}