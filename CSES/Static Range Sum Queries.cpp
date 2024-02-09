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

const ll MOD = 10e9 + 7;
const ll MOD_FFT = 998'244'353;

const ll PRIME_HASH1 = 31;
const ll PRIME_HASH2 = 37;

using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    ll n, q;
    ll l, r;
    vector<ll> vec;


    cin >> n >> q;

    vec.resize(n+1);

    vec[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> vec[i];
        vec[i] += vec[i-1];
    }

    for (int i = 1; i <= q; i++)
    {
        cin >> l >> r;

        cout << (vec[r] - vec[l-1]) << endl;
    }


    return 0;
}