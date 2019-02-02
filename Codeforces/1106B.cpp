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
int n,m,i,t,d,a[N],c[N];
struct Node{
	int id,a;
	bool operator<(const Node&rhs)const{
		if (c[id]==c[rhs.id]) return id>rhs.id;
		return c[id]>c[rhs.id];
	} 
};
ll ans;
priority_queue<Node>Q;
int main(){
	read(n),read(m);
	for (i=1;i<=n;++i) read(a[i]);
	for (i=1;i<=n;++i) read(c[i]),Q.push((Node){i,a[i]});
	for (;m--;){
		read(t),read(d);ans=0;
		if (a[t]>=d){
			ans=1LL*d*c[t];
			a[t]-=d;
			if (a[t]) Q.push((Node){t,a[t]});
		}
		else{
			ll left=d-a[t];
			ans=1LL*a[t]*c[t];
			a[t]=0;
			while (!Q.empty()){
				Node cur=Q.top();Q.pop();
				if (a[cur.id]!=cur.a) continue;
				if (cur.a>=left){
					ans+=1LL*left*c[cur.id];
					cur.a-=left;
					if (cur.a) Q.push(cur);
					a[cur.id]=cur.a;
					left=0;
					break;
				}
				else{
					left-=a[cur.id];
					ans+=1LL*a[cur.id]*c[cur.id];
					a[cur.id]=0;
				}
			}
			if (left) ans=0;
		}
		printf("%lld\n",ans);
	}
	return 0;
}