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
int a,b,c,d,e,f;
int main(){
    read(a),read(b),read(c),
    read(d),read(e),read(f);

    b=min(b,c);
    ll ans=0;
    if (e>f){
        ans+=1LL*e*min(a,d);
        d-=min(a,d);
        ans+=1LL*f*min(b,d);
    }
    else{
        ans+=1LL*f*min(b,d);
        d-=min(b,d);
        ans+=1LL*e*min(a,d);
    }
    cout<<ans<<endl;
    return 0;
}