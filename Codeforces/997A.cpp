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
const int N=300000+10;
int n,i,j,x,y,cnt;
char s[N];
vector<int>vec;
ll ans;
int main(){
	read(n),read(x),read(y);
	scanf("%s",s);
	for (i=0;s[i];i++){
		cnt=0;
		while (s[i]&&s[i]=='0') i++,cnt++;
		if (cnt>0) vec.push_back(cnt);
	}
	if (x>=y){
		ans=1LL*(int)vec.size()*y;
	}
	else{
		if ((int)vec.size()==0) ans=0;
		else ans=1LL*((int)vec.size()-1)*x+y;
	}
	printf("%lld\n",ans);
	return 0;
}