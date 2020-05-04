#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"
#define TEMPLATE_USED
#include "../template/template.hpp"
#include "../structure/binary-indexed-tree.hpp"

int main() {
  int N, Q;
  cin >> N >> Q;
  BinaryIndexedTree bit(N);
  while(Q--) {
    int T, X, Y;
    cin >> T >> X >> Y;
    if(T)cout << bit.sum(X-1,Y-1) << "\n";
    else bit.add(X-1,Y);
  }
}
