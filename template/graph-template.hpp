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
