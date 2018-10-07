#include <bits/stdc++.h>
#define MP make_pair
#define PB emplace_back
using namespace std;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
int n,i;
char s[10005];
int main(){
	read(n);
	scanf("%s",s);
	int num=0;
	for (i=0;i<n;++i){
		num+=s[i]=='8';
	}
	int ans=0;
	for (;;){
		if (num>0){
			if (n-11>=0){
				n-=11;
				num--;
				ans++;
			}
			else break;
		}
		else break;
	}
	printf("%d\n",ans);
	return 0;
}