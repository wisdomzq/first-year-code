#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int a[2010][2010];
struct mp{
    int num,ci=0;
}hen[2010],shu[2010];
priority_queue<int, vector<int>, greater<int> > p,q;
bool cmp(mp a,mp b)
{
    return a.ci>b.ci;
}
int main()
{
    int n,m,k,l,d,x1,y1,x2,y2,pc,qc;
    cin>>n>>m>>k>>l>>d;
    for(int i=1;i<=n;i++)
    hen[i].num=i;
    for(int i=1;i<=m;i++)
    shu[i].num=i;
    for(int i=1;i<=d;i++)
    {
           cin>>x1>>y1>>x2>>y2;
           if(x1==x2)
           shu[y1>y2?y2:y1].ci++;
           else
           hen[x1>x2?x2:x1].ci++;
    }
   sort(hen+1,hen+1+n,cmp);
   sort(shu+1,shu+1+m,cmp);
   for(int i=1;i<=k;i++)
   p.push(hen[i].num);
   while(!p.empty())
   {
    cout<<p.top()<<" ";
    p.pop();
   }
   cout<<endl;
    for(int i=1;i<=l;i++)
   q.push(shu[i].num);
   while(!q.empty())
   {
    cout<<q.top()<<" ";
    q.pop();
   }

}