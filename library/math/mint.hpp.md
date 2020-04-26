---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: math/mint.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/mint.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 13:41:02+09:00




## Depends on

* :heavy_check_mark: <a href="../template/template.hpp.html">template/template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/mint.hpp"

#line 1 "template/template.hpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pl;
typedef vector<pl> vp;
const ll INF=1001001001;
const ll LINF=1001001001001001001;
const ll D4[]={0,1,0,-1,0};
const ll D8[]={0,1,1,0,-1,-1,1,-1,0};
#define _overload3(_1,_2,_3,name,...) name
#define _rep2(i,n) for(ll i=0;i<(n);++i)
#define _rep3(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(...) _overload3(__VA_ARGS__,_rep3,_rep2)(__VA_ARGS__)
#define _repe2(i,n) for(ll i=0;i<=(n);++i)
#define _repe3(i,a,b) for(ll i=(a);i<=(b);++i)
#define repe(...) _overload3(__VA_ARGS__,_repe3,_repe2)(__VA_ARGS__)
#define _rrep2(i,n) for(ll i=(n)-1;i>=0;i--)
#define _rrep3(i,a,b) for(ll i=(b)-1;i>=(a);i--)
#define rrep(...) _overload3(__VA_ARGS__,_rrep3,_rrep2)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
template<class T>
bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>
bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
template<class T>
using pq=priority_queue<T,vector<T>,greater<T>>;
#line 3 "math/mint.hpp"
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

