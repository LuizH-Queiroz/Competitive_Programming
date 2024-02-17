/* https://atcoder.jp/contests/abc341/tasks/abc341_f */
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


vector<vector<ll>> adj;

vector<ll> weight;
vector<ll> initPieces;

vector<vector<ll>> dp;
vector<ll> fromDP;


ll solve(vector<ll>& vec, ll index, ll wleft) {
    if (index == vec.size())
    {
        return 0LL;
    }
    else if (dp[index][wleft] != -1)
    {
        return dp[index][wleft];
    }

    ll ans = solve(vec, index+1, wleft);
    if (wleft-weight[vec[index]] > 0)
    {
        ans = max(ans, fromDP[vec[index]] + solve(vec, index+1, wleft-weight[vec[index]]));
    }

    return dp[index][wleft] = ans;
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    ll n, m;
    ll a, b;
    priority_queue<pll, vector<pll>, greater<pll>> pq;


    cin >> n >> m;

    adj.resize(n+1);
    weight.resize(n+1);
    initPieces.resize(n+1);
    fromDP.resize(n+1);

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> weight[i];
        pq.push({weight[i], i});
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> initPieces[i];
    }

    while(!pq.empty())
    {
        ll vertex = pq.top().second;
        pq.pop();

        dp = vector<vector<ll>>(adj[vertex].size()+2, vector<ll>(weight[vertex]+2, -1));
        fromDP[vertex] = 1 + solve(adj[vertex], 0, weight[vertex]);
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += initPieces[i] * fromDP[i];
    }

    cout << ans << endl;


    return 0;
}