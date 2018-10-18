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
const int N=10000+10;
const double eps=1e-14;
struct P{double x,y,w,tot;}p[N],ans;
int n,i;
double sqr(double x){return x*x;}
double dist(P a,P b){return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));}
double calc(P x){
    double res=0;
    for (int i=1;i<=n;++i) res+=p[i].w*dist(x,p[i]);
    return res;
}
void SA(double T){
    P now=ans,cur;
    while (T>eps){
        cur.x=now.x+T*(rand()*2-RAND_MAX);
        cur.y=now.y+T*(rand()*2-RAND_MAX);
        cur.tot=calc(cur);
        if (cur.tot<now.tot || exp((now.tot-cur.tot)/T)*RAND_MAX>rand()) now=cur;
        if (cur.tot<ans.tot) ans=cur;
        T*=0.99;
    }
    for (int i=1;i<=5000;++i){
        cur.x=ans.x+T*(rand()*2-RAND_MAX);
        cur.y=ans.y+T*(rand()*2-RAND_MAX);
        cur.tot=calc(cur);
        if (cur.tot<ans.tot) ans=cur;
    }
}
int main(){
    srand(time(NULL));
    read(n);
    for (i=1;i<=n;++i){
        scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].w);
        ans.x+=p[i].x,ans.y+=p[i].y;
    }
    ans.x/=n,ans.y/=n,ans.tot=calc(ans);
    for (i=1;i<=10;++i) SA(20000);
    printf("%.3lf %.3lf\n",ans.x,ans.y);
    return 0;
}