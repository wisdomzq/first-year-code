#include<iostream>
using namespace std;
int main()
{
	int y,m,d,y2,y3,ans;
	bool m1,d1;
	m1=true,d1=true;
	cin>>y>>m>>d;
	if((m>12)||(m<1))m1=false;
	if(d<1)d1=false;
	if(m==2)
	{
			if((((y%4==0)&&((y%100)!=0))||(y%400==0)))
			{
				if(d>29) d1=false;
			}
			else if(d>28) d1=false;
	}
	else
	{
		if((m==1)&&(m==3)&&(m==5)&&(m==7)&&(m==8)&&(m==10)&&(m==12))
		{
			if(d>31)d1=false;
		}
		else if(d>30)d1=false;
	}
	if(m1==false)
	{
		if(d1==false)cout<<"month and day are wrong."<<endl;
		else cout<<"month is wrong."<<endl;
	}
	else
	{
		if(d1==false)cout<<"day is wrong."<<endl;
		else
		{   
			if((m==1)||(m==2))
			{
			m+=12;
			y--;
			}
			y2=y/100;
			y3=y%100;
			ans=y2/4-2*y2+y3+y3/4+13*(m+1)/5+d-1;
			ans%=7;
			while(ans<0)ans+=7;
			cout<<ans<<endl;
		}
	}
 } 
