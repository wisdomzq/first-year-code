#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double x[2000],y[2000];
double length(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
   int n;
   long double leng=0;
   long double min=10000000000;
   cin>>n;
   for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
   for(int i=1;i<=n;i++)
   {
    for(int j=1;j<=n;j++)
    {
        if(i!=j)
        leng+=length(x[i],y[i],x[j],y[j])/(n-1);
    }
    if(leng<min)min=leng;
    leng=0;
   }
    cout<<setprecision(10)<<min<<endl;
}