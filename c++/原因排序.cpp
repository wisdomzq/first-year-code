#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char a[2000],b[2000],c[2000];
    int len,lenb=0,lenc=0;
    gets(a);
    len=strlen(a);
    for(int i=0;i<len;i++)
    {
    if((a[i]=='a')||(a[i]=='e')||(a[i]=='i')||(a[i]=='o')||(a[i]=='u'))
    b[lenb]=a[i],lenb++;
    if((a[i]=='A')||(a[i]=='E')||(a[i]=='I')||(a[i]=='O')||(a[i]=='U'))
    c[lenc]=a[i],lenc++;
    }
    for(int i=0;i<lenb;i++)
    {
        for(int j=i+1;j<lenb;j++)
        {
            if(b[i]>b[j])
            {
                char op;
                op=b[i];
                b[i]=b[j];
                b[j]=op;
            }
        }
    }
    for(int i=0;i<lenc;i++)
    {
        for(int j=i+1;j<lenc;j++)
        {
            if(c[i]>c[j])
            {
                char op;
                op=c[i];
                c[i]=c[j];
                c[j]=op;
            }
        }
    }
    cout<<"result=";
    for(int i=0;i<lenb;i++)
    cout<<b[i];
    for(int i=0;i<lenc;i++)
    cout<<c[i];
    cout<<endl;
}