#include<bits/stdc++.h>
#define MP make_pair
#define PB emplace_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0'&& ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N=6000+10;
int n,ans;
char s[N];
int sum[6000][6000];
bool work(int x){
	for (int i=1;i<=n;i+=x){
		for (int j=1;j<=n;j+=x){
			int tot=sum[i+x-1][j+x-1]-sum[i-1][j+x-1]-sum[i+x-1][j-1]+sum[i-1][j-1];
			if (tot==0 || tot==x*x);
			else return 0;
		}
	}
	return 1;
}
int main(){
	read(n);
	for (int i=1;i<=n;++i){
		scanf("%s",s+1);
		for (int j=1;j<=n/4;++j){
			if (s[j]=='0'){
				sum[i][4*(j-1)+1]=0;
				sum[i][4*(j-1)+2]=0;
				sum[i][4*(j-1)+3]=0;
				sum[i][4*(j-1)+4]=0;
			}
			else if (s[j]=='1'){
				sum[i][4*(j-1)+1]=0;
				sum[i][4*(j-1)+2]=0;
				sum[i][4*(j-1)+3]=0;
				sum[i][4*(j-1)+4]=1;
			}
			else if (s[j]=='2'){
				sum[i][4*(j-1)+1]=0;
				sum[i][4*(j-1)+2]=0;
				sum[i][4*(j-1)+3]=1;
				sum[i][4*(j-1)+4]=0;
			}
			else if (s[j]=='3'){
				sum[i][4*(j-1)+1]=0;
				sum[i][4*(j-1)+2]=0;
				sum[i][4*(j-1)+3]=1;
				sum[i][4*(j-1)+4]=1;
			}
			else if (s[j]=='4'){
				sum[i][4*(j-1)+1]=0;
				sum[i][4*(j-1)+2]=1;
				sum[i][4*(j-1)+3]=0;
				sum[i][4*(j-1)+4]=0;
			}
			else if (s[j]=='5'){
				sum[i][4*(j-1)+1]=0;
				sum[i][4*(j-1)+2]=1;
				sum[i][4*(j-1)+3]=0;
				sum[i][4*(j-1)+4]=1;
			}
			else if (s[j]=='6'){
				sum[i][4*(j-1)+1]=0;
				sum[i][4*(j-1)+2]=1;
				sum[i][4*(j-1)+3]=1;
				sum[i][4*(j-1)+4]=0;
			}
			else if (s[j]=='7'){
				sum[i][4*(j-1)+1]=0;
				sum[i][4*(j-1)+2]=1;
				sum[i][4*(j-1)+3]=1;
				sum[i][4*(j-1)+4]=1;
			}
			else if (s[j]=='8'){
				sum[i][4*(j-1)+1]=1;
				sum[i][4*(j-1)+2]=0;
				sum[i][4*(j-1)+3]=0;
				sum[i][4*(j-1)+4]=0;
			}
			else if (s[j]=='9'){
				sum[i][4*(j-1)+1]=1;
				sum[i][4*(j-1)+2]=0;
				sum[i][4*(j-1)+3]=0;
				sum[i][4*(j-1)+4]=1;
			}
			else if (s[j]=='A'){
				sum[i][4*(j-1)+1]=1;
				sum[i][4*(j-1)+2]=0;
				sum[i][4*(j-1)+3]=1;
				sum[i][4*(j-1)+4]=0;
			}
			else if (s[j]=='B'){
				sum[i][4*(j-1)+1]=1;
				sum[i][4*(j-1)+2]=0;
				sum[i][4*(j-1)+3]=1;
				sum[i][4*(j-1)+4]=1;
			}
			else if (s[j]=='C'){
				sum[i][4*(j-1)+1]=1;
				sum[i][4*(j-1)+2]=1;
				sum[i][4*(j-1)+3]=0;
				sum[i][4*(j-1)+4]=0;
			}
			else if (s[j]=='D'){
				sum[i][4*(j-1)+1]=1;
				sum[i][4*(j-1)+2]=1;
				sum[i][4*(j-1)+3]=0;
				sum[i][4*(j-1)+4]=1;
			}
			else if (s[j]=='E'){
				sum[i][4*(j-1)+1]=1;
				sum[i][4*(j-1)+2]=1;
				sum[i][4*(j-1)+3]=1;
				sum[i][4*(j-1)+4]=0;
			}
			else if (s[j]=='F'){
				sum[i][4*(j-1)+1]=1;
				sum[i][4*(j-1)+2]=1;
				sum[i][4*(j-1)+3]=1;
				sum[i][4*(j-1)+4]=1;
			} 
		}
	}
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j){
			sum[i][j]=sum[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
		}
	}
	for (int i=1;i<=n;++i){
		if (n%i==0 && work(i)) ans=max(ans,i);
	}
	printf("%d\n",ans);
	return 0;
}