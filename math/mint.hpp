#ifndef ONLINE_JUDGE
#include "../template/template.hpp"
#endif

struct mint{
    static int m;

    ll x;
    mint(ll x=0):x((x%m+m)%m){}

    mint operator-()const{return mint(-x);}
    mint operator+(const mint &p)const{return mint(*this)+=p;}
    mint operator-(const mint &p)const{return mint(*this)-=p;}
    mint operator*(const mint &p)const{return mint(*this)*=p;}
    mint operator/(const mint &p)const{return mint(*this)/=p;}

    mint &operator+=(const mint &p){
        if((x+=p.x)>=m)x-=m;
        return *this;
    }
    mint &operator-=(const mint &p){
        if((x+=m-p.x)>=m)x-=m;
        return *this;
    }
    mint &operator*=(const mint &p){
        (x*=p.x)%=m;
        return *this;
    }
    mint &operator/=(const mint &p){
        return *this*=p.inv();
    }

    mint pow(ll n)const{
        mint ret(1),mul(x);
        while(n){
            if(n&1)ret*=mul;
            mul*=mul;
            n>>=1;
        }
        return ret;
    }
    mint inv()const{
        //return pow(m-2);
        int a=x,b=m,u=1,v=0,t;
        while(b){
            t=a/b;
            swap(a-=t*b,b);
            swap(u-=t*v,v);
        }
        return mint(u);
    }

    friend ostream& operator<<(ostream& os,const mint& a) {return os<<a.x;}
};
int mint::m=mod;