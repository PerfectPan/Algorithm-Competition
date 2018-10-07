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
const int N=100;
int T,i,j,n,m,cas=1,num[N][N];
int main(){
	for (read(T);T--;){
		read(n),read(m);
		for (i=1;i<=n;++i){
			for (j=1;j<=m;++j){
				read(num[i][j]);
			}
		}
		printf("Case #%d: ",cas++);
		bool flag=0;
		for (i=1;i<=n;++i){
			for (j=i+1;j<=n;++j){
				if (num[i][1]==num[j][1] || num[i][m]==num[j][m]){
					flag=1;
					break;
				}
			}
		}
		for (i=1;i<=m;++i){
			for (j=i+1;j<=m;++j){
				if (num[1][i]==num[1][j] || num[n][i]==num[n][j]){
					flag=1;
					break;
				}
			}
		}
		for (i=1;i<=n;++i){
			for (j=1;j<m;++j){
				if (num[i][j]==num[i][j+1]){
					flag=1;
					break;
				}
			}
		}
		for (i=1;i<=m;++i){
			for (j=1;j<n;++j){
				if (num[j][i]==num[j+1][i]){
					flag=1;
					break;
				}
			}
		}
		puts(flag?"Yes":"No");
	}
	return 0;
}