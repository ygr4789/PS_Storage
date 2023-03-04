#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll DIV = 998244353;

ll pow(ll x, ll e) {
  if (e == 0) return 1;
  ll ret = pow(x, e / 2);
  ret *= ret;
  ret %= DIV;
  if (e % 2 != 0) ret *= x;
  ret %= DIV;
  return ret;
}

ll inv(ll x) {
  return pow(x, DIV - 2);
}

ll fact(ll n) {
  ll ret = 1;
  for (ll i = 1; i <= n; i++) {
    ret *= i;
    ret %= DIV;
  }
  return ret;
}

ll inv_fact(ll n) {
  ll ret = 1;
  for (ll i = 1; i <= n; i++) {
    ret *= inv(i);
    ret %= DIV;
  }
  return ret;
}