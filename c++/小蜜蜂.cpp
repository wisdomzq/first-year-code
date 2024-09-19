#include<iostream>
using namespace std;
void _print(__int128 x)
{
    if(x > 9) _print(x/10);
    putchar(x%10 + '0');
}
__int128 cal(unsigned long long);
int main()
{
	unsigned long long x,y;
	cin>>x>>y;
	_print(cal(y-x+1));
	cout<<endl;
}

__int128 cal(unsigned long long n)
{	
    __int128 a1=1;
    __int128 a2=1;
    if (n==1||n==2) return 1;
    for (int i=3;i<=n;i++)
    {
        a2=a2+a1;
        a1=a2-a1;
    }
    return a2;
}
