#include<iostream>
using namespace std;
bool judge(int n)
{
    int month,date;
   
    month=(n%10)*10+(n%100)/10;
    date=n/1000+((n/100)%10)*10;
    
    if((month>12)||(month<1)) return false;
	    if(date<1) return false;
	    if(month==2)
	      {
			if((((n%4==0)&&((n%100)!=0))||(n%400==0)))
			{
				if(date>29) return false;
			}
			else if(date>28) return false;
	      }
         else
	    {
		if((month==1)||(month==3)||(month==5)||(month==7)||(month==8)||(month==10)||(month==12))
		{
			if(date>31)return false;
		}
		else if(date>30)return false;
	     }
         return true;
}
int main()
{
    char b[10],c[10];
    int begin[10],end[10];
    int be,en,da1,da2,mon1,day1,ans=0,mon2,day2;
    bool ju=false;
    cin>>b>>c;
    for(int i=0;i<8;i++)begin[i]=b[i]-'0',end[i]=c[i]-'0';
    be=begin[0]*1000+begin[1]*100+begin[2]*10+begin[3];
    en=end[0]*1000+end[1]*100+end[2]*10+end[3];
    da1=begin[4]*1000+begin[5]*100+begin[6]*10+begin[7];
    da2=end[4]*1000+end[5]*100+end[6]*10+end[7];
    mon1=begin[3]*10+begin[2],day1=begin[0]+begin[1]*10;
    mon2=end[3]*10+end[2],day2=end[0]+end[1]*10;
    if(be==en)
    {
        if(((mon2*100+day2)>da2)&&((mon2*100+day2)>da1))
        {
            cout<<0;
            return 0;
        } 
    }
    if(be<en)
    {
         if((mon2*100+day2)<=da2)
    {   ju=true;
        if((mon2>12)||(mon2<1)) ju=false;
	    if(day2<1) ju=false;
	    if(mon2==2)
	      {
			if((((en%4==0)&&((en%100)!=0))||(en%400==0)))
			{
				if(day2>29) ju=false;
			}
			else if(day2>28) ju=false;
	      }
         else
	    {
		if((mon2==1)||(mon2==3)||(mon2==5)||(mon2==7)||(mon2==8)||(mon2==10)||(mon2==12))
		{
			if(day2>31)ju=false;
		}
		else if(day2>30)ju=false;
	     }
    }
    }
    if(ju==true)ans++;
    ju=false;
    if(mon1*100+day1>=da1)
    {
        ju=true;
        if((mon1>12)||(mon1<1)) ju=false;
	    if(day1<1) ju=false;
	    if(mon1==2)
	      {
			if((((be%4==0)&&((be%100)!=0))||(be%400==0)))
			{
				if(day1>29) ju=false;
			}
			else if(day1>28) ju=false;
	      }
         else
	    {
		if((mon1==1)||(mon1==3)||(mon1==5)||(mon1==7)||(mon1==8)||(mon1==10)||(mon1==12))
		{
			if(day1>31)ju=false;
		}
		else if(day1>30)ju=false;
	     }
    }
    if(ju==true)ans++;
    for(int i=be+1;i<en;i++)
    if(judge(i)==true)ans++;
    cout<<ans;
}