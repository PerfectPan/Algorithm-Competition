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
const int N=20+10;
int n,m,i,q,y,lcm2;
string s[N],t[N];
int main(){
    read(n),read(m);lcm2=n/__gcd(n,m)*m;
    for (i=0;i<n;++i) cin>>s[i];
    for (i=0;i<m;++i) cin>>t[i];
    for (read(q);q--;){
        read(y);y-=1;
        y%=lcm2;
        int x=y%n,xx=y%m;
        cout<<(s[x]+t[xx])<<endl;
    }
    return 0;
}