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
#define IT set<Node>::iterator
struct Node{
	int l,r;
	mutable int v;
	Node(int L,int R=-1,int V=0):l(L),r(R),v(V){}
	bool operator<(const Node&rhs)const{
		return l<rhs.l;
	}
};
int n,m,i,op,a,b,x;
set<Node>S;
IT split(int pos){
	IT it=S.lower_bound(Node(pos));
	if (it!=S.end() && it->l==pos) return it;
	--it;
	int l=it->l,r=it->r,v=it->v;
	S.erase(it);
	S.insert(Node(l,pos-1,v));
	return S.insert(Node(pos,r,v)).first;
}
void assign(int l,int r,int v){
	IT itr=split(r+1),itl=split(l);
	S.erase(itl,itr);
	S.insert(Node(l,r,v));
}
void reverse(int l,int r){
	IT itr=split(r+1),itl=split(l);
	for (;itl!=itr;++itl) itl->v^=1;
}
int query(int l,int r){
	IT itr=split(r+1),itl=split(l);
	int res=0;
	for (;itl!=itr;++itl)if(itl->v)res+=itl->r-itl->l+1;
	return res;
}
int querymax(int l,int r){
	IT itr=split(r+1),itl=split(l);
	int ans=0,res=0,pre=0;
	for (;itl!=itr;++itl){
		if (itl->v){
			if (!pre) pre=1,res=itl->r-itl->l+1;
			else if (pre==1) res+=itl->r-itl->l+1;
		}
		else{
			ans=max(ans,res);
			res=pre=0;
		}
	}
	ans=max(ans,res);
	return ans;
}
int main(){
	read(n),read(m);
	for (i=1;i<=n;++i){
		read(x);
		S.insert(Node(i,i,x));
	}
	S.insert(Node(n+1,n+1,0));
	for (;m--;){
		read(op),read(a),read(b),a++,b++;
		if (op==0) assign(a,b,0);
		if (op==1) assign(a,b,1);
		if (op==2) reverse(a,b);
		if (op==3) printf("%d\n",query(a,b)); 
		if (op==4) printf("%d\n",querymax(a,b));
	}
	return 0;
}