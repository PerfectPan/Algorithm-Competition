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
const int N=1e5+10;
int n,k,A,B,i,a[N];
ll Ans;
ll dfs(int l,int r,int L,int R){
	if (l==r) return 1LL*B*(R-L+1);
	ll aans=1LL*B*(R-L+1)*(r-l+1);
	int mid=l+((r-l)>>1);
	int LL=L,RR=R,ans=LL-1;
	while (LL<=RR){
		int MID=LL+((RR-LL)>>1);
		if (a[MID]<=mid){
			LL=MID+1;
			ans=MID;
		}
		else RR=MID-1;
	}
	int leftnum=ans-L+1;
	int rightnum=R-ans;

	if (leftnum>0 && rightnum>0){
		ll LLLL,RRRR;	
		LLLL=dfs(l,mid,L,ans);
		RRRR=dfs(mid+1,r,ans+1,R);
		aans=min(aans,LLLL+RRRR);
	}
	else{
		if (!leftnum){
			aans=min(aans,A+dfs(mid+1,r,ans+1,R));
		}
		else if (!rightnum){
			aans=min(aans,A+dfs(l,mid,L,ans));
		}
	}
	return aans;
}
int main(){
	read(n),read(k),read(A),read(B);
	for (i=1;i<=k;++i) read(a[i]); 
	sort(a+1,a+1+k);
	printf("%lld\n",dfs(1,1<<n,1,k));
	return 0;
}