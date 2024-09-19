#include<iostream>
#include<cstring>
char b[10][3]={"7D","50","37","57","5A","4F","6F","54","7F","5F"};
using namespace std;
int main()
{
    char a[6];
    cin>>a;
    while(strcmp(a,"0")!=0)
    {
          if(strlen(a)<5)
          {
             for(int i=1;i<=5-strlen(a);i++)cout<<"7D ";
             for(int i=0;i<strlen(a)-1;i++)cout<<b[a[i]-'0']<<" ";
             cout<<b[a[strlen(a)-1]-'0']<<endl;
          }
          else
         {
            for(int i=0;i<strlen(a)-1;i++)cout<<b[a[i]-'0']<<" ";
             cout<<b[a[strlen(a)-1]-'0']<<endl;
         }
         cin>>a;
    }
}