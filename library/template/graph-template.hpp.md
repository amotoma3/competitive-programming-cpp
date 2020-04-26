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


# :heavy_check_mark: template/graph-template.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#66f6181bcb4cff4cd38fbc804a036db6">template</a>
* <a href="{{ site.github.repository_url }}/blob/master/template/graph-template.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 18:06:28+09:00




## Required by

* :heavy_check_mark: <a href="../graph/strongly-connected-components.hpp.html">graph/strongly-connected-components.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/strongly-connected-components.test.cpp.html">test/strongly-connected-components.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template<typename T>
struct edge{
    int src,to;
    T cost;
    edge(int from,int to,T cost):src(src),to(to),cost(cost){}
    edge(int to,T cost):edge(-1,to,cost){}
    operator int()const{return to;}
};

template<typename T>
using Edges=vector<edge<T>>;

template<typename T>
using Graph=vector<Edges<T>>;

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "template/graph-template.hpp"
template<typename T>
struct edge{
    int src,to;
    T cost;
    edge(int from,int to,T cost):src(src),to(to),cost(cost){}
    edge(int to,T cost):edge(-1,to,cost){}
    operator int()const{return to;}
};

template<typename T>
using Edges=vector<edge<T>>;

template<typename T>
using Graph=vector<Edges<T>>;

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

