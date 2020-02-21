#include<bits/stdc++.h>
#define MP make_pair
#define PB emplace_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N=1e5+10;
int T,n,m,i,j,k,x[N],y[N],cnt[N],cnt2[N],cnt3[N],primes[N];
ll ans;
vector<pair<int,int> >fac[N],vec;
void dfs(int idx,int cur,int num,ll x){
    if (idx==(int)vec.size()){
        if (cur!=1 && x/cur<=100000ll && 1ll*cur*cur!=x) fac[i].push_back(MP(cur,(int)(x/cur))); // 是(int)(x/cur)不能是(int)x/cur!!!
        return;
    }
    dfs(idx+1,cur,num,x);
    for (int j=1;j<=(int)vec[idx].second;++j){
        if (1ll*cur*vec[idx].first<1ll*num){
            cur*=vec[idx].first;
            dfs(idx+1,cur,num,x);
        }
        else break;
    }
}
void init(){
    for (i=2;i<=1e5;++i){
        if (!primes[i]) primes[++primes[0]]=i;
        for (j=1;j<=primes[0] && primes[j]*i<=1e5;++j){
            primes[i*primes[j]]=1;
            if (i%primes[j]==0) break;
        }
    }
    for (i=2;i<=1e5;++i){
        vec.clear();
        int num=i;
        for (j=1;j<=primes[0] && primes[j]<=num;++j){
            int cnt=0;
            while (num%primes[j]==0){
                num/=primes[j];
                cnt++;
            }
            if (cnt) vec.push_back(MP(primes[j],cnt<<1));
        }
        if (num>1) vec.push_back(MP(num,2));
        dfs(0,1,i,1ll*i*i);
        if (1ll*i*i<=100000ll) fac[i].push_back(MP(1,i*i));
    }
}
int main(){
    init();
    for (read(T);T--;){
        ans=0;
        read(n),read(m);
        for (i=1;i<=1e5;++i) cnt[i]=cnt2[i]=cnt3[i]=0;
        int zx=0,zy=0;
        for (i=1;i<=n;++i) read(x[i]),zx+=x[i]==0;
        for (i=1;i<=m;++i) read(y[i]),zy+=y[i]==0;
        
        for (i=1;i<=n;++i) cnt[abs(x[i])]++;
        for (i=1;i<=m;++i){
            if (y[i]>0) cnt2[y[i]]++;
            else if (y[i]<0) cnt3[abs(y[i])]++;
        }
        for (i=1;i<=n;++i)if(x[i]!=0){
            for (j=0;j<(int)fac[abs(x[i])].size();++j){
                pair<int,int> c=fac[abs(x[i])][j];
                int A=c.first,B=c.second;
                if (A==0 || B==0) continue;
                ans+=1ll*cnt2[A]*cnt3[B];
                if (A!=B) ans+=1ll*cnt2[B]*cnt3[A];
            }
            ans+=1ll*cnt2[abs(x[i])]*cnt3[abs(x[i])];
        }

        for (i=1;i<=1e5;++i) cnt[i]=cnt2[i]=cnt3[i]=0;
        for (i=1;i<=m;++i) cnt[abs(y[i])]++;
        for (i=1;i<=n;++i){
            if (x[i]>0) cnt2[x[i]]++;
            else if (x[i]<0) cnt3[abs(x[i])]++;
        }
        for (i=1;i<=m;++i)if(y[i]!=0){
            for (j=0;j<(int)fac[abs(y[i])].size();++j){
                pair<int,int> c=fac[abs(y[i])][j];
                int A=c.first,B=c.second;
                if (A==0 || B==0) continue;
                ans+=1ll*cnt2[A]*cnt3[B];
                if (A!=B) ans+=1ll*cnt2[B]*cnt3[A];
            }
            ans+=1ll*cnt2[abs(y[i])]*cnt3[abs(y[i])];
        }
        ans+=1LL*zy*(n-zx)*(m-zy);
        ans+=1LL*zx*(n-zx)*(m-zy);
        printf("%lld\n",ans);
    }
    return 0;
}