#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
#define ll long long
struct minister{
    int r,l;
}m[1005];
int a[20005];
bool cmp(minister a,minister b)
{
    return max(b.l,a.l*a.r)<max(a.l,b.l*b.r);
}
string multi(string p,string q)
{
    memset(a,0,sizeof(a));
    reverse(p.begin(),p.end());reverse (q.begin(),q.end());
    for(int i=0;i<p.size();i++)
    for(int j=0;j<q.size();j++)a[i+j]+=(p[i]-'0')*(q[j]-'0');
    for(int i=0;i<p.size()+q.size();i++)
    if(a[i]>=10)  a[i+1]+=a[i]/10,a[i]%=10;
    string ans="";
    bool ju=true;
    for(int i=p.size()+q.size()-1;i>=0;i--)
    {
        if(a[i]==0&&ju)continue;
        else{
            ju=false;
            ans+=a[i]+'0';
        }
    }
    return ans;
}
int dvs[20005],dvres[20005];
string div(string a,int b){
	memset(dvs,0,sizeof(dvs));
	memset(dvres,0,sizeof(dvres));
    for(int i=0;i<a.size();i++)dvs[i+1]=a[i]-'0';
    int bs=0;
    for(int i=1;i<=a.size();i++)
    {
        dvres[i]=(bs*10+dvs[i])/b;
        bs=(bs*10+dvs[i])%b;
    }
    int lc=1;
	while(dvres[lc]==0&&lc<a.size())++lc;
	string div_ans="";
	for(int i=lc;i<=a.size();i++)div_ans+=dvres[i]+'0';
	return div_ans;
}
string to_str(int n)
{
     string p="";
	while(n){
		p+=n%10+'0';
		n/=10;
	}
	reverse(p.begin(),p.end());
	return p;
}
string mx(string p,string q){
	if(p.size()!=q.size())return p.size()>q.size()?p:q;
	return p>q?p:q;
}

int main()
{
    int n,kr,kl;
    cin>>n;
    cin>>kr>>kl;
    string mul,ans="0";
    mul=to_str(kr);
    bool devide=true;
    for(int i=1;i<=n;i++)cin>>m[i].r>>m[i].l;
    sort(m+1,m+1+n,cmp);
    for(int i=1;i<=n;i++) 
    {
        ans=mx(ans,div(mul,m[i].l));
        mul=multi(mul,to_str(m[i].r));
    }
    cout<<ans<<endl;
}
