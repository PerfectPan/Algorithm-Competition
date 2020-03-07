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
int i,j,pre[26][N],suf[26][N];
char s[N];
int main(){
    scanf("%s",s+1);
    int len=strlen(s+1);
    for (i=1;i<=len;++i){
        for (j=0;j<26;++j) pre[j][i]=pre[j][i-1];
        pre[s[i]-'a'][i]++;
    }
    for (i=len;i>=1;--i){
        for (j=0;j<26;++j) suf[j][i]=suf[j][i+1];
        suf[s[i]-'a'][i]++;
    }
    ll ans=0;
    for (i=0;i<26;++i){
        ans=max(ans,1ll*pre[i][len]*(pre[i][len]-1)/2ll);
        ans=max(ans,1ll*pre[i][len]);
    }
    for (i=0;i<26;++i){
        for (j=0;j<26;++j)if(i!=j){
            ll cnt=0;
            for (int k=1;k<len;++k){
                if (s[k]-'a'==i) cnt+=suf[j][k+1];
            }
            // if (cnt)
            // cout<<i<<" "<<j<<" "<<cnt<<endl;
            ans=max(ans,cnt);
        }
    }
    printf("%lld\n",ans);
    return 0;
}