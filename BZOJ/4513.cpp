#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
int T,i,a,b,c,x,y,p,f[62][2][2][2],g[62][2][2][2];
ll n,m,k,table[62];
void up(int&a,int b){a+=b;if(a>=p)a-=p;}
int main(){
	for (read(T);T--;){
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		read(n),read(m),read(k),read(p);
		for (table[0]=i=1;i<62;i++) table[i]=(table[i-1]<<1)%p;
		f[61][1][1][1]=1;
		for (i=60;i>=0;i--) for (a=0;a<2;a++) for (b=0;b<2;b++) for (c=0;c<2;c++) if (f[i+1][a][b][c]){
			int pn=(n>>i)&1,pm=(m>>i)&1,pk=(k>>i)&1;
			for (x=0;x<=(a?pn:1);x++) for (y=0;y<=(b?pm:1);y++){
				int d=x^y;
				if (c && d<pk) continue;
				up(f[i][a && x==pn][b && y==pm][c && d==pk],f[i+1][a][b][c]);
				up(g[i][a && x==pn][b && y==pm][c && d==pk],g[i+1][a][b][c]);
				if (d) up(g[i][a && x==pn][b && y==pm][c && d==pk],table[i]*f[i+1][a][b][c]%p);
			}
		}
		int res=0;k%=p;
		up(res,((g[0][0][0][0]-k*f[0][0][0][0]%p)%p+p)%p);
		printf("%d\n",res);
	}
	return 0;
}