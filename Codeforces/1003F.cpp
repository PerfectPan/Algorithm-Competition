#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
using namespace std;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x; 
}
/*const int N=300+10;
const int M=1e5+10;
int n,i,j,k,len,sum,l[N],pre[N];
char w[N][M];
int vis[N][N];
int main(){
	read(n);
	for (i=1;i<=n;i++){
		scanf("%s",w[i]);
		l[i]=strlen(w[i]);
		pre[i]=pre[i-1]+l[i];
		sum+=l[i];
		if (i!=n) sum++;
	}
	int res=sum;
	for (i=1;i<=n;i++){
		for (len=1;len<=n;len++){
			int tot=0;
			int ll=pre[i+len-1]-pre[i-1]+len-1;
			for (k=1;k+len-1<=n;k++){
				if (vis[k][i]==0){
					if (strcmp(w[k],w[i])==0) vis[k][i]=vis[i][k]=1;
					else vis[k][i]=vis[i][k]=-1;
				}
				if (vis[k][i]==1){
					int l=k,r=i,cnt=0;
					while (vis[l][r]==1||(vis[l][r]==0&&strcmp(w[l],w[r])==0)){
						vis[l][r]=vis[r][l]=1;
						cnt++;
						if (cnt==len) break;
						l++,r++;
					}
					if (cnt==len){
						tot++;
						k=l;
					}
				}
			}	
			if (tot>=2){
				int ans=sum-tot*ll;
				ans+=tot*len;
				res=min(ans,res);
			}
		}
	}
	printf("%d\n",res);
	return 0;
}*/
const int N=300+10;
const int M=1e5+10;
map<string,int>mp;
char s[M];
int n,res,sum,i,j,k,a[N],len[N],nxt[N];
inline int getId(const string&t){
	if (!mp[t]) mp[t]=(int)mp.size();
	return mp[t];
}
int kmp(int a[],int n,int b[],int m){
	int i,j,res=0;
	for (nxt[0]=j=-1,i=1;i<n;nxt[i++]=j){
		while (~j&&a[j+1]!=a[i]) j=nxt[j];
		j+=(a[j+1]==a[i]);
	}
	for (j=-1,i=0;i<m;i++){
		while (~j&&a[j+1]!=b[i]) j=nxt[j];
		j+=(a[j+1]==b[i]);
		if (j==n-1) res++,j=-1;
	}
	return res;
}
int main(){
	read(n);
	for (i=1;i<=n;i++){
		scanf("%s",s);
		a[i]=getId(s);
		len[i]=strlen(s);
	}
	for (sum=n-1,i=1;i<=n;i++) sum+=len[i];
	res=sum;
	for (i=1;i<=n;i++){
		for (j=i;j<=n;j++){
			int cnt=kmp(a+i,j-i+1,a+1,n);
			if (cnt>=2){
				int tot=j-i;
				for (k=i;k<=j;k++) tot+=len[k]-1;
				res=min(res,sum-tot*cnt);
			}
		}
	}
	printf("%d\n",res);
	return 0;
}