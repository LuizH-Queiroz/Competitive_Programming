/*
Given a sequence of n numbers a1, a2, ..., an and a number of d-queries. A d-query is a pair (i, j) (1 ≤ i ≤ j ≤ n).
For each d-query (i, j), you have to return the number of distinct elements in the subsequence ai, ai+1, ..., aj.
Input

    Line 1: n (1 ≤ n ≤ 30000).
    Line 2: n numbers a1, a2, ..., an (1 ≤ ai ≤ 106).
    Line 3: q (1 ≤ q ≤ 200000), the number of d-queries.
    In the next q lines, each line contains 2 numbers i, j representing a d-query (1 ≤ i ≤ j ≤ n).

Output

    For each d-query (i, j), print the number of distinct elements in the subsequence ai, ai+1, ..., aj in a single line.

Example

Input
5
1 1 2 1 3
3
1 5
2 4
3 5

Output
3
2
3 
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


//////////////////////////////////////////////////////////////////////
const int MAX_VAL = 1'000'000;
vector<int> freq;
vector<int> vec;
int counter = 0;

// TODO: remove value at index from data structure
void remove(int index) {
    freq[vec[index]]--;
    if (freq[vec[index]] == 0)
    {
        counter--;
    }
}


// TODO: add value at index from data structure
void add(int index) {
    if (freq[vec[index]] == 0)
    {
        counter++;
    }
    freq[vec[index]]++;
}


// TODO: extract the current answer of the data structure
int get_answer() {
    return counter;
}

const int block_size = 170;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

vector<Query> queries;
vector<int> ans;
void mo_s_algorithm() {
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure
    freq.resize(MAX_VAL+1, 0);

    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        // debug(q.idx);
        // debug2(q.l, q.r);
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        ans[q.idx] = get_answer();
        // debug(ans[q.idx]);
        // cout << endl;
    }
}
//////////////////////////////////////////////////////////////////////



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    int n, q;
    Query query;


    cin >> n;

    vec.resize(n);

    for (int i = 0; i < vec.size(); i++)
    {
        cin >> vec[i];
    }

    cin >> q;

    queries.resize(q);
    ans.resize(q);

    for (int i = 0; i < queries.size(); i++)
    {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--;
        queries[i].r--;
        queries[i].idx = i;
    }

    mo_s_algorithm();
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }


    return 0;
}