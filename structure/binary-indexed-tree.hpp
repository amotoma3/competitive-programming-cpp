#ifndef ONLINE_JUDGE
#include "../template/template.hpp"
#endif

struct BinaryIndexedTree {
    int sz;
    vector<ll> data;

    BinaryIndexedTree(int sz):sz(sz){
        data.assign(sz,0);
    }

    void add(int x,int val){
        while(x<sz)data[x]+=val,x|=x+1;
    }

    ll sum(int to){
        to=min(to,sz-1);
        ll ret=0;
        while(to>=0)ret+=data[to],to=(to&(to+1))-1;
        return ret;
    }

    ll sum(int from,int to){
        if(from>to)return 0;
        return sum(to)-sum(from-1);
    }
};