#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,i,l,r,p,cnt,a[N],b[N];
bool check(){
	for (i=1;i<n;i++) if (b[i]>b[i+1]) return 0;
	return 1;
}
int main(){
	scanf("%d",&n);
	for (l=1,r=1,i=1;i<=n;i++) scanf("%d",&a[i]);
	for (i=1;i<n;i++){
		p=i;
		if (a[i]>a[i+1]){
			l=i;
			while (p+1<=n&&a[p]>a[p+1]) p++;
			r=p;
			break;
		}
	}
	for (i=1;i<l;i++) b[++cnt]=a[i];
	for (i=r;i>=l;i--) b[++cnt]=a[i];
	for (i=r+1;i<=n;i++) b[++cnt]=a[i];
	if (check()){
		puts("yes");
		printf("%d %d\n",l,r);
	}
	else puts("no");
	return 0;
}