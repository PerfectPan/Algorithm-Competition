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
const int N=100000+10;
int n,i,j,cnt[26];
char s[N];
int main(){
	read(n);
	scanf("%s",s);
	for (i=0;s[i];++i) cnt[s[i]-'a']++;
	for (i=0;i<26;++i)if(cnt[i]){
		for (j=1;j<=cnt[i];++j) putchar('a'+i);
	}
	puts("");
	return 0;
}