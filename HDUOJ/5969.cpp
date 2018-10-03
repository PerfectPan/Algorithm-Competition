#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
ll x,y;
int main(){
	for (scanf("%d",&T);T--;){
		scanf("%lld%lld",&x,&y);
		ll res=y;
		for (int i=62;i>=1;--i){
			if (y&(1LL<<i)){
				ll tmp=y^(1LL<<i);
				tmp|=(1LL<<i)-1;
				if (tmp>=x){
					res=y|tmp;
					break;
				}
			}
		}
		printf("%lld\n",res);
	}
	return 0;
}