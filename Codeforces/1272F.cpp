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
const int N=200+5;
struct State{
    int x,y,k;
    char s;
};
int i,j,k,ls,lt,dp[N][N][N<<1];
State p[N][N][N<<1];
char s[N],t[N];
int main(){
    scanf("%s%s",s+1,t+1);
    ls=strlen(s+1),lt=strlen(t+1);
    for(i=0;i<=ls;++i)for(j=0;j<=lt;++j)for(k=0;k<2*N;++k)dp[i][j][k]=1e9;
    dp[0][0][0]=0;
    for (i=0;i<=ls;++i){
        for (j=0;j<=lt;++j){
            for (k=0;k<2*N;++k)if(dp[i][j][k]!=1e9){
                int nxi=i+(i+1<=ls && s[i+1]=='(');
                int nxj=j+(j+1<=lt && t[j+1]=='(');
                if (k+1<2*N && dp[nxi][nxj][k+1]>dp[i][j][k]+1){
                    dp[nxi][nxj][k+1]=dp[i][j][k]+1;
                    p[nxi][nxj][k+1]=(State){i,j,k,'('};
                }

                nxi=i+(i+1<=ls && s[i+1]==')');
                nxj=j+(j+1<=lt && t[j+1]==')');
                if (k>0 && dp[nxi][nxj][k-1]>dp[i][j][k]+1){
                    dp[nxi][nxj][k-1]=dp[i][j][k]+1;
                    p[nxi][nxj][k-1]=(State){i,j,k,')'};
                }
            }
        }
    }
    int pos=0;
    for (k=0;k<2*N;++k){
        if (dp[ls][lt][k]+k<dp[ls][lt][pos]+pos){
            pos=k;
        }
    }
    string res=string(pos,')');
    while (ls>0 || lt>0 || pos!=0){
        int nxi=p[ls][lt][pos].x;
        int nxj=p[ls][lt][pos].y;
        int nxk=p[ls][lt][pos].k;
        res+=p[ls][lt][pos].s;
        ls=nxi;
        lt=nxj;
        pos=nxk;
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;
    return 0;
}