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
const int N=1e3+10;
int n,i,f,x[N],y[N];
vector<int>a[2][2];
int main(){
    read(n);
    for (i=1;i<=n;++i){
        read(x[i]),read(y[i]);
        x[i]+=1e6;
        y[i]+=1e6;
    }
    for (f=1,i=n;i>=1;--i){
        x[i]-=x[1],y[i]-=y[1];
        if ((x[i]&1) || (y[i]&1)) f=0;
    }
    for (;f;){
        for (i=1;i<=n;++i){
            x[i]/=2,y[i]/=2;
            if ((x[i]&1) || (y[i]&1)) f=0;
        }
    }
    for (i=1;i<=n;++i){
        a[x[i]&1][y[i]&1].PB(i);
    }
    if ((int)a[0][1].size() || (int)a[1][0].size()){
        printf("%d\n",(int)a[0][0].size()+(int)a[1][1].size());
        for (auto x:a[0][0]) printf("%d ",x);
        for (auto x:a[1][1]) printf("%d ",x);
        puts("");
    }
    else{
        printf("%d\n",(int)a[0][0].size());
        for (auto x:a[0][0]) printf("%d ",x);
        puts("");
    }
    return 0;
}