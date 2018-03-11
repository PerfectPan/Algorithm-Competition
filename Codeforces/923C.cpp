#include <bits/stdc++.h>
using namespace std;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0'||ch>'9')f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=300000+10;
int n,i,x,a[N];
struct Trie{
	int tot,i,ch[N*30][2],cnt[N*30];
	void Insert(int x){
		int p=0;
		for (i=29;i>=0;i--){
			int c=((x>>i)&1);
			if (!ch[p][c]) ch[p][c]=++tot;
			p=ch[p][c];
			cnt[p]++;
		}
	}
	void Remove(int x){
		int p=0;
		for (i=29;i>=0;i--){
			int c=((x>>i)&1);
			int pre=p;
			p=ch[p][c];
			if (--cnt[p]==0) ch[pre][c]=0;
		}
	}
	int Find(int x){
		int p=0,val=0;
		for (i=29;i>=0;i--){
			int c=((x>>i)&1);
			if (ch[p][c]) p=ch[p][c];
			else{
				p=ch[p][c^1];
				val+=(1<<i);
			}
		}
		Remove(val^x);
		return val;
	}
}T;
int main(){
	read(n);
	for (i=1;i<=n;i++) read(a[i]);
	for (i=1;i<=n;i++){
		read(x);
		T.Insert(x);
	}
	for (i=1;i<=n;i++){
		printf("%d%c",T.Find(a[i]),i==n?'\n':' ');
	}
	return 0;
}