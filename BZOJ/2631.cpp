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
using namespace std;
typedef unsigned int ll;
const int maxn=1e5+5;
const int INF=0x3f3f3f3f;
const int P=51061;
const double PI=acos(-1.0);
template<typename T> inline T gcd(T&a,T&b){return b==0?a:gcd(b,a%b);}
template<typename T> inline T lcm(T&a,T&b){return a/gcd(a,b)*b;}
template<typename T>
inline T read(T&x){
    x=0;int _f=0;char ch=getchar();
    while(ch<'0'||ch>'9')_f|=(ch=='-'),ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x=_f?-x:x;
}
int n,q,u,v,c,d;
char op[5];
struct Link_Cut_Tree{
    int top,fa[maxn],ch[maxn][2],q[maxn];
    ll sum[maxn],val[maxn],sz[maxn],add[maxn],mul[maxn];bool rev[maxn];
    Link_Cut_Tree(){
        top=0;memset(fa,0,sizeof(fa));
        memset(ch,0,sizeof(ch));
        memset(add,0,sizeof(add));
        memset(rev,false,sizeof(rev));
        fill(mul,mul+maxn,1);
    }
    bool isroot(int x){return ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x;}
    void UpdateAdd(int x,ll d,ll v){
        if (!x) return;
        add[x]=(add[x]*v+d)%P;
        mul[x]=(mul[x]*v)%P;
        val[x]=(val[x]*v+d)%P;
        sum[x]=(sum[x]*v+d*sz[x])%P;
    }
    void UpdateRev(int x){
        if(!x)return;
        swap(ch[x][0],ch[x][1]);
        rev[x]^=1;
    }
    void pushup(int x){
        sum[x]=(sum[ch[x][0]]+sum[ch[x][1]]+val[x])%P;
        sz[x]=(sz[ch[x][0]]+sz[ch[x][1]]+1)%P;
    }
    void pushdown(int x){
        if (rev[x]){
            UpdateRev(ch[x][0]);
            UpdateRev(ch[x][1]);
            rev[x]=0;
        }
        if (add[x]||mul[x]!=1){
            UpdateAdd(ch[x][0],add[x],mul[x]);
            UpdateAdd(ch[x][1],add[x],mul[x]);
            add[x]=0;
            mul[x]=1;
        }
    }
    void Rotate(int x){
        int y=fa[x],kind=ch[y][1]==x;
        ch[y][kind]=ch[x][kind^1];
        fa[ch[y][kind]]=y;
        if (fa[y]){
            int z=fa[y];
            if (ch[z][0]==y) ch[z][0]=x;else if (ch[z][1]==y) ch[z][1]=x;
        }
        fa[x]=fa[y];fa[y]=x;ch[x][kind^1]=y;
        pushup(y);
    }
    void splay(int x){
        q[top=1]=x;
        for (int i=x;!isroot(i);i=fa[i]) q[++top]=fa[i];
        while (top) pushdown(q[top--]);
        while(!isroot(x)){
            int y=fa[x],z=fa[y];
            if (!isroot(y)){
                if ((ch[y][0]==x)^(ch[z][0]==y)) Rotate(x);
                else Rotate(y);
            }
            Rotate(x);
        }
        pushup(x);
    }
    void access(int x){for(int t=0;x;t=x,x=fa[x])splay(x),ch[x][1]=t,pushup(x);}
    void makeroot(int x){access(x);splay(x);UpdateRev(x);}
    void link(int x,int y){makeroot(x);fa[x]=y;access(x);}
    void split(int x,int y){makeroot(x);access(y);splay(y);}
    void cut(int x,int y){split(x,y);fa[ch[y][0]]=0;ch[y][0]=0;pushup(y);}
    int find(int x){
        access(x);splay(x);int y=x;
        while (ch[y][0]) y=ch[y][0];
        return y;
    }
    int ask(int x,int y){split(x,y);return sum[y];}
}T;
int main(){
    read(n),read(q);
    for (int i=1;i<=n;i++) T.sz[i]=T.sum[i]=T.val[i]=1;
    for (int i=1;i<n;i++){
        read(u),read(v);
        T.link(u,v);
    }
    for (;q--;){
        scanf("%s",op);read(u),read(v);
        if (op[0]=='+'){
            read(c);
            T.split(u,v);
            T.UpdateAdd(v,c,1);
        }
        else if (op[0]=='-'){
            T.cut(u,v);
            read(u),read(v);
            T.link(u,v);
        }
        else if (op[0]=='*'){
            read(c);
            T.split(u,v);
            T.UpdateAdd(v,0,c);
        }
        else{
            printf("%d\n",T.ask(u,v));
        }
    }
    return 0;
}
