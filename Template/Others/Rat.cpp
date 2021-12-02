typedef long long ll;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
struct Rat{
    ll a, b;
    Rat(ll a=0):a(a),b(1){}
    Rat(ll x,ll y):a(x),b(y){
        if(b<0) a=-a,b=-b;
        ll d=gcd(a, b); if(d<0) d=-d;
        a/=d; b/=d;
    }
};
Rat operator + (const Rat& A,const Rat& B){
    ll x=lcm(A.b,B.b);
    return Rat(A.a*(x/A.b)+B.a*(x/B.b),x);
}
Rat operator - (const Rat& A,const Rat& B){return A+Rat(-B.a,B.b);}
Rat operator * (const Rat& A,const Rat& B){return Rat(A.a*B.a,A.b*B.b);}
void updatemin(Rat& A,const Rat& B){
    if(A.a*B.b>B.a*A.b) A.a=B.a,A.b=B.b;
}
