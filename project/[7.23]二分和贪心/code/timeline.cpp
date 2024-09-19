#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct event
{
    int t;
    string s;

    friend bool operator < (event a,event b)
    {
        return a.t>b.t;
    }

    event(int _t=0,string _s="qwq")
    {
        t=_t;
        s=_s;
    }
};

priority_queue <event> q;

int main(void)
{
    q.push(event(100,"  da lai lai"));
    q.push(event(50,"  akioi"));
    q.push(event(120,"  coding"));
    
    cout<< q.top().t << q.top().s << endl;
    q.pop();
    cout<< q.top().t << q.top().s << endl;
    q.pop();
    cout<< q.top().t << q.top().s << endl;
    q.pop();
    

}

