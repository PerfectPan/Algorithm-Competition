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
const int N=10000+10;
int T,cnt[26],cnts[26];
char s[N],t[N];
int main(){
    for (read(T);T--;){
        scanf("%s%s",s+1,t+1);
        int lens=strlen(s+1),lent=strlen(t+1);
        memset(cnts,0,sizeof(cnts));
        for (int i=1;i<=lens;++i) cnts[s[i]-'a']+=1;
        bool flag=0;
        for (int i=1;i+lens-1<=lent;++i){
            int r=i+lens-1;
            memset(cnt,0,sizeof(cnt));
            for (int j=i;j<=r;++j){
                cnt[t[j]-'a']+=1;
            }
            bool f=0;
            for (int j=0;j<26;++j){
                if (cnt[j]!=cnts[j]){
                    f=1;
                    break;
                }
            }
            if (!f){
                flag=1;
                break;
            }
        }
        puts(flag?"YES":"NO");
    }
    return 0;
}