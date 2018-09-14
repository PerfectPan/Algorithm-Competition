#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
const int N=3e5+10;
struct Query{int x,y;}q[N];
ll h[N],f[N];
int n,i,j,k,mask,len,Q,sz,res[N],block[N];
void cal(int idx){
	int L=(idx-1)*sz+1,R=min(idx*sz,Q);
	for (int i=0;i<=mask;++i) f[i]=0;
	for (int i=L;i<=R;++i) f[q[i].x]+=q[i].y; 
	for (int i=0;i<len;++i){
		for (int status=0;status<(1<<len);++status){
			if (!(status&(1<<i))) f[status]+=f[status|(1<<i)];
		}
	}
}
int main(){
	read(n);
	for(mask=1;mask<n;mask<<=1)len++;mask--; 
	for (i=0;i<n;++i) read(h[i]);
	read(Q),sz=sqrt(Q+0.5);
	for (i=1;i<=Q;++i){
		read(q[i].x),read(q[i].y);
		q[i].x&=mask;
		block[i]=(i-1)/sz+1;
	}
	for (i=1;i<=(Q-1)/sz+1;++i){
		cal(i);
		for (j=0;j<n;++j)if(h[j]>0){
			h[j]-=f[j];
			if (h[j]<=0){
				h[j]+=f[j];
				for (k=(i-1)*sz+1;k<=min(i*sz,Q);++k){
					if ((j&q[k].x)==j){//careful
						h[j]-=q[k].y;
						if (h[j]<=0){
							res[k]++;
							break;
						}
					}
				}
			}
		}
	}
	for (i=1;i<=Q;++i){
		res[i]+=res[i-1];
		printf("%d\n",n-res[i]);
	}
	return 0;
}