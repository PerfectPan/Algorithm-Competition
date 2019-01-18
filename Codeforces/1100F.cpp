#include <bits/stdc++.h>
#define PB emplace_back
using namespace std;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=5e5+10;
const int LL=21;
int n,q,i,ans[N],c[N],L[N],R[N],tmp[LL+1],f[N][LL+1],g[N][LL+1];
vector<int>v;
int work(int* f,int* g){
	int i,j,ret=0;
	for (i=0;i<=LL;++i) tmp[i]=f[i];
	for (i=0;i<=LL;++i){
		int t=g[i];
		for (j=LL;j>=0;--j){
			if (!(t&(1LL<<j))) continue;
        	if (!tmp[j]){
            	tmp[j]=t;
            	break;
            }
            t^=tmp[j];
		}
	}
	for (i=LL;i>=0;--i){
		if ((ret^tmp[i])>ret) ret^=tmp[i];
	}
	return ret;
}	
void solve(int l,int r,vector<int> v){
	if (l>r || v.size()==0) return;
	int i,j,mid=l+((r-l)>>1);
	if (l+1>=r){
		for (i=0;i<(int)v.size();++i){
			if (L[v[i]]==R[v[i]]) ans[v[i]]=c[L[v[i]]];
			else{
				ans[v[i]]=max(c[L[v[i]]],c[R[v[i]]]);
				ans[v[i]]=max(ans[v[i]],c[L[v[i]]]^c[R[v[i]]]);
			}
		}
		return;
	}
	for(i=l;i<=mid+1;++i)for(j=0;j<=LL;++j)f[i][j]=0;
	for (i=mid;i>=l;--i){
		for (j=0;j<=LL;++j) f[i][j]=f[i+1][j];
		int t=c[i];
		for (j=LL;j>=0;--j){
			if (!(t&(1LL<<j))) continue;
        	if (!f[i][j]){
            	f[i][j]=t;
            	break;
            }
            t^=f[i][j];
		}
	}

	for (i=mid;i<=r;++i)for(j=0;j<=LL;++j)g[i][j]=0;
	for (i=mid+1;i<=r;++i){
		for (j=0;j<=LL;++j) g[i][j]=g[i-1][j];
		int t=c[i];
		for (j=LL;j>=0;--j){
			if (!(t&(1LL<<j))) continue;
        	if (!g[i][j]){
            	g[i][j]=t;
            	break;
            }
            t^=g[i][j];
		}
	}
	vector<int>vl,vr;
	for (i=0;i<(int)v.size();++i){
		if (L[v[i]]>mid) vr.PB(v[i]);
		else if (R[v[i]]<mid) vl.PB(v[i]);
		else{
			ans[v[i]]=work(f[L[v[i]]],g[R[v[i]]]);
		}
	}
	solve(l,mid-1,vl);
	solve(mid+1,r,vr);
}
int main(){
	for (read(n),i=1;i<=n;++i) read(c[i]);
	for (read(q),i=1;i<=q;++i){
		read(L[i]),read(R[i]);
		v.PB(i);
	}
	solve(1,n,v);
	for (i=1;i<=q;++i) printf("%d\n",ans[i]);
	return 0;
}