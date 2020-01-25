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
int T,n,a,b,c,prime[N];
bool isPrime[N];
void init(){
    for (int i=2;i<=100000;i++){
        if (!isPrime[i]) prime[++prime[0]]=i;
        for (int j=1;i*prime[j]<=100000 && j<=prime[0];j++){
            isPrime[i*prime[j]]=true;
            if (i%prime[j]==0) break;
        }
    }
}
int main(){
    init();
    for (read(T);T--;){
        read(n);
        vector<int>vec;vec.clear();
        int l=1;
        for (int i=1;i<=prime[0] && n!=1;++i){
            if (n%prime[i]==0){
                int cnt=0,pp=n;
                while (n%prime[i]==0){
                    n/=prime[i];
                    cnt++;
                }
                if ((int)vec.size()==0){
                    if (cnt==1) vec.push_back(prime[i]);
                    else if (cnt==2){
                        vec.push_back(prime[i]);
                        l*=prime[i];
                    }
                    else{
                        vec.push_back(prime[i]);
                        vec.push_back(prime[i]*prime[i]);
                        for (int j=1;j<=cnt-3;++j) n*=prime[i];
                        vec.push_back(n);
                        break;
                    }
                }
                else if ((int)vec.size()==1){
                    if (cnt==1){
                        if (pp/prime[i]!=1){
                            vec.PB(prime[i]*l);
                            vec.PB(pp/prime[i]);
                        }
                    }
                    else{
                        vec.PB(prime[i]*l);
                        vec.PB(pp/prime[i]);
                    }
                    break;
                }
            }
        }
        if ((int)vec.size()!=3 || (vec[1]==vec[0]) || (vec[2]==vec[0]) || (vec[1]==vec[2]) || vec[0]==1 || vec[1]==1 || vec[2]==1) puts("NO");
        else{
            puts("YES");
            for (int i=0;i<3;++i) printf("%d%c",vec[i],i==2?'\n':' ');
        }
    }
    return 0;
}