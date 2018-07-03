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
int i,len,dp[N];
char s1[N],s2[N];
int main(){
	scanf("%s%s",s1+1,s2+1);
	len=strlen(s1+1);
	for (i=2;i<=len;i++){
		dp[i]=dp[i-1];
		if (s1[i]=='X'&&s2[i]=='0'){
			if (s1[i-1]==s2[i-1]&&s1[i-1]=='0') dp[i]=max(dp[i],dp[i-2]+1);
		}
		else if (s1[i]=='0'&&s2[i]=='X'){
			if (s1[i-1]==s2[i-1]&&s1[i-1]=='0') dp[i]=max(dp[i],dp[i-2]+1);
		}
		else if (s1[i]=='0'&&s2[i]=='0'){
			if (s1[i-1]=='X'&&s2[i-1]=='X');
			else if (s1[i-1]=='X'&&s2[i-1]=='0') dp[i]=max(dp[i],dp[i-2]+1);
			else if (s1[i-1]=='0'&&s2[i-1]=='X') dp[i]=max(dp[i],dp[i-2]+1);
			else{
				if (i==2) dp[i]=max(dp[i],dp[i-2]+1);
				else{
					if (s1[i-2]=='X'||s2[i-2]=='X') dp[i]=max(dp[i],dp[i-2]+1);
					else dp[i]=max(dp[i],dp[i-3]+2);
				}
			}
		}
	}
	printf("%d\n",dp[len]);
	return 0;
}