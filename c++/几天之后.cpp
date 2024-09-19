#include<iostream>
using  namespace std;
int p[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int q[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int y,m,d,a;
int cal(int);
int main()
{
	
	cin>>y>>m>>d>>a;
	if(((y%4==0)&&((y%100)!=0))||(y%400==0))
	{
		if(a<(q[m-1]-d))
		{
			cout<<y<<"."<<m<<"."<<d+a<<endl;
			return 0;
		}
	a-=(q[m-1]-d);
	}
	else
	{
		if(a<(p[m-1]-d))
		{
			cout<<y<<"."<<m<<"."<<d+a<<endl;
			return 0;
		}	
	a-=(p[m-1]-d);
	}	
	if(((y%4==0)&&((y%100)!=0))||(y%400==0)) cal(1); 
    else cal(0);
	m++;
	if(a==0)
	{m--;
	if(((y%4==0)&&((y%100)!=0))||(y%400==0))a=q[m-1];
	else a=p[m-1];
	}

	if(m==13)
	{
	m=1,y++;
	 } 
cout<<y<<"."<<m<<"."<<a;
cout<<endl;
 } 
 int cal(int j)
 {
 	if(j==0)
 	{
 	while(a>28)
	{   
	   if(m==12)
	   {m=0;y++; 
	   	if(((y%4==0)&&((y%100)!=0))||(y%400==0))
	   		{cal(1);return 0;
			   }
		else {cal(0); return 0;
		}
	   }
	     a-=p[m];
		m++;	
	}	
	 }
	 if(j==1)
 	{
 	while(a>29)
	{   
	   if(m==12)
	   {m=0;y++; 
	   	if(((y%4==0)&&((y%100)!=0))||(y%400==0))
	   		{cal(1);return 0;
			   }
		else {cal(0); return 0;
		}
	   }
	    a-=q[m];
		m++;	
	}	
	 }
	 return a;
 }
