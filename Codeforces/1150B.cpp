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
const int N=50+10;
int n,i,j;
char s[N][N];
int main(){
	read(n);
	for (i=1;i<=n;++i) scanf("%s",s[i]+1);
	for (i=2;i<n;++i){
		for (j=2;j<n;++j)if(s[i][j]=='.'){
			if (s[i-1][j]=='.' && s[i+1][j]=='.' && s[i][j-1]=='.' && s[i][j+1]=='.'){
				s[i][j]=s[i-1][j]=s[i+1][j]=s[i][j-1]=s[i][j+1]='#';
			}
		}
	}
	for (i=1;i<=n;++i){
		for (j=1;j<=n;++j){
			if (s[i][j]=='.') return puts("NO"),0;
		}
	}
	puts("YES");
	return 0;
}