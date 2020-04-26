#ifndef ONLINE_JUDGE
#include "../template/template.hpp"
#endif

#include "../math/mint.hpp"

struct Combination{
    vector<mint> f,rev;
    Combination(int n):f(n+1),rev(n+1){
        f[0]=1;
        repe(i,1,n)f[i]=f[i-1]*i;
        rev[n]=mint(1)/f[n];
        rrep(i,n)rev[i]=rev[i+1]*(i+1);
    }
    mint p(int n,int k){return k<0||n<k?0:f[n]*rev[n-k];}
    mint c(int n,int k){return k<0||n<k?0:f[n]*rev[n-k]*rev[k];}
    mint h(int n,int r){return n<0||r<0?0:c(n+r-1,r);}
};