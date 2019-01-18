#include<bits/stdc++.h>
#define MP make_pair
#define PB emplace_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0'&& ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N=1e5+10;
int n,m,c,i,j,a[N],cnt[N];
char ch[N];
int main(){
	read(n),read(m);
	for (i=1;i<=m;++i){
		read(a[i]);
		ch[i]='0';
		cnt[a[i]]++;
		if (cnt[a[i]]==1) c++;
		if (c==n){
			ch[i]='1';
			for (j=1;j<=n;++j){
				cnt[j]--;
				if (cnt[j]==0) c--;
			}
		}
	}
	ch[m+1]='\0';
	puts(ch+1);
	return 0;
}