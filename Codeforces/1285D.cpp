#include<bits/stdc++.h>
#define MP make_pair
#define PB emplace_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N=1e5*30*2+10;
int n,x,i,tot=1,son[N][2];
void add(int x){
    int pos=1;
    for (int i=29;i>=0;--i){
        if (!son[pos][(x>>i)&1]) son[pos][(x>>i)&1]=++tot;
        pos=son[pos][(x>>i)&1];
    }
}
int dfs(int pos,int len){
    if (!pos || len<0) return 0;
    if (!son[pos][0]) return dfs(son[pos][1],len-1);
    if (!son[pos][1]) return dfs(son[pos][0],len-1);
    return min(dfs(son[pos][0],len-1),dfs(son[pos][1],len-1))|(1<<len);
}
int main(){
    read(n);
    for (i=1;i<=n;++i){
        read(x);
        add(x);
    }
    printf("%d\n",dfs(1,29));
    return 0;
}




