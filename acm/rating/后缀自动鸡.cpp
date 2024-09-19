#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char a[1000005],b[1000005];
bool cmp(char a,char b)
{
    return a>b;
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    cin>>a;
    strcpy(b,a);
    sort(b,b+n,cmp);
    while(k--&&strcmp(b,a)!=0)
    {
       int p=0,mark;
       while(b[p]==a[p])p++;
       for(int i=0;i<n;i++)
       if(a[i]==b[p])
       {
        mark=i;break;
       }
       if(mark-p+1<=m)
       sort(a+p,a+p+m,cmp);
       else sort(a+mark-m+1,a+mark+1,cmp);
    }
    cout<<a;

}