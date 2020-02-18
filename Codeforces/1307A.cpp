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
const int N=100+10;
int T,i,n,d,a[N];
int main(){
    for (read(T);T--;){
        read(n),read(d);
        for (i=1;i<=n;++i){
            read(a[i]);
            if (i>1 && d>0){
                int num=i-1;
                if (d>=num*a[i]){
                    d-=num*a[i];
                    a[1]+=a[i];
                }
                else{
                    a[1]+=d/num;
                    d=0;
                }
            }
        }
        printf("%d\n",a[1]);
    }
    return 0;
}