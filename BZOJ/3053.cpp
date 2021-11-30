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
#define ALL(x) x.begin(),x.end()
#define F first
#define S second
using namespace std;
typedef long long ll;
const int maxn=500000+5;
const int INF=0x3f3f3f3f;
const int P=1000000007;
const double PI=acos(-1.0);
template<typename T>
inline T read(T&x){
    x=0;int _f=0;char ch=getchar();
    while(ch<'0'||ch>'9')_f|=(ch=='-'),ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x=_f?-x:x;
}
int n,m,D,k,tt,root;
struct A{
    int d[5],dis;
    bool operator<(const A&rhs)const{
        return dis<rhs.dis;
    }
}a[maxn],tmp;
struct T{int d[5],s[2],mn[5],mx[5];}t[maxn];
priority_queue<A>Q;
#define ls t[root].s[0]
#define rs t[root].s[1]
#define oo 1000000000000
void umin(int&a,int b){if(a>b)a=b;}
void umax(int&a,int b){if(a<b)a=b;}
void maintain(int f,int x){
    for (int i=0;i<m;i++){
        umin(t[f].mn[i],t[x].mn[i]);
        umax(t[f].mx[i],t[x].mx[i]);
    }
}
bool cmp(const A&a,const A&b){return a.d[D]<b.d[D];}
int build(int l,int r,int d){
    D=d;int root=l+((r-l)>>1);
    nth_element(a+l,a+root,a+r+1,cmp);
    for (int i=0;i<m;i++){
        t[root].d[i]=t[root].mn[i]=t[root].mx[i]=a[root].d[i];
    }
    ls=rs=0;
    if (l<root) ls=build(l,root-1,(d+1)%m),maintain(root,ls);
    if (root<r) rs=build(root+1,r,(d+1)%m),maintain(root,rs);
    return root;
}
int sqr(int x){return x*x;}
int cnt(int p){
    int ret=0;
    for (int i=0;i<m;i++){
        ret+=sqr(t[p].d[i]-tmp.d[i]);
    }
    return ret;
}
int getdis(int p){
    int ret=0;int i;
    for (i=0;i<m;i++) if (tmp.d[i]<t[p].mn[i]) ret+=sqr(t[p].mn[i]-tmp.d[i]);
    for (i=0;i<m;i++) if (tmp.d[i]>t[p].mx[i]) ret+=sqr(tmp.d[i]-t[p].mx[i]);
    return ret;
}
void query(int root){
    ll tmp=cnt(root),d[2];A AA;
    if (ls) d[0]=getdis(ls);else d[0]=oo;
    if (rs) d[1]=getdis(rs);else d[1]=oo;
    for (int i=0;i<m;i++) AA.d[i]=t[root].d[i];
    AA.dis=tmp;
    if (Q.size()<k) Q.push(AA);
    else if (Q.top().dis>tmp) Q.pop(),Q.push(AA);
    tmp=d[0]>=d[1];
    if (t[root].s[tmp] && (Q.size()<k || d[tmp]<Q.top().dis)) query(t[root].s[tmp]);tmp^=1;
    if (t[root].s[tmp] && (Q.size()<k || d[tmp]<Q.top().dis)) query(t[root].s[tmp]);
}
int main(){
    while (~scanf("%d%d",&n,&m)){
        for (int i=1;i<=n;i++){
            for (int j=0;j<m;j++){
                read(a[i].d[j]);
            }
        }
        root=build(1,n,0);
        for (read(tt);tt--;){
            for (int i=0;i<m;i++) read(tmp.d[i]);
            read(k),query(root);
            printf("the closest %d points are:\n",k);
            A dis[15];
            int n=Q.size();
            while (!Q.empty()) dis[n--]=Q.top(),Q.pop();
            for (int i=1;i<=k;i++){
                for (int j=0;j<m;j++) printf("%d%c",dis[i].d[j],j==m-1?'\n':' ');
            }
        }
    }
    return 0;
}
