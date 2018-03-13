#include <cstdio>
#include <iostream>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=500000+10;
const int INF=~0U>>1;
int n;
char ch[105];
struct Node{
	int l,r,key;
	char str[10];
	void clear(){l=r=0;}
	bool operator < (const Node&rhs)const{
		return strcmp(str,rhs.str)<0;
	}
}T[N];
void init(int n){
	for (int i=0;i<=n;i++) T[i].clear();
	T[0].key=INF;
}
int build(int n){
	stack<int>S;
	S.push(0);
	for (int i=1,fa;i<=n;i++){
		while (fa=S.top(),T[fa].key<T[i].key) S.pop();
		T[i].l=T[fa].r;
		T[fa].r=i;
		S.push(i);
	}
	while (S.size()) S.pop();
	return T[0].r;
}
void dfs(int root){
	printf("(");
	if (T[root].l) dfs(T[root].l);
	printf("%s/%d",T[root].str,T[root].key);
	if (T[root].r) dfs(T[root].r);
	printf(")");
}
int main(){
	while (~scanf("%d",&n),n){
		init(n);
		for (int i=1;i<=n;i++){
			scanf("%s",ch);
			sscanf(ch,"%[^/]/%d",T[i].str,&T[i].key);
		}
		sort(T+1,T+n+1);
		int rt=build(n);
		dfs(rt);
		puts("");
	}
	return 0;
}