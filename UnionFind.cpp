#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ALL(v) (v).begin(), (v).end()
#define ios() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
constexpr ll MOD = 10e9+7;
constexpr ll INF = 1LL << 60;
constexpr int Inf = 1e9;
inline int in() {int x; cin >> x; return x;}
template <typename T> inline void out(const T& x) {cout << x << endl;}
template <class T> inline bool chmin(T &a, T b){if (a > b){a = b;return 1;}return 0;}
template <class T> inline bool chmax(T &a, T b){if (a < b){a = b;return 1;}return 0;}
//UP = 0;RIGHT = 1; DOWN = 2; LEFT =3;
const int dx[] = {0, 1, 0, -1, 1, -1, 1, -1}, dy[] = {1, 0, -1, 0, 1, -1, -1, 1};
int gcd(int a, int b)
{
  if (a < b)
    gcd(b, a);
  int r;
  while ((r = a % b))
  {
    a = b;
    b = r;
  }
  return b;
}
void eratos(bool * isPrime,int max){
  fill(isPrime,isPrime + max,true);
  isPrime[0] = false; 
  isPrime[1] = false; 
  for(int i=2; i<=max/i; ++i) 
      if(isPrime[i]) 
          for(int j=2; j<=max/i; ++j) 
              isPrime[i*j] = false;    
}
//
//UnionFind譛ｨ
//蜷後§繧ｰ繝ｫ繝ｼ繝励↓螻槭＠縺ｦ縺・ｋ縺九←縺・°繧呈惠縺ｧ陦ｨ縺吶・
//譛ｨ縺ｮ蜷域・縺ｯ邁｡蜊倥↓縺ｧ縺阪ｋ縺後∵ｰ励・蛻・牡縺ｯ縺ｧ縺阪↑縺・

struct UnionFind
{
  vi par;
  vi rank;
  vi sizes;
  //par[i] parent
  UnionFind(int N) : par(N) , rank(N),sizes(N,1)
  {
    //par[i] == i 縺ｪ繧画ｹ
    rep(i,N) par[i] = i,rank[i] = 0;
  }
  int root(int x)
  {
    return par[x] == x ? x : par[x] = root(par[x]);
  }
  //同じグループに含まれているかどうか
  bool same(int x,int y)
  {
    return root(x) == root(y);
  }
  //xとyが含まれる集合を合成。階数rankの高いほうに小さいほうが合成される
  void unite(int x,int y)
  {
    x = root(x);
    y = root(y);
    if(x==y) return ;
    if(rank[x] < rank[y])
    {
      par[x] = y;
      sizes[y] += sizes[x];
    } else {
      par[y] = x;
      sizes[x] += sizes[y];
      if(rank[x]==rank[y])rank[x] ++;
    }

  }
  int size(int x)
  {
    return sizes[root(x)];
  }
};

int A[100010],B[100010],ans[100010];
signed main()
{
  ios();
  int N,M;
  cin >> N >> M;
  UnionFind tree(N);
  rep(i,M) cin >> A[i] >> B[i];
  ans[M-1]= (N*(N-1))/2;
  for(int i = M-2;i>=0;i--)
  {
    if(tree.root(A[i+1]-1) == tree.root(B[i+1] - 1))    {
      ans[i] = ans[i+1];
      continue;
    }
    ans[i] = ans[i+1] - tree.size(A[i]-1) * tree.size(B[i]-1);
    tree.unite(A[i]-1,B[i]-1);
  }
  rep(i,M) cout << ans[i] << endl;

}
