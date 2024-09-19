#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double dist(int x1,int y1,int x2,int y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int px,py;cin>>px>>py;
        int ax,ay;cin>>ax>>ay;
		int bx,by;cin>>bx>>by;
        double ans=0;
        double ap=dist(ax,ay,px,py),ao=dist(ax,ay,0,0);
		double bp=dist(bx,by,px,py),bo=dist(bx,by,0,0);
		double ab=dist(ax,ay,bx,by);
        ans=min(max(ap,ao),max(bp,bo));
        ans=min(ans,max(ab/2,max(ao,bp)));
		ans=min(ans,max(ab/2,max(ap,bo)));
        cout<<fixed<<setprecision(10)<<ans<<endl;

    }
}