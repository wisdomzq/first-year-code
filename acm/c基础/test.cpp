#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	int T;
	scanf("%lld",&T);
	while(T--) {
		long long k,x;
		scanf("%lld%lld",&k,&x);
		if(x>=(k+1)*k/2+k*(k-1)/2) cout<<k*2-1<<'\n';
		else {
			if(x==k*(k+1)/2) cout<<k<<'\n';
			else if(x<k*(k+1)/2) {
				//正常的二分
				int l=1,r=k,ans=1;
				while(l<=r) {
					int mid=(l+r)>>1;
					if((1+mid)*mid/2==x) {
						ans=mid;
						break;
					} else if((1+mid)*mid/2>x) {
						ans=mid;
						r=mid-1;
					} else l=mid+1;
				}
				cout<<ans<<'\n';
			} else {
				//答案在后半段的二分可能有些奇怪，因为l指向反而是消息中靠下的一个
				int l=1,r=k-1,ans=1;
				x-=k*(k+1)/2;
				while(l<=r) {
					int mid=(l+r)>>1;
					if((k-1+mid)*(k-mid)/2==x) {
						ans=mid;
						break;
					} else if((k-1+mid)*(k-mid)/2>x) {
						ans=mid;
						l=mid+1;
					} else r=mid-1;
				}
				cout<<k+k-ans<<'\n';
			}
		}
	}
	return 0;
}