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
const int N=1e6+10;
ll n,m,k,tn;
bool flag=1;
const int S=20;//随机算法判定次数，S越大，判错概率越小
//计算 (a*b)%c.   a,b都是long long的数，直接相乘可能溢出的
//  a,b,c <2^63
ll mult_mod(ll a,ll b,ll c)
{
    a%=c;
    b%=c;
    ll ret=0;
    while(b)
    {
        if(b&1){ret+=a;ret%=c;}
        a<<=1;
        if(a>=c)a%=c;
        b>>=1;
    }
    return ret;
}
ll pow_mod(ll x,ll n,ll mod)
{
    if(n==1)return x%mod;
    x%=mod;
    ll tmp=x;
    ll ret=1;
    while(n)
    {
        if(n&1) ret=mult_mod(ret,tmp,mod);
        tmp=mult_mod(tmp,tmp,mod);
        n>>=1;
    }
    return ret;
}
//以a为基,n-1=x*2^t      a^(n-1)=1(mod n)  验证n是不是合数
//一定是合数返回true,不一定返回false
bool check(ll a,ll n,ll x,ll t)
{
    ll ret=pow_mod(a,x,n);
    ll last=ret;
    for(int i=1;i<=t;i++)
    {
        ret=mult_mod(ret,ret,n);
        if(ret==1&&last!=1&&last!=n-1) return true;//合数
        last=ret;
    }
    if(ret!=1) return true;
    return false;
}
// Miller_Rabin()算法素数判定
//是素数返回true.(可能是伪素数，但概率极小)
//合数返回false;
bool Miller_Rabin(ll n)
{
    if(n<2)return false;
    if(n==2)return true;
    if((n&1)==0) return false;//偶数
    ll x=n-1;
    ll t=0;
    while((x&1)==0){x>>=1;t++;}
    for(int i=0;i<S;i++)
    {
        ll a=rand()%(n-1)+1;//rand()需要stdlib.h头文件
        if(check(a,n,x,t))
            return false;//合数
    }
    return true;
}
ll factor[N];//质因数分解结果（刚返回时是无序的）
int tol;//质因数的个数。数组小标从0开始
ll gcd(ll a,ll b)
{
    if(a==0)return 1;//???????
    if(a<0) return gcd(-a,b);
    while(b)
    {
        ll t=a%b;
        a=b;
        b=t;
    }
    return a;
}
ll Pollard_rho(ll x,ll c)
{
    ll i=1,k=2;
    ll x0=rand()%x;
    ll y=x0;
    while(1)
    {
        i++;
        x0=(mult_mod(x0,x0,x)+c)%x;
        ll d=gcd(y-x0,x);
        if(d!=1&&d!=x) return d;
        if(y==x0) return x;
        if(i==k){y=x0;k+=k;}
    }
}
//对n进行素因子分解
void findfac(ll n)
{
    if(Miller_Rabin(n))//素数
    {
        factor[tol++]=n;
        return;
    }
    ll p=n;
    while(p>=n)p=Pollard_rho(p,rand()%(n-1)+1);
    findfac(p);
    findfac(n/p);
}
void dfs(int x,ll num){
	if (!flag || num>max(n,m)) return;
	if (x==tol-1){
		if (!flag) return;
		ll a=num,b=tn/num;
		if (a>b) swap(a,b);
		if (n<m){
			if (a>=0 && a<=n && b>=0 && b<=m){
				puts("YES");
				printf("0 0\n");
				printf("%lld 0\n",a);
				printf("0 %lld\n",b);
				flag=0;
			}
		}
		else{
			if (a>=0 && a<=m && b>=0 && b<=n){
				puts("YES");
				printf("0 0\n");
				printf("%lld 0\n",b);
				printf("0 %lld\n",a);
				flag=0;
			}
		}
		return;
	}
	dfs(x+1,num*factor[x+1]);
	if (!flag) return;
	dfs(x+1,num);
	if (!flag) return;
}
int main(){
	read(n),read(m),read(k);
	ll g=__gcd(n*m,k);
	tn=n*m/g,k/=g;
	if (k==1 || k==2){
		if (k==1) tn*=2LL;
		if (tn>n*m) puts("NO");
		else{
			if (tn>1) findfac(tn);
			else factor[tol++]=1;
			dfs(-1,1LL);
			if (flag) puts("NO");
		}
	}
	else puts("NO");
	return 0;
}