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
const int N=2e5+10;
int n,k,len,i;
bool vis[26];
char s[N],s2[N];
ll ans;
int main(){
    read(n),read(k);
    scanf("%s",s+1);len=strlen(s+1);
    for (i=0;i<k;++i){
        scanf("%s",s2);
        vis[s2[0]-'a']=1;
    }
    int cnt=0;
    for (i=1;i<=len;++i){
        if (!vis[s[i]-'a']){
            ans+=1LL*cnt*(cnt+1)/2LL;
            cnt=0;
        }
        else cnt+=1;
    }
    ans+=1LL*cnt*(cnt+1)/2LL;
    printf("%lld\n",ans);
    return 0;
}