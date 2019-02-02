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
const int N=500+10;
int n,i,j,ans;
char s[N][N];
bool check(int x,int y){
	if (s[x][y]=='X' && s[x][y+2]=='X' && s[x+1][y+1]=='X'
		&& s[x+2][y]=='X' && s[x+2][y+2]=='X') return 1;
	return 0;
}
int main(){
	read(n);
	for (i=1;i<=n;++i) scanf("%s",s[i]+1);
	for (i=1;i+2<=n;++i){
		for (j=1;j+2<=n;++j){
			if (check(i,j)) ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}