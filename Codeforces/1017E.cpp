#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long ll;
typedef long double ld;
template<typename T>
inline T read(T&x){
	x=0;int f=0;char ch=getchar();
	while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x=f?-x:x;
}
struct Point{
    ll x,y;
    Point(ll x=0,ll y=0):x(x),y(y){}
    int read(){
        return scanf("%lld%lld",&x,&y);
    }
};
typedef Point Vector;
Vector operator +(Vector A,Vector B){return Vector(A.x+B.x,A.y+B.y);}
Vector operator -(Point A,Point B){return Vector(A.x-B.x,A.y-B.y);}
Vector operator *(Vector A,double p){return Vector(A.x*p,A.y*p);}
bool operator<(const Point&a,const Point&b){
    return a.x-b.x<0||(a.x-b.x==0&&a.y-b.y<0);
}
bool operator==(const Point&a,const Point&b){
    return a.x-b.x==0&&a.y-b.y==0;
}
//叉积
ll Cross(Vector A,Vector B){return A.x*B.y-A.y*B.x;}
ll Dot(Vector A,Vector B){return A.x*B.x+A.y*B.y;}
ll Len(Vector A){return A.x*A.x+A.y*A.y;}
//求凸包数组版及O(logn)判断点是否在凸包里
int ConvexHull(Point* p,Point* ch,int n){
    sort(p,p+n);//先比较x坐标再比较y坐标
    n=unique(p,p+n)-p;
    int m=0;
    for (int i=0;i<n;i++){
        while (m>1 && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
        ch[m++]=p[i];
    }
    int k=m;
    for (int i=n-2;i>=0;i--){
        while (m>k && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
        ch[m++]=p[i];
    }
    if (n>1) m--;
    return m;
}
const int N=1e5+10;
int n,m,i,ch1sz,ch2sz,pos1,pos2;
Point ch1[N],ch2[N],conv1[N],conv2[N];
vector<ld>str1,str2;
void get(Point p[],int sz,vector<ld>& rhs){
	for (int i=0;i<sz;i++){
		rhs.push_back(Len(p[i]-p[i-1<0?i-1+sz:i-1]));
		Vector a=p[i]-p[i-1<0?i-1+sz:i-1],b=p[i+1>=sz?i+1-sz:i+1]-p[i];
		rhs.push_back((long double)(Dot(a,b))/sqrt(1.0*Len(a))/sqrt(1.0*Len(b)));
	}
}
int MininumRepresentation(vector<ld>&b,int len){
    int i=0,j=1,k=0;
    ld t;
    while(i<len && j<len && k<len){
        t=b[(i+k)>=len?i+k-len:i+k]-b[(j+k)>=len?j+k-len:j+k];
        if(!t) k++;
        else{
            if (t>0) i+=k+1;
            else j+=k+1;
            if (i==j) j++;
            k=0;
        }
    }
    return (i<j?i:j);
}
bool check(){
	int len=(int)str1.size();
	for (int i=0;i<len;i++){
		if (str1[(i+pos1)%len]!=str2[(i+pos2)%len]) return 0;
	}
	return 1;
}
int main(){
	read(n),read(m);
	for (i=0;i<n;i++) ch1[i].read();
	ch1sz=ConvexHull(ch1,conv1,n);
	get(conv1,ch1sz,str1);
	pos1=MininumRepresentation(str1,(int)str1.size());
	for (i=0;i<m;i++) ch2[i].read();
	ch2sz=ConvexHull(ch2,conv2,m);
	get(conv2,ch2sz,str2);
	pos2=MininumRepresentation(str2,(int)str2.size());
	puts((int)str1.size()==(int)str2.size()&&check()?"YES":"NO");
	return 0;
}
