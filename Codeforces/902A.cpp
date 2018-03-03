#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while(ch<'0'||ch>'9')f|=(ch=='-'),ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N=100+5;
int n,m,i,x,y,a[N];
bool vis[N];
int main(){
    memset(a,-1,sizeof(-1));
    read(n),read(m);
    for (i=1;i<=n;i++){
        read(x),read(y);
        if (a[x]==-1) a[x]=y;
        else a[x]=max(a[x],y);
    }
    queue<int>Q;
    if (a[0]==-1) puts("NO");
    else{
        Q.push(0);
        while(!Q.empty()){
            int cur=Q.front();Q.pop();
            if (cur==m) return puts("YES"),0;
            int lim=a[cur];
            for (i=cur+1;i<=lim;i++){
                if (a[i]!=-1&&!vis[i]) Q.push(i),vis[i]=true;
            }
        }
        puts("NO");
    }
    return 0;
}
