#include <bits/stdc++.h>
using namespace std;
const int maxn=10005;
const int INF=1000000007;
template<typename T>
inline T read(T&x){
    x=0;int _f=0;char ch=getchar();
    while(ch<'0'||ch>'9')_f|=(ch=='-'),ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x=_f?-x:x;
}
int n,m;
struct Link_Cut_Tree{
    int top,ch[maxn][2],fa[maxn],q[maxn],key[maxn],add[maxn],Max[maxn];bool rev[maxn];
    Link_Cut_Tree(){
        top=0;memset(fa,0,sizeof(fa));
        memset(ch,0,sizeof(ch));
        memset(rev,0,sizeof(rev));
    }
    bool isroot(int x){return !fa[x]||ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x;}
    void UpdateRev(int x){
        if(!x)return;
        swap(ch[x][0],ch[x][1]);
        rev[x]^=1;
    }
    void pushdown(int x){
        if(rev[x]){
            UpdateRev(ch[x][0]);
            UpdateRev(ch[x][1]);
            rev[x]=0;
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
    }
    void access(int x){for(int t=0;x;t=x,x=fa[x])splay(x),ch[x][1]=t;}
    void makeroot(int x){access(x);splay(x);UpdateRev(x);}
    void link(int x,int y){makeroot(x);fa[x]=y;access(x);}
    void split(int x,int y){makeroot(x);access(y);splay(y);}
    void cut(int x,int y){split(x,y);fa[ch[y][0]]=0;ch[y][0]=0;}
    int find(int x){
        access(x);splay(x);int y=x;
        while (ch[y][0]) y=ch[y][0];
        return y;
    }
}T;
int main(){
    char s[10];int x,y;
    read(n),read(m);
    for (int i=1;i<=m;i++){
        scanf("%s",s);read(x),read(y);
        if (s[0]=='C') T.link(x,y);
        if (s[0]=='D') T.cut(x,y);
        if (s[0]=='Q'){
            int xx=T.find(x),yy=T.find(y);
            if (xx==yy) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
