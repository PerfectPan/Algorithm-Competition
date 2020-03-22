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
const int N=2e6+10;
struct Node{
    int cnt,nxt[26];
    void clear(){
        cnt=0;
        for (int i=0;i<26;++i) nxt[i]=-1;
    }
}Trie[N];
int T,n,k,i,tot,ans,cas=1;
char s[N];
void ins(char *s){
    int len=strlen(s),pos=0;
    for (int i=0;i<len;++i){
        int idx=s[i]-'A';
        Trie[pos].cnt++;
        if (Trie[pos].nxt[idx]==-1){
            Trie[pos].nxt[idx]=++tot;
            Trie[tot].clear();
        }
        pos=Trie[pos].nxt[idx];
    }
    Trie[pos].cnt++;
}
int dfs(int u,int dep){
    int sum=0;
    for (int i=0;i<26;++i)if(~Trie[u].nxt[i]){
        sum+=dfs(Trie[u].nxt[i],dep+1);
    }
    Trie[u].cnt-=sum;
    sum+=Trie[u].cnt/k*k;
    ans+=Trie[u].cnt/k*dep;
    return sum;
}
int main(){
    for (read(T);T--;){
        read(n),read(k);
        Trie[0].clear(),tot=0;
        for (i=1;i<=n;++i){
            scanf("%s",s+1);
            ins(s+1);
        }
        ans=0,dfs(0,0);
        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}