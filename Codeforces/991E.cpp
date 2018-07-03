#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x; 
}
const int N=10000+10;
char s[20];
int i,len,cnt[10],num[10];
ll ans,jc[20];
void dfs(int x){
	if (x==10){
		int len=0;
		for (int i=0;i<10;i++) len+=num[i];
		ll tmp=jc[len];
		for (int i=0;i<10;i++){
			tmp/=jc[num[i]];
		}
		ans+=tmp;
		if (cnt[0]>=1){
			tmp=jc[len-1];
			tmp/=jc[num[0]-1];
			for (int i=1;i<10;i++){
				tmp/=jc[num[i]];
			}
			ans-=tmp;
		}
		return;
	}
	if (!cnt[x]) dfs(x+1);
	else{
		for (int i=1;i<=cnt[x];i++){
			num[x]=i;
			dfs(x+1);
		}
	}
}
int main(){
	scanf("%s",s);
	len=strlen(s);
	for (jc[0]=i=1;i<=19;i++) jc[i]=jc[i-1]*i;
	for (i=0;s[i];i++) cnt[s[i]-'0']++;
	dfs(0);
	printf("%lld\n",ans);
	return 0;
}