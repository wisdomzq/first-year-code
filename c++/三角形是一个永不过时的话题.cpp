#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double length(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double area(double ax,double ay,double bx,double by,double cx,double cy)
{
    double a,b,c,p;
    a=length(ax,ay,bx,by);
    b=length(bx,by,cx,cy);
    c=length(cx,cy,ax,ay);
    p=(a+b+c)/2.0;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        double m,max=0;
        cin>>m;
        double x[102],y[102];
        for(int j=1;j<=m;j++)
        cin>>x[j]>>y[j];
        for(int j=1;j<=m-2;j++)
        {
            for(int k=j+1;k<=m-1;k++)
            {
                for(int q=k+1;q<=m;q++)
                {
                    double ans;
                    ans=area(x[j],y[j],x[k],y[k],x[q],y[q]);
                    if(ans>max)max=ans;
                }
            }
        }
         cout<<fixed<<setprecision(1)<<max<<endl;
    }
   
}