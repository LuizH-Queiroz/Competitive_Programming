/*
There is a single integer N written on a blackboard.
Takahashi will repeat the following series of operations until all integers not less than 2 are removed from
the blackboard:

    Choose one integer x not less than 2 written on the blackboard.
    Erase one occurrence of x from the blackboard. Then, write two new integers ⌊2x​⌋ and
    ⌈2x​⌉ on the blackboard.
    Takahashi must pay x yen to perform this series of operations.

Here, ⌊a⌋ denotes the largest integer not greater than a, and ⌈a⌉ denotes the smallest integer not less than a.

What is the total amount of money Takahashi will have paid when no more operations can be performed?
It can be proved that the total amount he will pay is constant regardless of the order in which the operations
are performed.

Constraints

2≤N≤1017
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

const ll MOD = 10e9 + 7;
const ll MOD_FFT = 998'244'353;

const ll PRIME_HASH1 = 31;
const ll PRIME_HASH2 = 37;

using namespace std;


map<ll, ll> dp;


ll solve(ll n) {
    if (n <= 1)
    {
        return 0;
    }
    else if (dp.find(n) != dp.end())
    {
        return dp[n];
    }

    return dp[n] = n + solve(floor(n/((ld)2.0))) + solve(ceil(n/((ld)2.0)));
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    ll n;

    cin >> n;

    cout << solve(n) << endl;


    return 0;
}