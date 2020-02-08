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
const int N=2e5+10;
int T,n,i,len,Y[N],X[N];
char s[N];
map<pair<int,int>,int>mp;
int main(){
    for (read(T);T--;mp.clear()){
        read(n);
        scanf("%s",s+1);len=strlen(s+1);
        int L=-1,R=-1,ans=-1,tx=0,ty=0;
        mp[MP(0,0)]=0;
        for (i=1;i<=len;++i){
            if (s[i]=='L') tx--;
            else if (s[i]=='R') tx++;
            else if (s[i]=='U') ty++;
            else ty--;
            if (mp.find(MP(tx,ty))!=mp.end()){
                if (ans==-1 || i-mp[MP(tx,ty)]<ans){
                    L=mp[MP(tx,ty)]+1;
                    R=i;
                    ans=i-mp[MP(tx,ty)];
                }
            } 
            mp[MP(tx,ty)]=i;
        }
        if (L==-1) puts("-1");
        else printf("%d %d\n",L,R);
    }
    return 0;
}