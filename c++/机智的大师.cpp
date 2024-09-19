#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
    int tmp;
    tmp=a,a=b,b=tmp;
}
void quicksort(int p[],int low,int high)
{
     int i=low,j=high;
     if(i>=j) return;
     int temp=p[low];
     while(i!=j)
     {
        while(p[j]>=temp&&i<j)j--;
        while(p[i]<=temp&&i<j)i++;
        if(i<j)swap(p[i],p[j]);
     }
     swap(p[low],p[i]);
     quicksort(p,low,i-1);
     quicksort(p,i+1,high);
}
int main()
{
    int n,king,*rp,mark;
    cin>>n>>king;
    rp=new int [n+5];
    for(int i=1;i<=n;i++)cin>>rp[i];
    quicksort(rp,1,n);
    for(int i=1;i<=n;i++)
        if((rp[i]==king)||((rp[i-1]<king&&rp[i]>king)))
        {
            mark=i;break;}
    for(int i=mark;i<=n;i++)
    {
        if(rp[i]>=king)king+=2;
        else king++;
    }
    king+=mark-1;
    cout<<king<<endl;
}