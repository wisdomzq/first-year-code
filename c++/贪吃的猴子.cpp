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
	cout<<"���������������ҵ� 1 ����������"<<endl;
	ju=false;
	}
	while(ans<x)
	 {
	 	if(n<=0)
		 {
		 	cout<<"���ܲ�����������"<<endl;
		 	ju=false;
		 	return 0;
		 }
		 n--;
	 	total++;
	 	ans-=m;
	 	ans+=n;
	 }
	 if(ju==true)cout<<"���������������ҵ�"<<total<<"����������"<<endl;
}
