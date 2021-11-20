#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int n,i,j,status,a[N],f[(1<<20)+10];
int main(){
	scanf("%d",&n);
	memset(f,0x3f,sizeof(f));
	for (i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]^=a[i-1];
		f[a[i]]=min(f[a[i]],i);
	}
	for (i=0;i<20;i++){
		for (status=0;status<(1<<20);status++){
			if (!(status&(1<<i))) f[status]=min(f[status],f[status|(1<<i)]);
		}
	}
	for (i=1;i<=n;i++){
		int res=0;
		for (j=19;j>=0;j--){
			if (!(a[i]&(1<<j)) && f[res|(1<<j)]<=i) res|=(1<<j);
		}
		printf("%d\n",res+(res^a[i]));
	}
	return 0;
}
