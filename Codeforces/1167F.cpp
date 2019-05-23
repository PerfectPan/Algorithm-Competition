#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N=5e5+10;
const int P=1e9+7;
int n,i,res,sum[2][N];
pair<int,int> a[N];
inline void up(int&a,int b){a+=b;if(a>=P)a-=P;}
inline int lowbit(int x){return x&(-x);}
void add(int x,int v,int tp){
    for (;x<=n;x+=lowbit(x)) up(sum[tp][x],v); 
}
int get(int x,int tp){
    int res=0;
    for (;x>0;x-=lowbit(x)) up(res,sum[tp][x]);
    return res;
}
inline int query(int l,int r,int tp){return (get(r,tp)-get(l-1,tp)+P)%P;}
int main(){
    read(n);
    for (i=1;i<=n;++i) read(a[i].first),a[i].second=i;
    sort(a+1,a+1+n);
    for (i=1;i<=n;++i){
        up(res,1LL*a[i].first*a[i].second%P*(n-a[i].second+1)%P);
        up(res,1LL*a[i].first*(n-a[i].second+1)%P*query(1,a[i].second,0)%P);
        up(res,1LL*a[i].first*a[i].second%P*query(a[i].second,n,1)%P);
        add(a[i].second,a[i].second,0);
        add(a[i].second,n-a[i].second+1,1);
    }
    printf("%d\n",res);
    return 0;
}