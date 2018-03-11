#pragma comment(linker, "/STACK:102400000,102400000")
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define lson root<<1,l,mid
#define rson root<<1|1,mid+1,r
#define Key_Value ch[ch[root][1]][0]
#define DBN1(a)           cerr<<#a<<"="<<(a)<<"\n"
#define DBN2(a,b)         cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"
#define DBN3(a,b,c)       cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define DBN4(a,b,c,d)     cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
#define DBN5(a,b,c,d,e)   cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<"\n"
#define DBN6(a,b,c,d,e,f) cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<", "<<#f<<"="<<(f)<<"\n"
#define clr(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define mp make_pair
#define ALL(x) x.begin(),x.end()
#define F first
#define S second
using namespace std;
typedef long long ll;
const int maxn=500000+5;
const int INF=0x3f3f3f3f;
const int P=1000000007;
const double PI=acos(-1.0);
template<typename T>
inline T read(T&x){
    x=0;int _f=0;char ch=getchar();
    while(ch<'0'||ch>'9')_f|=(ch=='-'),ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x=_f?-x:x;
}
const int N=(int)1e6+10;
int i,j,tot,Prime[N];
bool isPrime[N];
void init(){
	int i,j;
	for (i=2;i<=N-10;i++){
		if (!isPrime[i]){
			Prime[++Prime[0]]=i;
			if (!tot&&i>1000) tot=Prime[0]-1;
		}
		for (j=1;i*Prime[j]<=N-10 && j<=Prime[0];j++){
            isPrime[i*Prime[j]]=true;
            if (i%Prime[j]==0) break;
        }
	}
}
int get(int x){
	if (i==1) return 1;
	for (int i=1;i<=tot;i++){
		if (x%Prime[i]==0){
			while (x%Prime[i]==0){
				x/=Prime[i];
			}
			if (x==1){
				return Prime[i];
			}
		}
	}
	return x;
}
int main(){
	init();
	int x;
	read(x);
	int tmp=x,tmp2=x,y;
	for (i=1;i<=tot;i++){
		if (x%Prime[i]==0){
			while (x%Prime[i]==0){
				x/=Prime[i];
			}
			if (x==1){
				y=Prime[i];
				break;
			}
		}
	}
	if (x!=1) y=x;
	x=tmp-y+1;
	tmp=x;
	int ans=0;
	for (i=x;i<=tmp2;i++){
		int res,ttt;
		if (!isPrime[i]) ttt=i;
		else res=get(i),ttt=i-res+1;
		if (ttt<3) continue;
		if (ans==0) ans=ttt;
		else ans=min(ans,ttt);
	}
	cout<<ans<<endl;
	return 0;
}