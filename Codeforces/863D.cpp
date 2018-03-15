#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
template <typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
typedef pair<int,int> dual_rt;
const int N=200000+10;
int rt,i,n,m,q,op,l,r,x,a[N];
vector<int>vec;
struct FHQTreap{
	int l,r,val,key,rev,sz;
}d[N];
void pushdown(int u){
	if (d[u].rev){
		swap(d[u].l,d[u].r);
		d[d[u].l].rev^=1;
		d[d[u].r].rev^=1;
		d[u].rev=0;
	}
}
void update(int u){
	d[u].sz=d[d[u].l].sz+d[d[u].r].sz+1;
}
int NewNode(int val){
	static int cnt=0;
	d[++cnt].val=val;
	d[cnt].key=rand();
	d[cnt].sz=1;
	return cnt;
}
dual_rt split(int u,int val){
	dual_rt ret(0,0);
	if (!u) return ret;
	pushdown(u);
	if (val<=d[d[u].l].sz){
		ret=split(d[u].l,val);
		d[u].l=ret.second;
		ret.second=u;
	}
	else{
		ret=split(d[u].r,val-d[d[u].l].sz-1);
		d[u].r=ret.first;
		ret.first=u;
	}
	update(u);
	return ret;
}
int merge(int u,int v){
	if (!u) return v;
	pushdown(u);
	if (!v) return u;
	pushdown(v);
	if (d[u].key<d[v].key){
		d[u].r=merge(d[u].r,v);
		update(u);
		return u;
	}
	else{
		d[v].l=merge(u,d[v].l);
		update(v);
		return v;
	}
}
void build(){
	static stack<int> stk;
	stk.push(0);
	for (int i=1,fa;i<=n;i++){
		d[i].val=a[i],d[i].key=rand(),d[i].sz=1;
		while (fa=stk.top(),d[fa].key>d[i].key){
			update(fa);
			stk.pop();
		}
		d[i].l=d[fa].r;
		d[fa].r=i;
		stk.push(i);
	}
	while (stk.size()>1){
		update(stk.top());
		stk.pop();
	}
	stk.pop();
	rt=d[0].r;
}
void rvs(int L,int R){
	dual_rt x=split(rt,L-1);
	dual_rt y=split(x.second,R-L+1);
	d[y.first].rev^=1;
	rt=merge(merge(x.first,y.first),y.second);
}
void shift(int L,int R){
	dual_rt x=split(rt,L-1);
	dual_rt y=split(x.second,R-L);
	dual_rt z=split(y.second,1);
	rt=merge(merge(x.first,z.first),merge(y.first,z.second));
}
void dfs(int u){
	pushdown(u);
	if (d[u].l) dfs(d[u].l);
	vec.push_back(d[u].val);
	if (d[u].r) dfs(d[u].r);
}
int main(){
	read(n),read(q),read(m);
	for (i=1;i<=n;i++) read(a[i]);
	build();
	for (i=1;i<=q;i++){
		read(op),read(l),read(r);
		if (op==1) shift(l,r);
		else rvs(l,r);
	}
	dfs(rt);
	for (i=1;i<=m;i++){
		read(x);
		printf("%d%c",vec[x-1],i==m?'\n':' ');
	}
	return 0;
}

