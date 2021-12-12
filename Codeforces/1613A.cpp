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
int T,x1,p1,x2,p2;
int main() {
    for (read(T);T--;){
        read(x1),read(p1),read(x2),read(p2);
        string num1=to_string(x1);
        string num2=to_string(x2);
        if (num1.size()+p1>num2.size()+p2) {
            puts(">");
        }
        else if (num1.size()+p1<num2.size()+p2) {
            puts("<");
        }
        else {
            int i,j,f=0;
            for (i=0,j=0;i<num1.size()&&j<num2.size();++i,++j) {
                if (num1[i]<num2[j]) {
                    puts("<");
                    f=1;
                    break;
                }
                if (num1[i]>num2[j]){
                    puts(">");
                    f=1;
                    break;
                }
            }
            if (f) {
                continue;
            }
            if (i==num1.size() && j==num2.size()) {
                puts("=");
            } 
            else if (i<num1.size()) {
                for (;i<num1.size();++i){
                    if (num1[i]!='0'){
                        puts(">");
                        f=1;
                        break;
                    }
                }
                if (!f) {
                    puts("=");
                }
            }
            else {
                for (;j<num2.size();++j){
                    if (num2[j]!='0'){
                        puts("<");
                        f=1;
                        break;
                    }
                }
                if (!f) {
                    puts("=");
                }
            }
        }
    }
    return 0;
}

