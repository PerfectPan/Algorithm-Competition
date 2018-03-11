#pragma comment(linker, "/STACK:102400000,102400000")
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define lson root<<1,l,mid
#define rson root<<1|1,mid+1,r
#define Key_Value ch[ch[root][1]][0]
#define DBN1(a)           cerr<<#a<<"="<<(a)<<"\n"
#define DBN2(a,b)         cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"
#define DBN3(a,b,c)       cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define DBN4(a,b,c,d)     cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
#define DBN5(a,b,c,d,e)   cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<"\n"
#define DBN6(a,b,c,d,e,f) cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<", "<<#f<<"="<<(f)<<"\n"
#define clr(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define mp make_pair
#define ALL(x) x.begin(),x.end()
#define F first
#define S second
using namespace std;
typedef long long ll;
const int maxn=500000+5;
const ll INF=1LL*1e18;
const int P=1000000007;
const double PI=acos(-1.0);
template<typename T>
inline T read(T&x){
    x=0;int _f=0;char ch=getchar();
    while(ch<'0'||ch>'9')_f|=(ch=='-'),ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x=_f?-x:x;
}
const int N=1e5+10;
int n,i,cnt[N<<2];
ll mn[N<<2],flag[N<<2],res=0;
void pushup(int root){
	mn[root]=min(mn[root<<1],mn[root<<1|1]);
	cnt[root]=cnt[root<<1]+cnt[root<<1|1];
}
void pushdown(int root){
	if (flag[root]){
		mn[root<<1]-=flag[root];
		mn[root<<1|1]-=flag[root];
		flag[root<<1]+=flag[root];
		flag[root<<1|1]+=flag[root];
		flag[root]=0;
	}
}
void build(int root,int l,int r){
	if (l==r){
		read(mn[root]);
		if (mn[root]==0) mn[root]=INF,cnt[root]=0;
		else cnt[root]=1;
		return;
	}
	int mid=l+((r-l)>>1);
	build(lson);
	build(rson);
	pushup(root);
}
void update(int root,int l,int r,int L,int R,int val){
	if (mn[root]>1LL*1e9) return;
	if (l==r){
		if (mn[root]<=val){
			res+=mn[root];
			cnt[root]=0;
			mn[root]=INF;
		}
		else{
			res+=1LL*val;
			mn[root]-=val;
		}
		return;
	}
	if (L<=l&&r<=R&&mn[root]>val){
		res+=1LL*cnt[root]*val;
		flag[root]+=val;
		mn[root]-=val;
		return;
	}
	pushdown(root);
	int mid=l+((r-l)>>1);
	if (L<=mid) update(lson,L,R,val);
	if (mid<R) update(rson,L,R,val);
	pushup(root);
}
int main(){
	read(n);
	build(1,1,n);
	for (i=1;i<=n;i++){
		int x;read(x);
		res=0;
		if (x) update(1,1,n,1,i,x);
		printf("%lld ",res);
	}
	return 0;
}
