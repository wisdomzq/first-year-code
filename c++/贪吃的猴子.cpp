#include<iostream>
using namespace std;
int main()
{
	int n,m,x,ans,total;
	bool ju;
	ans=0,total=0,ju=true;
    cin>>n>>m>>x;
	ans+=n;
	total++;
    if(ans>=x)
	{
	cout<<"青蛙能爬出井，且第 1 天爬出井。"<<endl;
	ju=false;
	}
	while(ans<x)
	 {
	 	if(n<=0)
		 {
		 	cout<<"青蛙不能爬出井。"<<endl;
		 	ju=false;
		 	return 0;
		 }
		 n--;
	 	total++;
	 	ans-=m;
	 	ans+=n;
	 }
	 if(ju==true)cout<<"青蛙能爬出井，且第"<<total<<"天爬出井。"<<endl;
}
