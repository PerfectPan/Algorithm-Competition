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
int T,n,x,i,pre[N];
char s[N];
int main(){
    for (read(T);T--;){
        read(n),read(x);
        scanf("%s",s+1);
        int cnt=0;
        for (int i=1;i<=n;++i){
            pre[i]=pre[i-1];
            if (s[i]=='0') pre[i]++;
            else pre[i]--;
            cnt+=pre[i]==x;
        }
        if (pre[n]==0){
            if (cnt>0) puts("-1");
            else puts("0");
        }
        else{
            int delta=pre[n],ans=0;
            for (int i=1;i<=n;++i){
                if (delta>0){
                    if (pre[i]<=x && (x-pre[i])%delta==0) ans++;
                }
                else{
                    if (pre[i]>=x && (pre[i]-x)%(-delta)==0) ans++;
                }
            }
            if (x==0) ans++;
            printf("%d\n",ans);
        }
    }
    return 0;
}