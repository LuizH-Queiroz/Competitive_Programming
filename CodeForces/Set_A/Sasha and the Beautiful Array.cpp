/* https://codeforces.com/contest/1929/problem/A */
/*
Sasha decided to give his girlfriend an array a1,a2,…,an. He found out that his girlfriend evaluates the beauty
of the array as the sum of the values (ai−ai−1) for all integers i from 2 to n.

Help Sasha and tell him the maximum beauty of the array a

that he can obtain, if he can rearrange its elements in any way.
Input

Each test consists of multiple test cases. The first line contains a single integer t
(1≤t≤500) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer n
(2≤n≤100) — the length of the array a.

The second line of each test case contains n
integers a1,a2,…,an (1≤ai≤109) — the elements of the array a.


Output

For each test case, output a single integer — the maximum beauty of the array a
that can be obtained.
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



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    int t;

    cin >> t;

    while(t--)
    {
        ll n;
        vector<ll> vec;

        cin >> n;

        vec.resize(n);

        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }
        sort(all(vec));

        ll sum = 0;
        for (int i = 1; i < vec.size(); i++)
        {
            sum += vec[i] - vec[i-1];
        }

        cout << sum << endl;
    }




    return 0;
}