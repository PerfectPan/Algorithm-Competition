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
const int N=500+10;
int n,m,q,i,j,k,a,b,c,d,mm[N],ans[N][N],pre[4][N][N];
char s[N][N];
int get(int k,int a,int b,int c,int d){
    return pre[k][c][d]-pre[k][a-1][d]-pre[k][c][b-1]+pre[k][a-1][b-1];
}
int dpmax[N][N][12][12];
void initRMQ(int n,int m){
    for(int ii=0;ii<=mm[n];ii++){
        for(int jj=0;jj<=mm[m];jj++)if(ii+jj){
            for(int i=1;i+(1<<ii)-1<=n;i++){
                for(int j=1;j+(1<<jj)-1<=m;j++){
                    if(ii){
                        dpmax[i][j][ii][jj] = max(dpmax[i][j][ii-1][jj],dpmax[i+(1<<(ii-1))][j][ii-1][jj]);
                    }
                    else{
                        dpmax[i][j][ii][jj] = max(dpmax[i][j][ii][jj-1],dpmax[i][j+(1<<(jj-1))][ii][jj-1]);
                    }
                }
            }
        }
    }
}
int query(int x1,int y1,int x2,int y2){
    if (x1>x2 || y1>y2 || x1<1 || x2>n || y1<1 || y2>m) return -1e9;
    int k1=mm[x2-x1+1];
    int k2=mm[y2-y1+1];
    x2=x2-(1<<k1)+1;
    y2=y2-(1<<k2)+1;
    return max(max(dpmax[x1][y1][k1][k2],dpmax[x1][y2][k1][k2]),max(dpmax[x2][y1][k1][k2],dpmax[x2][y2][k1][k2]));
}
int main(){
    mm[0]=-1;
    for(i=1;i<=500;++i) mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
    read(n),read(m),read(q);
    for (i=1;i<=n;++i){
        scanf("%s",s[i]+1);
    }
    for (i=1;i<=n;++i){
        for (j=1;j<=m;++j){
            for (k=0;k<4;++k){
                pre[k][i][j]=pre[k][i-1][j]+pre[k][i][j-1]-pre[k][i-1][j-1];
                if (k==0 && s[i][j]=='R') pre[k][i][j]++;
                if (k==1 && s[i][j]=='G') pre[k][i][j]++;
                if (k==2 && s[i][j]=='Y') pre[k][i][j]++;
                if (k==3 && s[i][j]=='B') pre[k][i][j]++;
            }
        }
    }
    for (i=1;i<=n;++i){
        for (j=1;j<=m;++j){
            int len=min(min(i,n-i+1),min(j,m-j+1));
            for (k=1;k<=len;++k){
                if (get(0,i-k+1,j-k+1,i,j)==k*k
                    && get(1,i-k+1,j+1,i,j+k)==k*k
                    && get(2,i+1,j-k+1,i+k,j)==k*k
                    && get(3,i+1,j+1,i+k,j+k)==k*k)
                dpmax[i][j][0][0]=k;
            }
        }
    }
    initRMQ(n,m);
    for (i=1;i<=q;++i){
        read(a),read(b),read(c),read(d);
        int l=1,r=min(abs(a-c),abs(b-d)),ans=0;
        while (l<=r){
            int mid=l+((r-l)>>1);
            if (query(a+mid-1,b+mid-1,c-mid,d-mid)>=mid){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        printf("%d\n",4*ans*ans);
    }
    return 0;
}