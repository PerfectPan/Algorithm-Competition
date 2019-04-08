#include <bits/stdc++.h>
#define MP make_pair
#define PB emplace_back
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
const int S=26;
int tot,last,i,j,len,T,sg[N<<1],firstpos[N<<1],sum[N<<1],pre[N<<1],son[N<<1][S],ml[N<<1];
char s[N],t[N];
void init(){
	tot=last=1;
	memset(son,0,sizeof(son));
	memset(sg,-1,sizeof(sg));
}
void extend(int w){
	int p=++tot,x=last,r,q;firstpos[p]=ml[x];
	for (ml[last=p]=ml[x]+1;x&&!son[x][w];x=pre[x]) son[x][w]=p;
	if (!x) pre[p]=1;
	else if (ml[x]+1==ml[q=son[x][w]]) pre[p]=q;
	else{
		pre[r=++tot]=pre[q];memcpy(son[r],son[q],sizeof(son[r]));
		ml[r]=ml[x]+1;pre[p]=pre[q]=r;firstpos[r]=firstpos[q];
		for (;x&&son[x][w]==q;x=pre[x]) son[x][w]=r;
	}
}
int dfs(int idx){
	if (~sg[idx]) return sg[idx];
	set<int>SG;
	for (int i=0;i<S;++i)if(son[idx][i]){
		SG.insert(dfs(son[idx][i]));
	}
	for (int i=0;;++i) if(SG.find(i)==SG.end()) return sg[idx]=i; 
}
int getSG(const char *s){
	int cur=1;
	for (int i=0;s[i];++i){
		cur=son[cur][s[i]-'a'];
	}
	return sg[cur];
}
int main(){
	while (~scanf("%s",s+1)){
		len=strlen(s+1);
		init();
		for (i=1;i<=len;++i) extend(s[i]-'a');
		dfs(1);
		int ans=0;
		for (read(T);T--;){
			scanf("%s",t+1);
			ans^=getSG(t+1);
		}
		puts(ans?"Alice":"Bob");
	}
	return 0;
}