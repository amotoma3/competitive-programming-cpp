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


# :heavy_check_mark: structure/union-find.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#07414f4e15ca943e6cde032dec85d92f">structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/structure/union-find.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-14 03:16:06+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/union-find.test.cpp.html">test/union-find.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct UnionFind {
    vector<int> par;

    UnionFind(int sz){
        par.assign(sz+1,-1);
    }

    bool unite(int x,int y){
        x=find(x),y=find(y);
        if(x==y)return false;
        if(par[x]>par[y])swap(x,y);
        par[x]+=par[y];
        par[y]=x;
        return true;
    }

    int find(int x){
        if(par[x]<0)return x;
        return par[x]=find(par[x]);
    }

    int size(int x){
        return -par[find(x)];
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "structure/union-find.hpp"
struct UnionFind {
    vector<int> par;

    UnionFind(int sz){
        par.assign(sz+1,-1);
    }

    bool unite(int x,int y){
        x=find(x),y=find(y);
        if(x==y)return false;
        if(par[x]>par[y])swap(x,y);
        par[x]+=par[y];
        par[y]=x;
        return true;
    }

    int find(int x){
        if(par[x]<0)return x;
        return par[x]=find(par[x]);
    }

    int size(int x){
        return -par[find(x)];
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

