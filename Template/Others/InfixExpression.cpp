//递归法求中缀表达式的值，O(n^2)
#include <bits/stdc++.h>
using namespace std;
string s;
int calc(int l,int r){
	for (int i=r,j=0;i>=l;i--){
		if (s[i]=='(') j++;
		if (s[i]==')') j--;
		if (j==0&&s[i]=='+') return calc(l,i-1)+calc(i+1,r);
		if (j==0&&s[i]=='-') return calc(l,i-1)-calc(i+1,r);
	}
	for (int i=r,j=0;i>=l;i--){
		if (s[i]=='(') j++;
		if (s[i]==')') j--;
		if (j==0&&s[i]=='*') return calc(l,i-1)*calc(i+1,r);
		if (j==0&&s[i]=='/') return calc(l,i-1)/calc(i+1,r);
	}
	if (s[l]=='('&&s[r]==')') return calc(l+1,r-1);
	int ans=0;
	for (int i=l;i<=r;i++) ans=ans*10+s[i]-'0';
	return ans;
}
int main(){
	cin>>s;
	printf("%d\n",calc(0,(int)s.length()-1));
	return 0;
}