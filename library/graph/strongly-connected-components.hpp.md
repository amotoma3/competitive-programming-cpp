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


# :heavy_check_mark: graph/strongly-connected-components.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/strongly-connected-components.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 18:10:23+09:00




## Depends on

* :heavy_check_mark: <a href="../template/graph-template.hpp.html">template/graph-template.hpp</a>
* :heavy_check_mark: <a href="../template/template.hpp.html">template/template.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/strongly-connected-components.test.cpp.html">test/strongly-connected-components.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef ONLINE_JUDGE
#include "../template/template.hpp"
#include "../template/graph-template.hpp"
#endif

template<typename G>
struct StronglyConnectedComponents{
    const G &g;
    vvl gg,rg,bg,ms;
    vl gid,ord;
    vector<bool> used;

    StronglyConnectedComponents(G &g):g(g),gg(g.size()),rg(g.size()),gid(g.size(),-1),used(g.size()){
        rep(i,g.size())for(auto &to:g[i]){
            gg[i].push_back(to);
            rg[to].push_back(i);
        }
        build();
    }
    int operator[](int k){return gid[k];}
    vvl get_graph(){return bg;}
    vl get_members(int id){return ms[id];}

private:
    void dfs(int x){
        if(used[x])return;
        used[x]=true;
        for(ll to:gg[x])dfs(to);
        ord.push_back(x);
    }
    void rdfs(int x,int id){
        if(gid[x]!=-1)return;
        gid[x]=id;
        for(ll to:rg[x])rdfs(to,id);
    }
    void build(){
        rep(i,gg.size())dfs(i);
        reverse(all(ord));
        int id=0;
        for(int i:ord)if(gid[i]==-1)rdfs(i,id),++id;

        bg.resize(id);
        ms.resize(id);
        rep(i,g.size()){
            for(auto &to:g[i]){
                if(gid[i]!=gid[to])bg[gid[i]].push_back(gid[to]);
            }
            ms[gid[i]].push_back(i);
        }
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 340, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 170, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 281, in update
    raise BundleError(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: graph/strongly-connected-components.hpp: line 3: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

