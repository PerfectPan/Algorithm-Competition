#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n,cas=1;
int main(){
	for (scanf("%lld",&T);T--;){
		scanf("%lld",&n);
		printf("Case #%lld: ",cas++);
		if (n==1) puts("0");
		else{
			ll ans=n*(n+1)/2LL-1LL;
			printf("%lld\n",ans);
		}
	}
	return 0;
}