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
const int N=1e3+10;
int T,n,p,i,j,d[N];
int main(){
    for (read(T);T--;){
        read(n),read(p);
        int num=-1;
        for (i=1;i<=n;++i){
            read(d[i]);
            if (d[i]>p || p%d[i]!=0) num=d[i];
        }
        if (~num){
            printf("YES ");
            for (i=1;i<=n;++i){
                if (d[i]==num){
                    if (d[i]>p) printf("1%c",i==n?'\n':' ');
                    else printf("%d%c",(p+d[i]-1)/d[i],i==n?'\n':' ');
                }
                else printf("0%c",i==n?'\n':' ');
            }
        }
        else{
            bool flag=0;
            for (i=1;i<=n;++i){
                for (j=i+1;j<=n;++j){
                    int x=(p-d[j]+d[i]-1)/d[i];
                    int tot=d[j]+d[i]*x;
                    if (tot>p && tot-d[i]<p && tot-d[j]<p){
                        flag=1;
                        break;
                    }
                }  
                if (flag) break;
            }
            if (!flag) puts("NO");
            else{
                printf("YES ");
                int a=i,b=j;
                int x=(p-d[j]+d[i]-1)/d[i];
                for (i=1;i<=n;++i){
                    if (i==b) printf("1%c",i==n?'\n':' ');
                    else if (i==a) printf("%d%c",x,i==n?'\n':' ');
                    else printf("0%c",i==n?'\n':' ');
                }
            }
        }
    }
    return 0;
}