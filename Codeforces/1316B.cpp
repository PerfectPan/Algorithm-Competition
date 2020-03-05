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
int T,n;
string s;
vector<pair<string,int> >vec;
int main(){

std::ios::sync_with_stdio(false);
cin.tie(0), cout.tie(0);
    for (cin>>T;T--;){
        cin>>n>>s;
        vec.clear();
        vec.push_back(MP(s,1));
        for (int i=1;i<n;++i){
            string t=s.substr(i);
            string tt=s.substr(0,i);
            int left=n-i;
            string ans;
            if (left&1){
                reverse(tt.begin(),tt.end());
                ans=t+tt;
            }
            else ans=t+tt;
            vec.push_back(MP(ans,i+1));
        }
        sort(vec.begin(),vec.end());
        cout<<vec[0].first<<endl;
        cout<<vec[0].second<<endl;
    }
    return 0;
}