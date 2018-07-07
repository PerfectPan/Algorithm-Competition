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
/*const int N=1e5+10;
int n,i,j,sum,a[N];
double res;
int main(){
	read(n);
	for (i=1;i<=n;i++) read(a[i]);
	i=j=1;
	for (i=1;i<=n&&a[i]!=-1;i++);
	for (;i<=n;i++)if(a[i]==-1){
		int pre=i;
		sum=2;
		while (i<n&&sum>0){
			i++;
			if (a[i]==-1) sum+=2;
			else if (a[i]==0) sum-=1;
			else sum-=2;
			if (sum<0){
				res=max(res,i-pre+0.5);
				break;
			}
			else if (sum==0){
				if (i+1<=n&&a[i+1]==-1){
					i++;
					sum+=2;
					continue;
				}
				res=max(res,i-pre+1.0);
				break;
			}
		}
		if (sum>0){
			res=max(res,i-pre+1.0);
		}
	}
	printf("%.1lf\n",res);
	return 0;
}*/
const int N=1e5+10;
int i,n,sum,val,res,pre;
vector<int>points;
int main(){
	read(n);
	for (i=1;i<=n;i++){
		read(val);
		if (val==0){
			points.PB(0);
			points.PB(-1);
		}
		else if (val==-1){
			points.PB(1);
			points.PB(1);
		}
		else{
			points.PB(-1);
			points.PB(-1);
		}
	}
	for (pre=-1,i=0;i<(int)points.size();i++){
		sum+=points[i];
		if (sum<0){
			sum=0;
			pre=i;
		}
		else if (points[i]){
			res=max(res,i-pre);
		}
	}
	printf("%.1lf\n",1.0*res/2.0);
	return 0;
}