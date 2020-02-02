#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N=1e5+10;
int T,i,j,k,x,n,tn,nxt[N][26],st[26];
char s[N],t[N];
int main(){
    for (read(T);T--;){
        scanf("%s%s",s+1,t+1);
        n=strlen(s+1),tn=strlen(t+1);
        for (j=0;j<26;++j) nxt[n][j]=n+1;
        for (i=n;i;--i){
            for (j=0;j<26;++j) nxt[i-1][j]=nxt[i][j];
            nxt[i-1][s[i]-'a']=i;
        }
        memset(st,-1,sizeof(st));
        for (i=1;i<=n;++i){
            if (st[s[i]-'a']==-1) st[s[i]-'a']=i;
        }
        int pos=-1,ans=0;
        for (i=1;i<=tn;++i){
            if (pos==-1){
                if (st[t[i]-'a']==-1){
                    ans=-1;
                    break;
                }
                else{
                    pos=st[t[i]-'a'];
                    ans++;
                }
            }
            else{
                if (nxt[pos][t[i]-'a']==n+1){
                    if (st[t[i]-'a']==-1){
                        ans=-1;
                        break;
                    }
                    else{
                        pos=st[t[i]-'a'];
                        ans++;
                    }
                }
                else pos=nxt[pos][t[i]-'a'];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}