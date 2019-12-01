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
int n,i,j,len,cnt,num[N],fa[N];
char s[N];
inline int Find(int x){return x==fa[x]?x:fa[x]=Find(fa[x]);}
int main(){
    read(n);
    for (i=1;i<=n;++i){
        scanf("%s",s+1);len=strlen(s+1);
        for (j=1;j<=len;++j){
            num[i]|=(1<<(s[j]-'a'));
        }
        fa[i]=i;
    }
    cnt=n;
    for (i=0;i<26;++i){
        int pre=0;
        for (j=1;j<=n;++j)if(num[j]&(1<<i)){
            if (!pre) pre=j;
            else{}
                int u=Find(pre),v=Find(j);
                if (u!=v){
                    cnt-=1;
                    fa[u]=v;
                }
                pre=j;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}