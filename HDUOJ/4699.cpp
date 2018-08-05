#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int Q,x,topA,topB,a[N],b[N],f[N],sum[N];
char s[2];
int main(){
	f[0]=-10000;
	while (~scanf("%d",&Q)){
		topA=topB=0;
		for (;Q--;){
			scanf("%s",s);
			if (s[0]=='I'){
				scanf("%d",&x);
				a[++topA]=x;
				sum[topA]=sum[topA-1]+a[topA];
				f[topA]=max(f[topA-1],sum[topA]);
			}
			else if (s[0]=='D'){
				topA--;
			}
			else if (s[0]=='L'){
				if (topA!=0) b[++topB]=a[topA--];
			}
			else if (s[0]=='R'){
				if (topB!=0){
					a[++topA]=b[topB--];
					sum[topA]=sum[topA-1]+a[topA];
					f[topA]=max(f[topA-1],sum[topA]);
				}
			}
			else{
				scanf("%d",&x);
				printf("%d\n",f[x]);
			}
		}
	}
	return 0;
}