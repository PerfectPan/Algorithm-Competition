#include<bits/stdc++.h>
#define MP make_pair
#define PB emplace_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0'&& ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int P=1e9+7;
const int N=1e5+10;
#define IT set<Node>::iterator
struct Node{
	int l,r;
	mutable ll v;
	Node(int L,int R=-1,ll V=0):l(L),r(R),v(V){}
	bool operator<(const Node&rhs)const{
		return l<rhs.l;
	}
};
set<Node>S;
ll fexp(ll a,ll n,ll mod){
	ll res=1;
	a%=mod;
	while (n){
		if (n&1) res=res*a%mod;
		a=a*a%mod;
		n>>=1LL;
	}
	return res;
}
IT split(int pos){
	IT it=S.lower_bound(Node(pos));
	if (it!=S.end() && it->l==pos) return it;
	--it;
	int l=it->l,r=it->r;
	ll v=it->v;
	S.erase(it);
	S.insert(Node(l,pos-1,v));
	return S.insert(Node(pos,r,v)).first;
}
void assign(int l,int r,ll val){
	IT itr=split(r+1),itl=split(l);
	S.erase(itl,itr);
	S.insert(Node(l,r,val));
}
void add(int l,int r,ll val){
	IT itr=split(r+1),itl=split(l);
	for (;itl!=itr;++itl) itl->v+=val;
}
ll getRank(int l,int r,int k){
	vector<pair<ll,int> >vec;
	IT itr=split(r+1),itl=split(l);
	for (;itl!=itr;++itl) vec.PB(MP(itl->v,itl->r-itl->l+1));
	sort(vec.begin(),vec.end());
	for (int i=0;i<(int)vec.size();++i){
		k-=vec[i].second;
		if (k<=0) return vec[i].first;
	}
}
ll sum(int l,int r,int x,int mod){
	IT itr=split(r+1),itl=split(l);
	ll res=0;
	for (;itl!=itr;++itl){
		(res+=(itl->r-itl->l+1)*fexp(itl->v,x,mod))%=mod;
	}
	return res;
}
int n,m,i,op,l,r,x,y;
ll seed,vmax,a[N];
ll rd(){
	ll ret=seed;
	seed=(seed*7+13)%P;
	return ret;
}
int main(){
	read(n),read(m),read(seed),read(vmax);
	for (i=1;i<=n;++i){
		a[i]=(rd()%vmax)+1;
		S.insert(Node(i,i,a[i]));
	}
	S.insert(Node(n+1,n+1,0));
	for (i=1;i<=m;++i){
		op=(int)(rd()%4)+1;
		l=(int)(rd()%n)+1;
		r=(int)(rd()%n)+1;
		if (l>r) swap(l,r);
		if (op==3) x=(int)(rd()%(r-l+1))+1;
		else x=(int)(rd()%vmax)+1;
		if (op==4) y=(int)(rd()%vmax)+1;

		if (op==1) add(l,r,x);
		else if (op==2) assign(l,r,x);
		else if (op==3) printf("%lld\n",getRank(l,r,x));
		else printf("%lld\n",sum(l,r,x,y));
	}
	return 0;
}