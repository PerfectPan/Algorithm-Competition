#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=100000+10;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
int n,m,Q,i,l1,r1,l2,r2,cnt,sum1[N],sum2[N],a1[N],a2[N];
char s[N],t[N],ans[N];
int main(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	for (i=1;i<=n;i++){
		sum1[i]=sum1[i-1]+(s[i]!='A');
		if (s[i]=='A') a1[i]=a1[i-1]+1;
		else a1[i]=0;
	}
	for (i=1;i<=m;i++){
		sum2[i]=sum2[i-1]+(t[i]!='A');
		if (t[i]=='A') a2[i]=a2[i-1]+1;
		else a2[i]=0;
	}
	for (read(Q);Q--;cnt++){
		read(l1),read(r1),read(l2),read(r2);
		int suffa1=min(a1[r1],r1-l1+1),suffa2=min(a2[r2],r2-l2+1);
		int cntb1=sum1[r1]-sum1[l1-1],cntb2=sum2[r2]-sum2[l2-1];
		if (cntb1>cntb2) ans[cnt]='0';
		else if (cntb1==cntb2){
			if (suffa1>=suffa2&&(suffa1-suffa2)%3==0) ans[cnt]='1';
			else ans[cnt]='0';
		}
		else{
			if ((cntb2-cntb1)&1) ans[cnt]='0';
			else if (suffa2>suffa1) ans[cnt]='0';
			else if (suffa2==suffa1&&!cntb1) ans[cnt]='0';
			else ans[cnt]='1';
		}
	}
	puts(ans);
	return 0;
}