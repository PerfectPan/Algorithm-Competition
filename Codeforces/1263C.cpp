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
int T,n,i,lst;
vector<int>vec;
int main(){
    for (read(T);T--;){
        read(n);
        vec.clear();
        vec.push_back(0);
        for (i=1;i<=n;i=lst+1){
            lst=n/(n/i);
            vec.push_back(lst);
            // printf(" %d",lst);
        }
        printf("%d\n",(int)vec.size());
        for (i=0;i<(int)vec.size();++i){
            printf("%d%c",vec[i],i==(int)vec.size()-1?'\n':' ');
        }
    }
    return 0;
}