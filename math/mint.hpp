#ifndef ONLINE_JUDGE
#include "../template/template.hpp"
#endif

template<int m>
struct MInt{
    //static int m;

    ll x;
    MInt(ll x=0):x((x%m+m)%m){}

    MInt operator-()const{return MInt(-x);}
    MInt operator+(const MInt &p)const{return MInt(*this)+=p;}
    MInt operator-(const MInt &p)const{return MInt(*this)-=p;}
    MInt operator*(const MInt &p)const{return MInt(*this)*=p;}
    MInt operator/(const MInt &p)const{return MInt(*this)/=p;}

    MInt &operator+=(const MInt &p){
        if((x+=p.x)>=m)x-=m;
        return *this;
    }
    MInt &operator-=(const MInt &p){
        if((x+=m-p.x)>=m)x-=m;
        return *this;
    }
    MInt &operator*=(const MInt &p){
        (x*=p.x)%=m;
        return *this;
    }
    MInt &operator/=(const MInt &p){
        return *this*=p.inv();
    }

    MInt pow(ll n)const{
        MInt ret(1),mul(x);
        while(n){
            if(n&1)ret*=mul;
            mul*=mul;
            n>>=1;
        }
        return ret;
    }
    MInt inv()const{
        //return pow(m-2);
        int a=x,b=m,u=1,v=0,t;
        while(b){
            t=a/b;
            swap(a-=t*b,b);
            swap(u-=t*v,v);
        }
        return MInt(u);
    }

    friend ostream& operator<<(ostream& os,const MInt& a) {return os<<a.x;}
};
//int MInt::m=0;
using mint=MInt<mod>;