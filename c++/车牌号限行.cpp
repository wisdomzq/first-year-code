#include<iostream>  
using  namespace std;
char limit[5][3]={"38","49","50","16","27"};  
int p[12]={31,28,31,30,31,30,31,31,30,31,30,31};  
int q[12]={31,29,31,30,31,30,31,31,30,31,30,31};  
int week(int y,int m,int d)
{
    int y2,y3,ans;
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
            return ans;  
} 
int daysafter(int ey,int em,int ed) 
{  
    int y,m,d,ans=0,pans=0,l;  
    y=2012,m=4,d=9;
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
    return ans;  
}  
int main()
{
    int y,m,d,day,week1;
    cin>>y>>m>>d;
    week1=week(y,m,d);
    day=daysafter(y,m,d)%455;
    if(week1==0||week1==6)cout<<"Free."<<endl;
    else{
        if(day<=89)
        {
          week1=(week1+4)%5;
          cout<<limit[week1][0]<<" and "<<limit[week1][1]<<"."<<endl;
        }
        if(day>89&&day<=180)
        {
            week1=(week1+3)%5;
            cout<<limit[week1][0]<<" and "<<limit[week1][1]<<"."<<endl;
        }
        if(day>180&&day<=271)
        {
            week1=(week1+2)%5;
            cout<<limit[week1][0]<<" and "<<limit[week1][1]<<"."<<endl;
        }
        if(day>271&&day<=366)
        {
            week1=(week1+1)%5;
            cout<<limit[week1][0]<<" and "<<limit[week1][1]<<"."<<endl;
        }
        if(day>366&&day<=455)
            cout<<limit[week1][0]<<" and "<<limit[week1][1]<<"."<<endl;
    }
}