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
const int N=1e5+10;
int T,n,x,i,a[N];
int main(){
    for (read(T);T--;){
        read(n),read(x);
        for (i=1;i<=n;++i) read(a[i]);
        sort(a+1,a+1+n);
        int mx=a[n];
        if (x>=mx){
            if (x%mx==0) printf("%d\n",x/mx);
            else printf("%d\n",x/mx+1);
        }
        else{
            bool flag=0;
            for (i=1;i<=n;++i){
                if (a[i]==x){
                    flag=1;
                    break;
                }
            }
            if (flag) puts("1");
            else puts("2");
        }
    }
    return 0;
}