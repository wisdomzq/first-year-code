#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string a[10000],b[10000];
int main()
{
    int i=0,ans=0,tim,kpm;
    getline(cin,a[i]);
    while(a[i]!="EOF")
    {
          for(int k=0;k<a[i].size();i++)
          {
            if(a[i][k]=='<')
            if(k-1>=0)
            {
                a[i].erase(k,1);
				a[i].erase(k-1,1),k-=2;
            }
            else  a[i].erase(k,1),k--;
          }
          i++;
          getline(cin,a[i]);
         
    }
    int j=0;
    getline(cin,b[j]);
    while(b[j]!="EOF")
    {
        for(int k=0;k<b[j].size();k++)
        {
            if(b[j][k]=='<')
            {
                if(k-1>=0)
                {
                 b[j].erase(k,1);
				b[j].erase(k-1,1),k-=2;
                }
                else
                b[j].erase(k,1),k--;
            }
        }
        j++;
        getline(cin,b[j]);
    }
    int min=i>j?i:j;
    for(i=0;i<min;i++)
    {
        int leng=(b[i].length()>a[i].length())?b.length():a[j].length();
        for(int k=0;k<leng;k++)
        if(b[i][k]==a[i][k]) ans++;
    } 
    }
     cin>>tim;
     kpm=ans;kpm=kpm*60/tim;ans=kpm;//注意精度.
	if(kpm-ans>=0.5)  ans++;//小数部分四舍五入.
	cout<<ans;
   
}