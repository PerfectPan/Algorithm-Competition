#include <bits/stdc++.h>
#define MP make_pair
#define PB emplace_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N=1e5+10;
const int M=200+10;
const ll INF=2000000000000000000LL;
struct Node{
	int d,w,flag;
	bool operator<(const Node&rhs)const{
		if (w==rhs.w) return d>rhs.d;
		return w>rhs.w;
	}
};
int n,m,k,s,t,d,w,i,j;
Node a[N];
ll ans=INF,f[M][N];
multiset<Node>S;
vector<Node>vec[N];
void ins(Node p){S.insert(p);}
void del(Node p){
	p.flag=1;
	auto it=S.find(p);
	S.erase(it);
}
int main(){
	read(n),read(m),read(k);
	for (i=1;i<=k;++i){
		read(s),read(t),read(d),read(w);
		vec[s].PB((Node){d,w,1});
		vec[t+1].PB((Node){d,w,-1});
	}
	for (i=1;i<=n;++i){
		for (auto p:vec[i]){
			if (p.flag==1) ins(p);
			else del(p);
		}
		if (S.size()) a[i]=*S.begin();
		else a[i]=(Node){i,0,0};
	}
	for(j=0;j<=m+5;++j)for(i=1;i<=n+5;++i)f[j][i]=INF;
	for (f[0][1]=0,j=0;j<=m;++j){
		for (i=1;i<=n;++i){
			f[j+1][i+1]=min(f[j+1][i+1],f[j][i]);
			f[j][a[i].d+1]=min(f[j][a[i].d+1],f[j][i]+a[i].w);
		}
		ans=min(ans,f[j][n+1]);
	}
	printf("%lld\n",ans);
	return 0;
}