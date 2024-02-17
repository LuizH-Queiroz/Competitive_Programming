/* https://atcoder.jp/contests/abc341/tasks/abc341_d */
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
    ll n, m, k;


    cin >> n >> m >> k;

    ll left = 1;
    ll right = 1e18;

    ll ans = -1;
    while(left <= right)
    {
        ll val = (left + right) / 2;
        ll counter = val/n + val/m - 2*(val/lcm(n, m));

        if (counter == k)
        {
            ans = val;
            right = val-1;
        }
        else if (counter < k)
        {
            left = val+1;
        }
        else // counter > k
        {
            right = val-1;
        }
    }

    cout << ans << endl;


    return 0;
}