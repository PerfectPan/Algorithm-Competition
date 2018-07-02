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
const int N=100+10;
int n,a[13]={0,4,10,20,35,56,83,116,155,198,244,292};
/*int n,f[N*50];
int v[4]={1,5,10,50};
set<int>S;
void dfs(int idx,int num){
	if (idx==0){
		S.insert(num);
		return;
	}
	for (int i=0;i<4;i++){
		dfs(idx-1,num+v[i]);
	}
}
int main(){
	for (n=1;n<=50;n++){
		cout<<n<<endl;
		dfs(n,0);
		cout<<(int)S.size()<<",";
		S.clear();
	}
	return 0;
}*/
int main(){
	read(n);
	if (n<=11) printf("%d\n",a[n]);
	else printf("%lld\n",292+1LL*(n-11)*49); 
	return 0;
}
