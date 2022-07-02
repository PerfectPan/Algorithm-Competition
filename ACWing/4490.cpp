#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
  x=0;int f=0;char ch=getchar();
  while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
  while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
  return x=f?-x:x;
}
const int N = 1e4 + 10;
vector<int> G[N];
int n,i,p,cnt,c[N],cur[N];
void dfs(int id,int col) {
  for (int j = 0 ; j < G[id].size(); ++j) {
    int son = G[id][j];
    if (c[son] != col) {
      cnt++;
    }
    dfs(son,c[son]);
  }
}
int main () {
  read(n);
  for (i=2;i<=n;++i){
    read(p);
    G[p].PB(i);
  }
  for (i=1;i<=n;++i){
    read(c[i]);
  }
  dfs(1,c[1]);
  printf("%d\n",cnt+1);
  return 0;
}

