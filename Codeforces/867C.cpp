#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=1e5+10;
struct Node{
	ll val,num;
	bool operator<(const Node&rhs)const{
		return val<rhs.val;
	}
}t[N];
int n,i;
ll t1,t2,ans,sum,s,mn,S[N],A[N],B[N];
int main(){
	read(n),read(s);
	for (i=1;i<=n;i++){
		read(S[i]),read(A[i]),read(B[i]);
		if (A[i]>=B[i]) t1+=S[i];
		if (A[i]<B[i]) t2+=S[i];
		ans+=max(A[i],B[i])*S[i];
		t[i].val=A[i]-B[i];
		t[i].num=S[i];
	}
	if ((t1%s==0&&t2%s==0)||(t1%s+t2%s>s)) printf("%lld\n",ans);
	else{
		t1%=s,t2%=s;
		ll gainA=0,gainB=0;
		sort(t+1,t+1+n);
		for (i=1;i<=n;i++)if(t[i].val>=0){
			if (t1>=t[i].num){
				gainA+=t[i].val*t[i].num;
				t1-=t[i].num;
			}
			else{
				gainA+=t[i].val*t1;
				t1=0;
				break;
			}
		}
		for (i=n;i>=1;i--)if(t[i].val<0){
			if (t2>=t[i].num){
				gainB+=(-t[i].val)*t[i].num;
				t2-=t[i].num;
			}
			else{
				gainB+=(-t[i].val)*t2;
				t2=0;
				break;
			}
		}
		printf("%lld\n",ans-min(gainA,gainB));
	}
	return 0;
}