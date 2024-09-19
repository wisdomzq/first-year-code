#include<iostream>
using namespace std;
int main()
{
    char a[6];
    int ans=0;
    cin>>a;
    if(a[4]<'0'||a[4]>'9')cout<<"no."<<endl;
    else{
      for(int i=0;i<5;i++)
        if((a[i]>='A'&&a[i]<='Z')&&(a[i]!='I')&&(a[i]!='O'))ans++;
      if(ans>=2)cout<<"ok."<<endl;
      else cout<<"no."<<endl;
    }
}