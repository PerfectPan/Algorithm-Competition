#include <bits/stdc++.h>
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	puts(std::min(n,m)&1?"Akshat":"Malvika");
	return 0;
}