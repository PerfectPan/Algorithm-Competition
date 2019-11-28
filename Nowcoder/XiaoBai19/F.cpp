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
int i,j,len,ans,nxt[N],cnt[N];
char s[N];
int main(){
    scanf("%s",s+1);len=strlen(s+1);
    for (nxt[1]=j=0,i=2;i<=len;nxt[i++]=j){
        while (j&&s[j+1]!=s[i]) j=nxt[j];
        j+=(s[j+1]==s[i]);
    }
    for (i=1;i<=len;++i) cnt[i]=1;
    for (i=len;i>=1;--i) cnt[nxt[i]]+=cnt[i];
    for (ans=nxt[len];ans;ans=nxt[ans]){
        if (cnt[ans]>=3) break;
    }
    for (i=1;i<=ans;++i) putchar(s[i]);
    puts("");
    return 0;
}