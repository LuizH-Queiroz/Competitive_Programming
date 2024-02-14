/*
You have an empty sequence A. There are Q queries given, and you need to process them in the order they are given.
The queries are of the following two types:

    1 x: Append x to the end of A.
    2 k: Find the k-th value from the end of A. It is guaranteed that the length of A is at least k when this query 
    is given.

Constraints

1≤Q≤100

In the first type of query,
x is an integer satisfying

1≤x≤109.

In the second type of query, k is a positive integer not greater than the current length of sequence A.
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



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    int q;
    vector<int> vec;
    int type, val, index;

    
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        cin >> type;

        if (type  == 1)
        {
            cin >> val;
            vec.pb(val);
        }
        else
        {
            cin >> index;
            cout << vec[vec.size()-index] << endl;
        }
    }


    return 0;
}