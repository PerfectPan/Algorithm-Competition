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
const int N=100+10;
const int M=50+10;
int n,m,i,j,pos=-1;
char s[N][M];
bool vis[N];
vector<pair<int,int> >vec;
bool ok(int x){
    int i,j;
    for (i=1,j=m;i<j;++i,--j){
        if (s[x][i]!=s[x][j]) return 0;
    }
    return 1;
}
bool check(int x,int y){
    int i,j;
    for (i=1,j=m;i<=m;++i,--j){
        if (s[x][i]!=s[y][j]) return 0;
    }
    return 1;
}
int main(){
    read(n),read(m);
    for (i=1;i<=n;++i) scanf("%s",s[i]+1);
    for (i=1;i<=n;++i)if(!vis[i]){
        bool flag=0;
        for (j=i+1;j<=n;++j)if(!vis[j]){
            if (check(i,j)){
                vec.push_back(MP(i,j));
                flag=1;
                vis[i]=vis[j]=1;
            }
        }
        if (!flag && ok(i)){
            pos=i;
            vis[i]=1;
        }
    }
    int len=(int)vec.size()*2*m;
    if (pos!=-1) len+=m;
    printf("%d\n",len);
    for (i=0;i<(int)vec.size();++i){
        printf("%s",s[vec[i].first]+1);
    }
    if (pos!=-1) printf("%s",s[pos]+1);
    for (i=(int)vec.size()-1;i>=0;--i){
        printf("%s",s[vec[i].second]+1);
    }
    puts("");
    return 0;
}