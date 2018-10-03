#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,cas=1;
ll A,B;
int main(){
	for (scanf("%d",&T);T--;){
		scanf("%lld%lld",&A,&B);
		printf("Case #%d:\n",cas++);
		if (A==B){
			puts("1");
			printf("%lld %lld\n",A,A);
		}
		else{
			puts("2");
			printf("%lld %lld\n",A,B);
			printf("%lld %lld\n",B,A);
		}
	}
	return 0;
}