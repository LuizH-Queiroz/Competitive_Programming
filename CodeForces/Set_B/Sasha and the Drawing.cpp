/* https://codeforces.com/contest/1929/problem/B */
/*
Even in kindergarten, Sasha liked a girl. Therefore, he wanted to give her a drawing and attract her attention.

As a drawing, he decided to draw a square grid of size n×n, in which some cells are colored. But coloring the
cells is difficult, so he wants to color as few cells as possible. But at the same time, he wants
at least k diagonals to have at least one colored cell. Note that the square grid of size n×n has a total
of 4n−2 diagonals.

Help little Sasha to make the girl fall in love with him and tell him the minimum number of cells he needs to color.


Input

Each test consists of multiple test cases. The first line contains a single integer t (1≤t≤1000) — the number
of test cases. The description of the test cases follows.

The only line of each test case contains two integers n
and k (2≤n≤108, 1≤k≤4n−2) — the size of the square grid and the minimum number of diagonals in which there should
be at least one colored cell.


Output

For each test case, output a single integer — the minimum number of cells that need to be colored.
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


bool isOdd(ll n) {
    return (n&1) == 1;
} 



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    int t;

    cin >> t;

    while(t--)
    {
        ll n, k;
        ll pairs = 0;
        ll ans = 0;

        cin >> n >> k;

        pairs = 2*n - 2;
        // debug(pairs);
        if (k <= 2*pairs)
        {
            if (isOdd(k))
            {
                k++;
            }
            ans = k/2;
        }
        else
        {
            ans += pairs;
            k -= 2*pairs;

            ans += k;
        }

        cout << ans << endl;
    }




    return 0;
}