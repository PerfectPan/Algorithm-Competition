#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N=500+10;
const ll INF=2e18;
int i,j,x,n,match[N],pre[N];
ll a[N],b[N],k[N],cost[N][N],lx[N],ly[N],slack[N];
bool vy[N];
void augment(int root){
    fill(vy+1,vy+n+1,false);
    fill(slack+1,slack+n+1,INF);
    int py;
    match[py=0]=root;
    do{
        vy[py]=true;
        int x=match[py],yy;
        ll delta=INF;
        for (int y=1;y<=n;y++){
            if (!vy[y]){
                if (lx[x]+ly[y]-cost[x][y]<slack[y]){
                    slack[y]=lx[x]+ly[y]-cost[x][y];
                    pre[y]=py;
                }
                if (slack[y]<delta){
                    delta=slack[y];
                    yy=y;
                }
            }
        }
        for (int y=0;y<=n;y++){
            if (vy[y]){
                lx[match[y]]-=delta;
                ly[y]+=delta;
            }
            else{
                slack[y]-=delta;
            }
        }
        py=yy;
    }while(~match[py]);
    do{
        int cnt=pre[py];
        match[py]=match[cnt];
        py=cnt;
    }while(py);
}
ll KM(){
    for (int i=1;i<=n;i++){
        lx[i]=ly[i]=0;
        match[i]=-1;
        for (int j=1;j<=n;j++) lx[i]=max(lx[i],cost[i][j]);
    }
    ll ans=0;
    for (int i=1;i<=n;i++) augment(i);
    for (int i=1;i<=n;i++){
        ans+=lx[i];
        ans+=ly[i];
    }
    return ans;
}
int main(){
    read(n);
    for (i=1;i<=n;i++){
    	read(a[i]),read(b[i]),read(k[i]);
        for (j=1;j<=n;j++){
            cost[i][j]=max(a[i]-b[i]*min(k[i],j-1LL),0LL);
        }
    }
    printf("%lld\n",KM());
    return 0;
}