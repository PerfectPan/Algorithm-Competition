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
int n,sx,sy,x,y,i,a,b,c,d,ans;
int main(){
    read(n),read(sx),read(sy);
    for (i=1;i<=n;++i){
        read(x),read(y);
        if (x>sx) a++;
        if (x<sx) b++;
        if (y>sy) c++;
        if (y<sy) d++;
    }
    ans=max(ans,a);
    ans=max(ans,b);
    ans=max(ans,c);
    ans=max(ans,d);
    cout<<ans<<endl;
    if (ans==a) cout<<(sx+1)<<" "<<(sy)<<endl;
    else if (ans==b) cout<<(sx-1)<<" "<<(sy)<<endl;
    else if (ans==c) cout<<(sx)<<" "<<(sy+1)<<endl;
    else cout<<(sx)<<" "<<(sy-1)<<endl;
    return 0;
}