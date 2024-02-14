/*
Takahashi is playing a game.

The game consists of
N stages numbered 1,2,…,N. Initially, only stage

1 can be played.

For each stage
i ( 1≤i≤N−1 ) that can be played, you can perform one of the following two actions at stage i:

Spend Ai​ seconds to clear stage i. This allows you to play stage i+1.
Spend Bi​ seconds to clear stage i. This allows you to play stage Xi​.

Ignoring the times other than the time spent to clear the stages, how many seconds will it take at the minimum to
be able to play stage N?

Constraints

2≤N≤2×105
1≤Ai​,Bi​≤109
1≤Xi​≤N

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

const ll MOD = 10e9 + 7;
const ll MOD_FFT = 998'244'353;

const ll PRIME_HASH1 = 31;
const ll PRIME_HASH2 = 37;

using namespace std;


int n;
vector<vector<pll>> adj;
vector<bool> used;

typedef pair<ll, ll> pqType;
priority_queue<pqType, vector<pqType>, greater<pqType>> pq;


ll dijkstra() {

    pq.push({0, 1});
    while(!pq.empty())
    {
        ll currCost = pq.top().first;
        ll v = pq.top().second;
        pq.pop();

        if (v == n)
        {
            return currCost;
        }
        else if (used[v])
        {
            continue;
        }
        used[v] = true;

        for (pll& it : adj[v])
        {
            ll u = it.first;
            ll cost = it.second;

            if (!used[u])
            {
                pq.push({currCost + cost, u});
            }
        }
    }

    return -1;
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    int a, b, x;


    cin >> n;

    adj.resize(n+1);
    used.resize(n+1, false);

    for (int i = 1; i < n; i++)
    {
        cin >> a >> b >> x;

        adj[i].pb({i+1, a});
        adj[i].pb({x, b});
    }

    cout << dijkstra() << endl;


    return 0;
}