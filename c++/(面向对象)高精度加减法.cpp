#include<iostream>
#include<cstring>
using namespace std;
class Rational{     
    public:
    int num[501],len; 
    Rational()
		{
			memset(num,0,sizeof(num));
		}
    bool judge=true;
    void output();
    Rational operator+(Rational &r1);
    Rational operator-(Rational &r1);
};
void Rational::output()
{
    if(judge==false)cout<<"-";
    bool ju=false;
    for(int i=len-1;i>=0;i--)cout<<num[i],ju=true;
    if(ju==false)cout<<0;
    cout<<endl;
}
Rational Rational::operator + ( Rational &r1) 
{
      Rational tmp;
      if(len>r1.len)tmp.len=len;
		else tmp.len=r1.len;
		for(int i=0;i<tmp.len;i++)
	 {
	 	tmp.num[i]+=num[i]+r1.num[i];
	 	tmp.num[i+1]=tmp.num[i]/10;
	 	tmp.num[i]%=10;
	 }
		if(tmp.num[tmp.len])tmp.len++;
	    return tmp;
}
Rational Rational::operator-(Rational &r1) 
{
    Rational tmp;
    bool ju=true;
    if(len==r1.len)
    {
        int k=len-1;
        while(num[k]==r1.num[k]&&k>-1)
            k--;
        if(num[k]<r1.num[k])ju=false;
    }
    if ((len<r1.len) || (len==r1.len && ju==false))
	  {
        tmp.judge=false;
        tmp.len=r1.len;
         for (int i=0;i<tmp.len;i++)
	 {
        if (r1.num[i]<num[i]) 
		{
            r1.num[i+1]-=1;
            r1.num[i]+= 10;
        }
        tmp.num[i]=r1.num[i]-num[i];
    }
   while(tmp.len>0&&tmp.num[tmp.len-1]==0) --tmp.len;  
   }
   else{
    tmp.len=len;
     for (int i=0;i<tmp.len;i++)
	 {
        if (num[i]<r1.num[i]) 
		{
            num[i+1]--;
            num[i]+= 10;
        }
        tmp.num[i]=num[i]-r1.num[i];
    }
     while(tmp.len>0&&tmp.num[tmp.len-1]==0) --tmp.len;  
    }return tmp;
}
char a[10003];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int p;
        Rational r1,r2,r3;
        cin>>a;
        for(int i=0;i<strlen(a);i++)
        if((a[i]=='+')||(a[i]=='-'))p=i;
        r1.len=p,r2.len=strlen(a)-p-1;
        for(int i=0;i<r1.len;i++)
        r1.num[p-1-i]=a[i]-'0';
        for(int i=strlen(a)-1;i>=p+1;i--)
        r2.num[strlen(a)-1-i]=a[i]-'0';
        if(a[p]=='+')
            r3=r1+r2;
        if(a[p]=='-')
            r3=r1-r2;
        r3.output();
    }
    
}