/*
Given an array of n integers, your task is to process q queries of the following types:

update the value at position k to u
what is the sum of values in range [a,b]?

Input
The first input line has two integers n and q: the number of values and queries.
The second line has n integers x_1,x_2,\dots,x_n: the array values.
Finally, there are q lines describing the queries. Each line has three integers: either "1 k u" or "2 a b".

Output
Print the result of each query of type 2.
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


vector<ll> vec;
ll block[700]; // decomposed array
ll blk_sz; // block size


void update(int idx, int val)
{
    int blockNumber = idx / blk_sz;
    block[blockNumber] += val - vec[idx];
    vec[idx] = val;
}
 
// Time Complexity : O(sqrt(n))
ll query(int l, int r)
{
    ll sum = 0;
    while (l < r and l % blk_sz != 0 and l != 0) {
        // traversing first block in range
        sum += vec[l];
        l++;
    }
    while (l + blk_sz - 1 <= r) {
        // traversing completely overlapped blocks in range
        sum += block[l / blk_sz];
        l += blk_sz;
    }
    while (l <= r) {
        // traversing last block in range
        sum += vec[l];
        l++;
    }
    return sum;
}
 
void preprocess(int n)
{
    // initiating block pointer
    int blk_idx = -1;
 
    // calculating size of block
    blk_sz = sqrt(n);
 
    // building the decomposed array
    for (int i = 0; i < n; i++) {
        if (i % blk_sz == 0) {
            // entering next block
            // incrementing block pointer
            blk_idx++;
        }
        block[blk_idx] += vec[i];
    }
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    ll n, q;
    ll type;
    ll k, u;
    ll a , b;


    cin >> n >> q;

    vec.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    preprocess(n);
    for (int i = 0; i < q; i++)
    {
        cin >> type;

        if (type == 1)
        {
            cin >> k >> u;
            update(k-1, u);
        }
        else
        {
            cin >> a >> b;
            cout << query(a-1, b-1) << endl;
        }
    }


    return 0;
}