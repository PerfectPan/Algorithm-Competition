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
	mutable bool v;
	Node(int L,int R=-1,bool V=false):l(L),r(R),v(V){}
	bool operator<(const Node&rhs)const{
		return l<rhs.l;
	}
};
set<Node>S;
int n,q,i,l,r,k,ans;
IT split(int pos){
	IT it=S.lower_bound(Node(pos));
	if (it!=S.end() && it->l==pos) return it;
	--it;
	int l=it->l,r=it->r;
	bool v=it->v;
	S.erase(it);
	S.insert(Node(l,pos-1,v));
	return S.insert(Node(pos,r,v)).first;
}
void assign(int l,int r,bool v){
	IT itr=split(r+1),itl=split(l);
	int num=0;
	for (;itl!=itr;++itl){
		if (itl->v){
			num+=itl->r-itl->l+1;
		}
	}
	itl=split(l);
	S.erase(itl,itr);
	S.insert(Node(l,r,v));
	if (v) ans=ans-num+r-l+1;
	else ans=ans-num;
} 
int main(){
	read(n),read(q);
	S.insert(Node(1,n,true));
	for (ans=n;q--;){
		read(l),read(r),read(k);
		if (k==1) assign(l,r,false);
		else assign(l,r,true);
		printf("%d\n",ans);
	}
	return 0;
}