#include <bits/stdc++.h>
using namespace std;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=5e5+10;
const int L=31;
struct LinearBasis{
    int a[L+1];
    LinearBasis(){
        fill(a,a+L+1,0);
    }
    void insert(int t){
        for (int j=L;j>=0;j--){
            if (!t) return;
            if (!(t&(1LL<<j))) continue;
            if (a[j]) t^=a[j];
            else{
                a[j]=t;
                return;
            }
        }
    }
    void merge(const LinearBasis& rhs){
        for (int i=0;i<=L;i++) insert(rhs.a[i]);
    }
	void print(){
		for (int i=0;i<=L;i++){
			printf("%d%c",a[i],i==L?'\n':' ');
		}
	}
    int querymax(){
        int ret=0;
        for (int i=L;i>=0;i--){
            if ((ret^a[i])>ret) ret^=a[i];
        }
        return ret;
    }
}P;
int n,i,x,ans[N];
vector<int>p[N<<2];
map<int,int>vis,loc;
#define lson root<<1,l,mid
#define rson root<<1|1,mid+1,r
void update(int root,int l,int r,int L,int R,int x){
	if (L<=l&&r<=R){
		p[root].push_back(x);
		return;
	}
	int mid=l+((r-l)>>1);
	if (L<=mid) update(lson,L,R,x);
	if (mid<R) update(rson,L,R,x);
}
void query(int root,int l,int r,LinearBasis base){
	for (int i=0;i<(int)p[root].size();i++){
		int num=p[root][i];
		base.insert(num);
	}
	if (l==r){
		// printf("***%d\n",l);
		// base.print();
		ans[l]=base.querymax();
		return;
	}
	int mid=l+((r-l)>>1);
	query(lson,base);
	query(rson,base);
}
int main(){
	read(n);
	for (i=1;i<=n;i++){
		read(x);
		if (x>0){
			if (!vis[x]) loc[x]=i;
			vis[x]++;
		}
		else{
			if (!(--vis[-x])){
				update(1,1,n,loc[-x],i-1,-x);
			}
		}
	}
	for (map<int,int>::iterator it=vis.begin();it!=vis.end();++it){
		int num=(*it).first,cnt=(*it).second;
		if (cnt==0) continue;
		update(1,1,n,loc[num],n,num);
	}
	query(1,1,n,P);
	for (i=1;i<=n;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}