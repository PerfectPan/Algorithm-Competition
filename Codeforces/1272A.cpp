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
int q,a[3],b[3],c[3];
int main(){
    for (read(q);q--;){
        read(a[0]),read(b[0]),read(c[0]);
        a[1]=a[0]+1;
        b[1]=b[0]+1;
        c[1]=c[0]+1;
        a[2]=a[0]-1;
        b[2]=b[0]-1;
        c[2]=c[0]-1;
        int ans=-1;
        for (int i=0;i<3;++i){
            for (int j=0;j<3;++j){
                for (int k=0;k<3;++k){
                    int dis=abs(a[i]-b[j])+abs(b[j]-c[k])+abs(c[k]-a[i]);
                    if (ans==-1) ans=dis;
                    else ans=min(ans,dis);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}