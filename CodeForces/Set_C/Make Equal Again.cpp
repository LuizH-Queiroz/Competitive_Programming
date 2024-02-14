/* https://codeforces.com/contest/1931/problem/C */
/*
You have an array a of n integers.

You can no more than once apply the following operation: select three integers i, j, x (1≤i≤j≤n) and assign
all elements of the array with indexes from i to j the value x.
The price of this operation depends on the selected indices and is equal to (j−i+1) burles.

For example, the array is equal to [1,2,3,4,5,1]. If we choose i=2,j=4,x=8, then after applying this operation,
the array will be equal to [1,8,8,8,5,1].

What is the least amount of burles you need to spend to make all the elements of the array equal?
Input

The first line contains a single integer t
(1≤t≤104) — the number of input test cases. The descriptions of the test cases follow.

The first line of the description of each test case contains a single integer n
(1≤n≤2⋅105) — the size of the array.

The second line of the description of each test case contains n
integers a1,a2,…,an (1≤ai≤n) — array elements.

It is guaranteed that the sum of n
for all test cases does not exceed 2⋅105.


Output

For each test case, output one integer — the minimum number of burles that will have to be spent to make all the
elements of the array equal. It can be shown that this can always be done.
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
        ll fromLeft, fromRight;
        vector<ll> vec;

        cin >> n;

        vec.resize(n);

        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }

        fromLeft = 1;
        fromRight = 1;
        for (int i = 1; i < vec.size(); i++)
        {
            if (vec[i] != vec[i-1])
            {
                break;
            }
            fromLeft++;
        }
        for (int i = vec.size()-2; i >= 0; i--)
        {
            if (vec[i] != vec[i+1])
            {
                break;
            }
            fromRight++;
        }

        ll ans;
        if (vec[0] != vec.back()) ans = n - max(fromLeft, fromRight);
        else ans = max(0LL, n - (fromLeft + fromRight));

        cout << ans << endl;
    }




    return 0;
}