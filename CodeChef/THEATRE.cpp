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
int T,n,d,i,a[4][4],id[4],id2[4];
int coin[4]={25,50,75,100};
char s[2];
ll tot;
inline int TimeID(int x){return x/3-1;}
int main(){
    for (read(T);T--;){
        read(n);
        memset(a,0,sizeof(a));
        for (i=1;i<=n;++i){
            scanf("%s%d",s,&d);
            int id=s[0]-'A';
            a[id][TimeID(d)]++;
        }
        for (i=0;i<4;++i) id[i]=i;
        ll ans=-400;
        do{
            for (i=0;i<4;++i) id2[i]=i;
            do{
                ll ret=0;
                for (i=0;i<4;++i){
                    if (a[id[i]][i]) ret+=1LL*a[id[i]][i]*coin[id2[i]];
                    else ret-=100;
                }
                ans=max(ans,ret);
            }while(next_permutation(id2,id2+4));
        }while(next_permutation(id,id+4));
        printf("%lld\n",ans);
        tot+=ans;
    }
    printf("%lld\n",tot);
    return 0;
}