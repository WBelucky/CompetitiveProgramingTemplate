#include <bits/stdc++.h>
using namespace std;
#define int long long
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

//繰り返し二乗法
int pow_mod(int n,int k,int m)
{
  if( k== 0)
  {
    return 1;
  } else if (k%2 == 1)
  {
    return pow_mod(n,k-1,m) * n % m;
  } else{
    int t = pow_mod(n,k/2,m);
    return t*t % m;
  }
}
int pow_mod2 (int n,int k,int m)
{
  int r = 1;
  for(;k>0;k>>1)
  {
    if(k & 1) r = (r*n)%m;
    n = (n*n)%m;
  }
  return r;
}

signed main()
{
  ios();
  string S;
  cin >> S;
  int l = S.length();
  for(int i = l-2;i>=0;i--){
    if(S[i] == 'W' && S[i+1]=='A')
    {
      S[i] = 'A';
      S[i+1] = 'C';
    }
  }
  cout << S << endl;

}
