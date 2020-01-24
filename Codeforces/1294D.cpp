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
int q,x,a,mex,y;
map<ll,int>vis;
int main(){
    read(q),read(x);
    for (;q--;){
        read(y);
        y%=x;
        int l=0,r=1000000000,ans=0;
        while (l<=r){
            int mid=l+((r-l)>>1);
            if (vis.find(1LL*mid*x+y)==vis.end()){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        vis[1LL*ans*x+y]=1;
        while (vis.find(1LL*mex)!=vis.end()) mex++;
        printf("%d\n",mex);
    }
    return 0;
}