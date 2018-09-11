#include <bits/stdc++.h>
using namespace std;
const int N=(1<<22)+10;
const int M=1e6+10;
int n,status,i,a[M],f[N];
int main(){
	scanf("%d",&n);
	for (i=1;i<=n;++i){
		scanf("%d",&a[i]);
		f[a[i]]=a[i];
	}
	for (i=0;i<22;++i){
		for (status=0;status<(1<<22);++status){
			if (status&(1<<i)) f[status]=max(f[status],f[status^(1<<i)]);
		}
	}
	for (i=1;i<=n;i++){
		int pos=((1<<22)-1)^a[i];
		printf("%d%c",f[pos]?f[pos]:-1,i==n?'\n':' ');
	}
	return 0;
}