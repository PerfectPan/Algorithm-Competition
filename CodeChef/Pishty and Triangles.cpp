#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while(ch<'0'||ch>'9')f|=(ch=='-'),ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N=1e5+10;
int n,Q,op,i,l,r,x;
vector<int>node[N<<2];
#define lson root<<1,l,mid
#define rson root<<1|1,mid+1,r
inline bool cmp(int&a,int&b){return a>b;}
vector<int> pushup(vector<int> a,vector<int> b){
    vector<int> c(a.size()+b.size());
    merge(a.begin(),a.end(),b.begin(),b.end(),c.begin(),cmp);
    if (c.size()>50) c.resize(50);
    return c;
}
void build(int root,int l,int r){
    if (l==r){
        read(x);
        node[root].push_back(x);
        return;
    }
    int mid=l+((r-l)>>1);
    build(lson);
    build(rson);
    node[root]=pushup(node[root<<1],node[root<<1|1]);
}
void update(int root,int l,int r,int pos,int val){
    if (l==r){
        node[root].clear();
        node[root].push_back(val);
        return;
    }
    int mid=l+((r-l)>>1);
    if (pos<=mid) update(lson,pos,val);
    else update(rson,pos,val);
    node[root]=pushup(node[root<<1],node[root<<1|1]);
}
vector<int> query(int root,int l,int r,int L,int R){
    if (L<=l&&r<=R) return node[root];
    int mid=l+((r-l)>>1);
    if (R<=mid) return query(lson,L,R);
    else if (L>mid) return query(rson,L,R);
    else return pushup(query(lson,L,R),query(rson,L,R));
}
ll get(int L,int R){
    vector<int> v=query(1,1,n,L,R);
    ll ans=0;
    for (int i=(int)v.size()-3;i>=0;i--){
        if (v[i+2]+v[i+1]>v[i]){
            ans=max(ans,1LL*v[i]+v[i+1]+v[i+2]);
        }
    }
    return ans;
}
int main(){
    read(n),read(Q);
    build(1,1,n);
    for (;Q--;){
        read(op),read(l),read(r);
        if (op==1) update(1,1,n,l,r);
        else{
            printf("%lld\n",get(l,r));
        }
    }
    return 0;
}
