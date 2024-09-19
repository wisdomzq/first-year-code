#include<iostream>
#include<cstring>
using namespace std;
struct student{
    int num,ord;
    char name[21];
};
void swap(int &x,int &y)
{
    int temp;
    temp=y;
    y=x;
    x=temp;
}
char a[201][201];
int main()
{
    int n,k;
    cin>>n;
    struct student stu[200];
    for(int i=1;i<=n;i++)
    cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        int m;
        k=strlen(a[i]);
        for(int j=0;j<k;j++)
        if(a[i][j]==',')
        {
           m=j;
           break;
        }
        for(int j=0;j<m;j++)
             stu[i].name[j]=a[i][j];
       stu[i].num=a[i][m+1]-'0';
       for(int j=m+2;j<k;j++)
       {
             stu[i].num*=10;
             stu[i].num+=a[i][j]-'0';
       }
        stu[i].ord=i;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        if(stu[i].num<stu[j].num)
        swap(stu[i],stu[j]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        if(stu[i].num==stu[j].num)
            if(stu[i].ord>stu[j].ord)swap(stu[i],stu[j]);
    }
      for(int i=1;i<=n;i++)
      cout<<stu[i].name<<","<<stu[i].num<<endl;
}