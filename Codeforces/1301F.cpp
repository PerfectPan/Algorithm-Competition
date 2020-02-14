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
const int M=40+10;
int n,m,k,q,r1,c1,r2,c2,i,j,a[N][N],dis[M][N][N];
int dir_x[4]={1,0,-1,0};
int dir_y[4]={0,1,0,-1};
vector<pair<int,int> >G[M];
bool vis[N][N],vis2[M];
void bfs(int col){
    queue<pair<int,int> >Q;
    int i,j;
    memset(vis2,0,sizeof(vis2));
    for (i=1;i<=n;++i){
        for (j=1;j<=m;++j){
            vis[i][j]=0;
            dis[col][i][j]=-1;
            if (a[i][j]==col){
                dis[col][i][j]=0;
                Q.push(MP(i,j));
            }
        }
    }
    vis2[col]=1;
    while (!Q.empty()){
        pair<int,int> x=Q.front();Q.pop();
        if (vis[x.first][x.second]) continue;
        vis[x.first][x.second]=1;
        if (!vis2[a[x.first][x.second]]){
            for (i=0;i<(int)G[a[x.first][x.second]].size();++i){
                int xx=G[a[x.first][x.second]][i].first;
                int yy=G[a[x.first][x.second]][i].second;
                if (~dis[col][xx][yy]) continue;
                dis[col][xx][yy]=dis[col][x.first][x.second]+1;
                Q.push(MP(xx,yy));
            }
            vis2[a[x.first][x.second]]=1;
        }
        for (i=0;i<4;++i){
            int tx=x.first+dir_x[i];
            int ty=x.second+dir_y[i];
            if (tx<1 || tx>n || ty<1 || ty>m || ~dis[col][tx][ty]) continue;
            dis[col][tx][ty]=dis[col][x.first][x.second]+1;
            Q.push(MP(tx,ty));
        }
    }
}
int main(){
    read(n),read(m),read(k);
    for (i=1;i<=n;++i){
        for (j=1;j<=m;++j){
            read(a[i][j]);
            G[a[i][j]].push_back(MP(i,j));
        }
    }
    for (i=1;i<=k;++i) bfs(i);
    for (read(q);q--;){
        read(r1),read(c1),read(r2),read(c2);
        int ans=abs(r1-r2)+abs(c1-c2);
        for (i=1;i<=k;++i) ans=min(ans,1+dis[i][r1][c1]+dis[i][r2][c2]);
        printf("%d\n",ans);
    }
    return 0;
}