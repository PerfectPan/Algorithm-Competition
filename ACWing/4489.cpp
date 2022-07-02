#include<cstdio>
#include<cstring>
#include<algorithm>
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
const int N = 2e5 + 10;
int n, a[N], dp[N], mx[N << 2];
#define lson root<<1,l,mid
#define rson root<<1|1,mid+1,r
void pushup(int root){
  mx[root]=max(mx[root<<1],mx[root<<1|1]);
}
void build(int root,int l,int r){
  if (l==r){
    mx[root] = 0;
    return;
  }
  int mid=l+((r-l)>>1);
  build(lson);
  build(rson);
  pushup(root);
}
void update(int root,int l,int r,int x,int v){
  if (l==r){
    mx[root]=v;
    return;
  }
  int mid=l+((r-l)>>1);
  if (x<=mid) update(lson,x,v);
  else update(rson,x,v);
  pushup(root);
}
int query(int root,int l,int r,int L,int R){
  if (L<=l&&r<=R){
    return mx[root];
  }
  int mid=l+((r-l)>>1);
  int lm = 0, rm = 0;
  if (L<=mid) lm = query(lson,L,R);
  if (mid<R) rm = query(rson,L,R);
  return max(lm, rm);
}
int main() {
  read(n);
  for (int i = 1; i <= n; ++i) {
    read(a[i]);
    int num = a[i] / 2 + (a[i] & 1 ? 1 : 0);
    int L = 1, R = i - 1, res = -1;
    while (L <= R) {
      int mid = L + ((R - L) >> 1);
      if (a[mid] >= num) {
        res = mid;
        R = mid - 1;
      } else L = mid + 1;
    }
    // cout << i << " " << a[i] << " " << res << endl;
    if (~res) {
      // cout << a[res] <<endl;
      dp[i] = query(1,1,n,res,i-1) + 1;
    } else {
      dp[i] = 1;
    }
    update(1,1,n,i,dp[i]);
  }
  printf("%d\n",*max_element(dp+1,dp+1+n));
  return 0;
}

