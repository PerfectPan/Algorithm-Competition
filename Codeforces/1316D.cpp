#include<bits/stdc++.h>
#define MP make_pair
#define PB emplace_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N=1000+10;
int n,i,j,k,cnt,x[N][N],y[N][N],id[N][N];
pair<int,int> tt[N*N];
int dir_x[4]={0,0,1,-1};
int dir_y[4]={1,-1,0,0};
bool vis[N][N],flag;
vector<int>G[N*N];
char ch[4]={'R','L','D','U'};
char ans[N][N];
void dfs(int x,int y){
	vis[x][y]=1;
	for (int i=0;i<(int)G[id[x][y]].size();++i){
		int v=G[id[x][y]][i];
		int xx=tt[v].first,yy=tt[v].second;
		if (vis[xx][yy]) continue;
		int k;
        for (k=0;k<4;++k){
            if (x+dir_x[k]==xx && y+dir_y[k]==yy) break;
        }
        if (!flag){
            ans[x][y]=ch[k];
            flag=1;
        }
        ans[xx][yy]=ch[k^1];
		dfs(xx,yy);
	}
}
int main(){
	read(n);
	for (i=1;i<=n;++i){
		for (j=1;j<=n;++j){
			read(x[i][j]),read(y[i][j]);
			id[i][j]=++cnt;
			tt[cnt]=MP(i,j);
		}
	}
	for (i=1;i<=n;++i){
		for (j=1;j<=n;++j){
			for (k=0;k<4;++k){
				int tx=i+dir_x[k];
				int ty=j+dir_y[k];
				if (tx<1 || tx>n || ty<1 || ty>n) continue;
				if (x[i][j]==x[tx][ty] && y[i][j]==y[tx][ty]){
					G[id[i][j]].push_back(id[tx][ty]);
					G[id[tx][ty]].push_back(id[i][j]);
				}
			}
		}
	}
	for (i=1;i<=n;++i){
		for (j=1;j<=n;++j)if(!vis[i][j]){
			if (x[i][j]==-1 && y[i][j]==-1){
				flag=0;
				dfs(i,j);
				if (!flag) return puts("INVALID"),0;
			}
			else{
                flag=1;
                ans[x[i][j]][y[i][j]]='X';
                dfs(x[i][j],y[i][j]);
			}
		}
	}
    for(i=1;i<=n;++i)for(j=1;j<=n;++j)if(!vis[i][j]) return puts("INVALID"),0;
    puts("VALID");
    for (i=1;i<=n;++i){
        for (j=1;j<=n;++j) putchar(ans[i][j]);
        puts("");
    }
    return 0;
}
