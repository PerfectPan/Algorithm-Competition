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
const int N=1000+10;
int n,m,i,j;
char s[N][N];
bool vis[N][N];
void work(int x,int y){
	if (x+3-1<=n && y+3-1<=m){
		if (s[x][y]=='#' && s[x+1][y]=='#' && s[x+2][y]=='#' 
			&& s[x][y+1]=='#' && s[x+2][y+1]=='#'
			&& s[x][y+2]=='#' && s[x+1][y+2]=='#' && s[x+2][y+2]=='#'){
			vis[x][y]=vis[x+1][y]=vis[x+2][y]=1;
			vis[x][y+1]=vis[x+2][y+1]=1;
			vis[x][y+2]=vis[x+1][y+2]=vis[x+2][y+2]=1;
		}
	}
}
int main(){
	read(n),read(m);
	for (i=1;i<=n;++i) scanf("%s",s[i]+1);
	for (i=1;i<=n;++i){
		for (j=1;j<=m;++j){
			if (s[i][j]=='#') work(i,j);
		}
	}
	for (i=1;i<=n;++i){
		for (j=1;j<=m;++j){
			if (s[i][j]=='#' && !vis[i][j]) return puts("NO"),0;
		}
	}
	puts("YES");
	return 0;
}