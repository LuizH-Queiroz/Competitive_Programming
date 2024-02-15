/* https://codeforces.com/contest/1929/problem/C */
/*
Sasha decided to give his girlfriend the best handbag, but unfortunately for Sasha, it is very expensive.
Therefore, Sasha wants to earn it. After looking at earning tips on the internet, he decided to go to the casino.

Sasha knows that the casino operates under the following rules. If Sasha places a bet of y
coins (where y is a positive integer), then in case of winning, he will receive y⋅k coins (i.e., his number of
coins will increase by y⋅(k−1)). And in case of losing, he will lose the entire bet amount (i.e., his number of
coins will decrease by y).

Note that the bet amount must always be a positive (>0) integer and cannot exceed Sasha's current number of coins.

Sasha also knows that there is a promotion at the casino: he cannot lose more than xtimes in a row.

Initially, Sasha has a
coins. He wonders whether he can place bets such that he is guaranteed to win any number of coins. In other words,
is it true that for any integer n, Sasha can make bets so that for any outcome that does not contradict the rules
described above, at some moment of time he will have at least ncoins.


Input

Each test consists of multiple test cases. The first line contains a single integer t
(1≤t≤1000) — the number of test cases. The description of the test cases follows.

The single line of each test case contains three integers k,x
and a (2≤k≤30, 1≤x≤100, 1≤a≤109) — the number of times the bet is increased in case of a win, the maximum number
of consecutive losses, and the initial number of coins Sasha has.


Output

For each test case, output "YES" (without quotes) if Sasha can achieve it and "NO" (without quotes) otherwise.

You can output "YES" and "NO" in any case (for example, the strings "yEs", "yes" and "Yes" will be recognized as
a positive answer).
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


bool canWin(ll x, ll mult, ll init) {
    ll bet = 1;
    ll add = 1;

    for (int i = 2; i <= x; i++)
    {
        // add * (mult-1) > bet
        add = bet/(mult-1)+1;

        bet += add;

        if (bet >= init)
        {
            return false;
        }
    }

    return (init-bet)*(mult-1) > bet;
}



int main() {
    ios::sync_with_stdio(0);
    // cin.tie(0);
    ////////////////////////
    int t;

    cin >> t;

    while(t--)
    {
        ll mult, x, init;

        cin >> mult >> x >> init;

        if (canWin(x, mult, init)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }




    return 0;
}