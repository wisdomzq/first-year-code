#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int n,m,num;
    queue<int> q;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>m;
        if(m==1)
        {
            cin>>num;
            q.push(num);
        }
        if(m==2)
        {
            if(q.empty())cout<<"ERR_CANNOT_POP"<<endl;
            else q.pop();
        }
        if(m==3)
        {
            if(q.empty())cout<<"ERR_CANNOT_QUERY"<<endl;
            else cout<<q.front()<<endl;
        }
        if(m==4)
        cout<<q.size()<<endl;
    }
}