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
const int N=65000+10;
int n,i;
char s[N];
ll ans;
int main(){
	read(n);
	scanf("%s",s+1);
	int len=strlen(s+1);
	for (i=1;i<=n;++i){
		int num=s[i]-'0';
		if (num&1);
		else ans+=i;
	}
	printf("%lld\n",ans);
	return 0;
}