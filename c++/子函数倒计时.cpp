#include <iostream>  
using namespace std;   
int leap_year( int );     
int year_days( int );     
int days(int, int, int);      
int leap_year( int year )   // 判断闰年或平年  
{   return ( (year%4==0 && year%100!=0) || year%400==0 ) ? 1 : 0;  
}   
int year_days(int year)     // 计算一整年的天数  
{   return leap_year( year ) ? 366 : 365;  
}  
int days( int year, int month, int day ) // 计算该天month,day 是本年year的第几天  
{   int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31}, i;  
      
    if  ( leap_year( year ) && month >2 )  
        day++;  
      
    for ( i=1; i<month; i++ )  
        day += months[i];  
  
    return day;  
}  
//子函数开始 
int main() 
{ 
 int y1,m1,d1,y2,m2,d2,ans;
 ans=0;
 cin>>y1>>m1>>d1>>y2>>m2>>d2;
 if(y2==y1)
 ans+=days(y2,m2,d2)-days(y1,m1,d1);
 else
 {
 	ans=year_days(y1)-days(y1,m1,d1);
 	while(y2>(y1+1))
 	{
 		y1++;
 		ans+=year_days(y1);
	 }
	 ans+=days(y2,m2,d2);
	
 }
  cout<<ans<<" "<<(ans==1?"day":"days")<<endl;
  return 0; 
}
