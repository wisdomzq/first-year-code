#include<iostream>
using  namespace std;
int p[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int q[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int main()
{
	int y,m,d,ey,em,ed,ans=0,pans=0,l;
	cin>>y>>m>>d>>ey>>em>>ed;
		while(ey>y)
		{
			l=y+1;
			if(((((y%4==0)&&((y%100)!=0))||(y%400==0))&&(m<=2))||((((l%4==0)&&((l%100)!=0))||(l%400==0))&&(m>2))) ans+=366;
			else ans+=365;
			y++;
		}
			if(em>=m)
 	 {
		if(((y%4==0)&&((y%100)!=0))||(y%400==0))
		{
			while(m<em)
			{
			ans+=q[m-1];
			m++;
			}
			ans+=(ed-d);
		}
		else
		{
			while(m<em)
			{
			ans+=p[m-1];
			m++;
			}
			 ans+=(ed-d);
		}
	}
	else
	{
		if(((y%4==0)&&((y%100)!=0))||(y%400==0))
		{
			while(m>em)
			{
			pans+=q[em-1];
			em++;
			}
			pans-=(ed-d);
		}
		else
		{
			while(m>em)
			{
			pans+=p[em-1];
			em++;
			}
			pans-=(ed-d);
		}
	}
	ans-=pans;
	printf("%d %s",ans,ans==1?"day":"days");
	printf("\n"); 
}
