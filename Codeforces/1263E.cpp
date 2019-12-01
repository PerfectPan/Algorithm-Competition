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
const int N=1e6+10;
int n,i,topA=1,topB,a[N],b[N],pre[N],suf[N],f[N],f2[N],f3[N],f4[N];
char s[N];
void update(int x,int val){
    a[x]=val;
    pre[x]=pre[x-1]+a[x];
    f[x]=max(f[x-1],pre[x]);
    f2[x]=min(f2[x-1],pre[x]);
}
int main(){
    read(n);
    scanf("%s",s+1);
    int ans=-1;
    f2[0]=f4[0]=0x3f3f3f3f;
    for (i=1;i<=n;++i){
        if (s[i]=='(') update(topA,1);
        else if (s[i]==')') update(topA,-1);
        else if (s[i]=='L'){
            if (topA>=2){
                b[++topB]=a[topA--];
                suf[topB]=suf[topB-1]+b[topB]*-1;
                f3[topB]=max(f3[topB-1],suf[topB]);
                f4[topB]=min(f4[topB-1],suf[topB]);
            }
        }
        else if (s[i]=='R'){
            ++topA;
            if (topB){
                update(topA,b[topB]);
                topB--;
            }
            else{
                update(topA,0);
            }
        }
        else update(topA,0);

        if (topB==0){
            if (pre[topA]==0 && f2[topA]>=0) ans=f[topA];
            else ans=-1;
        }
        else{
            if (pre[topA]==suf[topB] && f2[topA]>=0 && f4[topB]>=0){
                ans=max(f[topA],f3[topB]);
            }
            else ans=-1;
        }
        printf("%d%c",ans,i==n?'\n':' ');
    }
    return 0;
}