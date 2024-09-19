#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    queue<int> q;
    priority_queue <int,vector<int>,greater<int> > q1;
    int n,op,num;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>op;
        if(op==1)
        {
            cin>>num;
            q.push(num);
        }
        if(op==2)
        {
            if(!q1.empty())
            {
                cout<<q1.top()<<endl;
                q1.pop();
            }
            else{
                cout<<q.front()<<endl;
                q.pop();
            }
            
        }
        if(op==3)
        {
            while(!q.empty())
            {
                q1.push(q.front());
                q.pop();
            }
        }
            
    }
}


// #include<iostream>
// #include<algorithm>
// using namespace std;
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int n;
//     cin>>n;
//     int *p,op,num,rear=1,begin=1;
//     p=new int [n+1];
//     for(int i=1;i<=n;i++)
//     {
//         cin>>op;
//         if(op==1)
//         {
//             cin>>num;
//             p[rear]=num;
//             rear++;
//         }
//         if(op==2)
//         {
//             cout<<p[begin];
//             cout<<'\n';
//             begin++;
//         }
//         if(op==3)
//          sort(p+begin,p+rear);
//     }
// }