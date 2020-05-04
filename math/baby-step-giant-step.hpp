#ifndef TEMPLATE_USED
#include "../template/template.hpp"
#endif

template<typename T>
T pow(T a,T x,T m){
    T ret=1;
    while(x){
        if(x&1)ret=ret*a%m;
        a=a*a%m;
        x>>=1;
    }
    return ret;
}

template<typename T>
T baby_step_giant_step(T x,T y,T m){
    map<T,T> mp;
    mp.emplace(1,0);

    T sq=(T)sqrt(m)+1;
    T t=1;
    repe(i,1,sq){
        t=t*x%m;
        mp[t]=i;
    }

    T inv=pow<T>(t,m-2,m);
    repe(i,sq){
        if(mp.find(y)!=mp.end())return mp[y]+i*sq;
        y=y*inv%m;
    }

    return -1;
}
