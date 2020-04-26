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