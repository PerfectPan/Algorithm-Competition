#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
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
int n,q,i,j,k,x,A,B,C,nxt[N][26];
int f[300][300][300];
char op[2],y[2],a[300],b[300],c[300],s[N];
int main(){
	read(n),read(q);
	scanf("%s",s+1);
	for (j=0;j<26;++j) nxt[n][j]=n+1;
	for (i=n;i;--i){
		for (j=0;j<26;++j) nxt[i-1][j]=nxt[i][j];
		nxt[i-1][s[i]-'a']=i;
	}
	f[0][0][0]=0;
	for (;q--;){
		scanf("%s%d",op,&x);
		if (op[0]=='+'){
			scanf("%s",y);
			if (x==1){
				a[++A]=y[0];
				for (j=0;j<=B;++j){
					for (k=0;k<=C;++k){
						f[A][j][k]=n+1;
						if (A && f[A-1][j][k]<=n) f[A][j][k]=min(f[A][j][k],nxt[f[A-1][j][k]][a[A]-'a']);
						if (j && f[A][j-1][k]<=n) f[A][j][k]=min(f[A][j][k],nxt[f[A][j-1][k]][b[j]-'a']);
						if (k && f[A][j][k-1]<=n) f[A][j][k]=min(f[A][j][k],nxt[f[A][j][k-1]][c[k]-'a']);
					}
				}
			}
			if (x==2){
				b[++B]=y[0];
				for (j=0;j<=A;++j){
					for (k=0;k<=C;++k){
						f[j][B][k]=n+1;
						if (B && f[j][B-1][k]<=n) f[j][B][k]=min(f[j][B][k],nxt[f[j][B-1][k]][b[B]-'a']);
						if (j && f[j-1][B][k]<=n) f[j][B][k]=min(f[j][B][k],nxt[f[j-1][B][k]][a[j]-'a']);
						if (k && f[j][B][k-1]<=n) f[j][B][k]=min(f[j][B][k],nxt[f[j][B][k-1]][c[k]-'a']);
					}
				}
			}
			if (x==3){
				c[++C]=y[0];
				for (j=0;j<=A;++j){
					for (k=0;k<=B;++k){
						f[j][k][C]=n+1;
						if (C && f[j][k][C-1]<=n) f[j][k][C]=min(f[j][k][C],nxt[f[j][k][C-1]][c[C]-'a']);
						if (j && f[j-1][k][C]<=n) f[j][k][C]=min(f[j][k][C],nxt[f[j-1][k][C]][a[j]-'a']);
						if (k && f[j][k-1][C]<=n) f[j][k][C]=min(f[j][k][C],nxt[f[j][k-1][C]][b[k]-'a']);
					}
				}
			}
		}
		else{
			if (x==1) A--;
			if (x==2) B--;
			if (x==3) C--;
		}
		puts(f[A][B][C]<=n?"YES":"NO");
	}
	return 0;
}