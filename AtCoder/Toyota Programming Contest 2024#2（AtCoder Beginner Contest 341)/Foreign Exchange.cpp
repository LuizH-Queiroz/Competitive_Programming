/* https://atcoder.jp/contests/abc341/tasks/abc341_b */
#include <bits/stdc++.h>

#define endl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()

#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << "; " << #y << " = " << y << endl;

#define pii pair<int, int>
#define pll pair<ll, ll>

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll MOD_FFT = 998'244'353;

const ll PRIME_HASH1 = 31;
const ll PRIME_HASH2 = 37;

using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    ll n;
    vector<ll> coins;


    cin >> n;

    coins.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    vector<ll> s, t;

    s.resize(n+1);
    t.resize(n+1);

    for (int i = 0; i < n-1; i++)
    {
        cin >> s[i] >> t[i];
    }

    for (int i = 0; i < n-1; i++)
    {
        coins[i+1] += (coins[i] / s[i]) * t[i];
    }

    cout << coins.back() << endl;


    return 0;
}