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
const int N=10000+10;
string s;
int main(){
	cin>>s;
	int cnt=-1;
	int a=10,b=26,ans=1;
	for (int i=0;i<(int)s.length();i++){
		if (s[i]=='d'){
			if (i&&s[i-1]=='d') a--;
			ans*=a;
			a=10;
		}
		else{
			if (i&&s[i-1]=='c') b--;
			ans*=b;
			b=26;
		}
	}
	cout<<ans<<endl;
	return 0;
}