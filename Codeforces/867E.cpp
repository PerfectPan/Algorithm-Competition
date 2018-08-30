#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
int T,n,x,i;
ll ans;
priority_queue<int>Q;
int main(){
    read(n);
    for (ans==0,i=1;i<=n;i++){
        read(x);
        if (Q.empty()||-Q.top()>=x){
            Q.push(-x);
        }
        else{
            int cur=-Q.top();Q.pop();
            ans+=x-cur;
            Q.push(-x);
            Q.push(-x);
        }
    }
    printf("%lld\n",ans);
    return 0;
}