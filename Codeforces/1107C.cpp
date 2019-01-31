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
const int N=2e5+10;
int n,k,i,cnt[30],a[N];
char s[N];
ll ans=0;
inline bool cmp(const int&A,const int& B){
	return A>B;
}
int main(){
	read(n),read(k);
	for (i=1;i<=n;++i){
		read(a[i]);
	}
	scanf("%s",s+1);
	vector<int>vec;
	int pre=0;
	for (i=1;i<=n;++i){
		if (s[i]-'a'+1!=pre){
			sort(vec.begin(),vec.end());
			reverse(vec.begin(),vec.end());
			// puts("***");
			for (int j=0;j<(int)vec.size();++j){
				if (j==k) break;
				ans+=vec[j];
				// cout<<vec[j]<<endl;
			}
			vec.clear();
			// puts("***");
			vec.push_back(a[i]);
			pre=s[i]-'a'+1;
		}
		else{
			vec.push_back(a[i]);
			// pre=s[i]-'a'+1;
		}
	}
	sort(vec.begin(),vec.end(),cmp);
			for (int j=0;j<(int)vec.size();++j){
				if (j==k) break;
				ans+=vec[j];
			}
	printf("%lld\n",ans);
	return 0;
}