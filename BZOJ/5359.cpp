#include <bits/stdc++.h>
#define PB push_back
using namespace std;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=100000+10;
int T,n,m,i,j,a,l,r,d,primes[N],id[N];
vector<int>G[N];
void init(){
	for (i=2;i<=100000;i++){
		if (!primes[i]) primes[++primes[0]]=i;
		for (j=1;j<=primes[0]&&i*primes[j]<=100000;j++){
			primes[i*primes[j]]=1;
			if (i%primes[j]==0) break;
		}
	}
	for (i=1;i<=primes[0];i++) id[primes[i]]=i;
}
void update(int x,int pos){
	int m=(int)sqrt(x+0.5);
	for (int i=2;i<=m;i++){
		if (x%i==0){
			while (x%i==0){
				x/=i;
				G[id[i]].PB(pos);
			}
		}
	}
	if (x>1) G[id[x]].PB(pos);
}
int main(){
	init();
	for (read(T);T--;){
		read(n),read(m);
		for (i=1;i<=primes[0];i++) G[i].clear();
		for (i=1;i<=n;i++){
			read(a);
			update(a,i);
		}
		for (i=1;i<=m;i++){
			read(l),read(r),read(d);
			bool flag=1;
			int m=(int)sqrt(d+0.5);
			for (j=2;j<=m;j++){
				if (d%j==0){
					int cnt=0;
					while (d%j==0){
						d/=j;
						cnt++;
					}
					int tot=upper_bound(G[id[j]].begin(),G[id[j]].end(),r)-lower_bound(G[id[j]].begin(),G[id[j]].end(),l);
					if (tot<cnt){
						flag=0;
						break;
					}
				}
			}
			if (d>1){
				int tot=upper_bound(G[id[d]].begin(),G[id[d]].end(),r)-lower_bound(G[id[d]].begin(),G[id[d]].end(),l);
				if (tot<1) flag=0;
			}
			puts(flag?"Yes":"No");
		}
	}
	return 0;
}