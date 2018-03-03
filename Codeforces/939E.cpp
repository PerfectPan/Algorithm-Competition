#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while(ch<'0'||ch>'9')f|=(ch=='-'),ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
//二分f(i)
const int N=500000+10;
int Q,op,i,x,cnt,l,r,pos;
double ans=0,res;
ll sum[N],a[N];
ll f(int x){return a[cnt]+sum[x]-(x+1)*a[x+1];}
void gmax(double&a,double b){if(a<b)a=b;}
int main(){
    for (read(Q);Q--;){
        read(op);
        if (op==1){
            cnt++,read(a[cnt]);
            sum[cnt]+=sum[cnt-1]+a[cnt];
        }
        else{
            res=0,l=1,r=cnt-1,pos=0;
            while (l<=r){
                int mid=l+((r-l)>>1);
                if (f(mid)<=0){
                    r=mid-1;
                    pos=mid;
                }
                else l=mid+1;
            }
            res=a[cnt]-1.0*(sum[pos]+a[cnt])/(pos+1);
            gmax(ans,res);
            printf("%.7lf\n",ans);
        }
    }
}
//函数是单峰极值函数，可用三分法
const int N=500000+10;
const double eps=1e-7;
int Q,op,i,x,cnt,l,r,pos;
double ans=0,res;
ll sum[N],a[N];
double f(int x){return a[cnt]-1.0*(a[cnt]+sum[x])/(x+1);}
int ternary_search(int l,int r){
    while (l+1<r){
        int midl=(l+((r-l)>>1));
        int midr=(midl+((r-midl)>>1));
        if (f(midl)>=f(midr)) r=midr;
        else l=midl;
    }
    return f(l)>f(r)?l:r;
}
void gmax(double&a,double b){if(a<b)a=b;}
int main(){
    for (read(Q);Q--;){
        read(op);
        if (op==1){
            cnt++,read(a[cnt]);
            sum[cnt]=sum[cnt-1]+a[cnt];
        }
        else{
            gmax(ans,f(ternary_search(1,cnt)));
            printf("%.7lf\n",ans);
        }
    }
}
//尺取法
const int N=500000+10;
int Q,op,x,cnt,now;
double ans;
ll sum[N],a[N];
int main(){
    for (read(Q);Q--;){
        read(op);
        if (op==1){
            cnt++,read(a[cnt]);
            sum[cnt]+=sum[cnt-1]+a[cnt];
        }
        else{
            ans=1.0*a[cnt]-1.0*(sum[now]+a[cnt])/(now+1);
            while(now+1<cnt&&1.0*a[cnt]-1.0*(sum[now+1]+a[cnt])/(now+2)>ans){
                now++;
                ans=1.0*a[cnt]-1.0*(sum[now]+a[cnt])/(now+1);
            }
            printf("%.7lf\n",ans);
        }
    }
}
