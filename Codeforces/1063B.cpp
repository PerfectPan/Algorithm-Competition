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
const int N=2000+10;
struct P{
	int x,y,L,R;
	bool operator<(const P&rhs)const{
		return L+R<=rhs.L+rhs.R;
	}
};
int n,m,i,j,r,c,x,y,ans;
bool vis[N][N];
char s[N][N];
priority_queue<P>Q;
bool check(int x,int y){
	return x>=1 && x<=n && y>=1 && y<=m; 
}
int main(){
	read(n),read(m);
	read(r),read(c),read(x),read(y);
	for (i=1;i<=n;++i) scanf("%s",s[i]+1);
	vis[r][c]=1;
	Q.push((P){r,c,x,y});
	while (!Q.empty()){
		auto cur=Q.top();Q.pop();

		int tx=cur.x+1,ty=cur.y;
		if (check(tx,ty) && s[tx][ty]!='*' && !vis[tx][ty]){
			vis[tx][ty]=1;
			Q.push((P){tx,ty,cur.L,cur.R});
		}

		tx=cur.x-1,ty=cur.y;
		if (check(tx,ty) && s[tx][ty]!='*' && !vis[tx][ty]){
			vis[tx][ty]=1;
			Q.push((P){tx,ty,cur.L,cur.R});
		}

		if (cur.R){
			tx=cur.x,ty=cur.y+1;
			if (check(tx,ty) && s[tx][ty]!='*' && !vis[tx][ty]){
				vis[tx][ty]=1;
				Q.push((P){tx,ty,cur.L,cur.R-1});
			}
		}

		if (cur.L){
			tx=cur.x,ty=cur.y-1;
			if (check(tx,ty) && s[tx][ty]!='*' && !vis[tx][ty]){
				vis[tx][ty]=1;
				Q.push((P){tx,ty,cur.L-1,cur.R});
			}
		}
	}
	for(i=1;i<=n;++i)for(j=1;j<=m;++j)ans+=vis[i][j];
	printf("%d\n",ans);
	return 0;
}