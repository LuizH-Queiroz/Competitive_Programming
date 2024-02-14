/* https://atcoder.jp/contests/arc165/tasks/arc165_a */
/*
You are given a positive integer N.

Determine if there are two or more (not necessarily distinct) positive integers

A1​,A2​,…,An​ (2≤n) that satisfy all of the following conditions:

A1​+A2​+⋯+An​=N.

The least common multiple of
A1​,A2​,…,An​ is N.

You have T test cases to solve.

Constraints

1≤T≤100
2≤N≤109
All input values are integers.
*/
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


vector<ll> trial_division1(ll n) {
    vector<ll> factorization;
    for (ll d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    int t;
    ll n;

    cin >> t;

    while(t--)
    {
        cin >> n;

        vector<ll> fact = trial_division1(n);
        bool diff = false;

        for (int i = 1; i < fact.size(); i++)
        {
            if (fact[i] != fact[i-1])
            {
                diff = true;
                break;
            }
        }

        if (fact.size() > 1 && diff) cout << "Yes" << endl;
        else cout << "No" << endl;
    }


    return 0;
}