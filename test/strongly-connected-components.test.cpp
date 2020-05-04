#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C"
#define TEMPLATE_USED
#include "../template/template.hpp"
#include "../template/graph-template.hpp"
#include "../graph/strongly-connected-components.hpp"

int main() {
    ll v,e;cin>>v>>e;
    Graph<ll> g(v);
    rep(i,e){
        ll s,t;cin>>s>>t;
        g[s].emplace_back(t,1);
    }

    StronglyConnectedComponents<Graph<ll>> scc(g);
    ll q;cin>>q;
    rep(i,q){
        ll u,w;cin>>u>>w;
        cout<<(scc[u]==scc[w]?1:0)<<endl;
    }
}
