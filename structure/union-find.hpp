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
