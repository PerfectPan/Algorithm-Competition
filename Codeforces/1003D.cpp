#include <bits/stdc++.h>
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
const int N=5000+10;
int n,q,i,j;
ll b,x;
int cnt[64],a[64],cnt2[64];
int main(){
	read(n),read(q);
	for (i=1;i<=n;i++){
		read(x);
		int tot=0;
		while ((1LL<<tot)!=x) tot++;
		cnt[tot]++;
	}
	for (i=1;i<=q;i++){
		read(b);
		for (j=0;j<=30;j++) a[j]=cnt[j],cnt2[j]=0;
		int num=0;
		for (j=30;j>=0;j--){
			if ((1LL<<j)&b) cnt2[j]++;
			if (a[j]>=cnt2[j]){
				num+=cnt2[j];
				cnt2[j]=0;
			}
			else{
				int tmp=cnt2[j]-a[j];
				num+=a[j];
				cnt2[j]=0;
				if (j==0){
					num=-1;
					break;
				}
				else{
					cnt2[j-1]+=tmp*2;
				}
			}
		}
		printf("%d\n",num);
	}
	return 0;
}