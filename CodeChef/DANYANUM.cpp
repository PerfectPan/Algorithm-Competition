#include <bits/stdc++.h>
using namespace std;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=(1<<18)+10;
int n,m,k,i,sz,qsize,op,x,cnt[N],num[N],q[N],qval[N];
void SOS(){
	int i,status;
	for (i=0;i<(1<<k);++i) num[i]=cnt[i];
	for (i=0;i<k;++i){
		for (status=0;status<(1<<k);++status){
			if (!(status&(1<<i))) num[status]+=num[status|(1<<i)];
		}
	}
}
void add(int x){
	if (qsize>=sz){
		qsize=0;
		SOS();
	}
	cnt[x]++;
	q[qsize]=x;
	qval[qsize]=1;
	qsize++;
}
void del(int x){
	if (qsize>=sz){
		qsize=0;
		SOS();
	}
	cnt[x]--;
	q[qsize]=x;
	qval[qsize]=-1;
	qsize++;
}
int getNum(int status){
	int res=num[status],i;
	for (i=0;i<qsize;++i){
		if ((q[i]&status)==status) res+=qval[i];
	}
	return res;
}
int solve(int x){
	int res=0,i;
	for (i=18;i>=0;--i){
		if (getNum(res|(1<<i))>=x) res|=1<<i;
	}
	return res;
}
int main(){
	read(n),read(m),read(k);
	for (i=1;i<=n;++i){
		read(x);
		cnt[x]++;
	}
	SOS();
	sz=sqrt(m+0.5);
	for (;m--;){
		read(op),read(x);
		if (op==1) add(x);
		if (op==2) del(x);
		if (op==3) printf("%d\n",solve(x));
	}
	return 0;
}