#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=100+10;
int n,i,sum;
char s[N];
bool check(int x){
	int num=0,cnt=0;
	for (int i=1;i<=n;++i){
		num+=s[i]-'0';
		if (num==x) num=0,cnt++;
		else if (num>x) return 0;
	}
	return cnt>=2;
}
int main(){
	read(n);
	scanf("%s",s+1);
	for (i=1;i<=n;++i){
		sum+=s[i]-'0';
	}
	if (sum==0) return puts("YES"),0;
	for (i=1;i*i<=sum;++i){
		if (sum%i==0){
			if (check(i) || (i>1 && check(sum/i))) return puts("YES"),0;
		}
	}
	puts("NO");
	return 0;
}