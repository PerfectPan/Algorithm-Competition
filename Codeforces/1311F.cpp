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
const int N=2e5+10;
struct Node{
    int x,v;
    bool operator < (const Node& rhs)const{
        return x<rhs.x;
    }
}p[N];
int n,i,tot;
ll sum[2][N],ans;
vector<int>vec;
void compress(){
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    tot=(int)vec.size();
}
inline int lowbit(int x){return x&(-x);}
void add(int x,int v,int i){for(;x<=tot;x+=lowbit(x))sum[i][x]+=v;}
ll get(int x,int i){
    ll res=0;
    for (;x>0;x-=lowbit(x)) res+=sum[i][x];
    return res;
}
int main(){
    read(n);
    for (i=1;i<=n;++i) read(p[i].x);
    for (i=1;i<=n;++i) read(p[i].v),vec.push_back(p[i].v);
    compress();
    sort(p+1,p+1+n);
    for (i=1;i<=n;++i){
        int pos=lower_bound(vec.begin(),vec.end(),p[i].v)-vec.begin()+1;
        ans+=get(pos,0)*p[i].x-get(pos,1);
        add(pos,1,0);
        add(pos,p[i].x,1);
    }
    printf("%lld\n",ans);
    return 0;
}