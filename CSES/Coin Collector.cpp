/*
A game has n rooms and m tunnels between them. Each room has a certain number of coins. What is the maximum number of
coins you can collect while moving through the tunnels when you can freely choose your starting and ending room?

Input
The first input line has two integers n and m: the number of rooms and tunnels. The rooms are numbered 1,2,\dots,n.
Then, there are n integers k_1,k_2,\ldots,k_n: the number of coins in each room.
Finally, there are m lines describing the tunnels. Each line has two integers a and b: there is a tunnel from room a
to room b. Each tunnel is a one-way tunnel.

Output
Print one integer: the maximum number of coins you can collect.
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


vector<vector<int>> adj;
vector<vector<int>> rev;
vector<ll> coins;
vector<bool> used;

stack<int> out;
vector<vector<int>> scc;
vector<int> scc_of;
vector<ll> scc_max;
vector<vector<int>> condens; // condensation graph


void dfs(int v) {
    used[v] = true;

    for (int u : adj[v])
    {
        if (!used[u])
        {
            dfs(u);
        }
    }

    out.push(v);
}


void rev_dfs(int v) {
    used[v] = true;
    scc.back().pb(v);
    scc_of[v] = scc.size()-1;

    for (int u : rev[v])
    {
        if (!used[u])
        {
            rev_dfs(u);
        }
    }
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    int n, m;
    int a, b;


    cin >> n >> m;

    adj.resize(n+1);
    rev.resize(n+1);
    scc_of.resize(n+1);
    scc_max.resize(n+1);
    condens.resize(n+1);
    coins.resize(n+1);
    used.resize(n+1, false);

    for (int i = 1; i <= n; i++)
    {
        cin >> coins[i];
    }

    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;

        adj[a].pb(b);
        rev[b].pb(a);
    }

    ///////////////////////

    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
        {
            dfs(i);
        }
    }

    fill(all(used), false);
    scc.emplace_back(); // index 0 will not be used
    while(!out.empty())
    {
        if (!used[out.top()])
        {
            scc.emplace_back();
            rev_dfs(out.top());
        }

        out.pop();
    }

    ll ans = 0;
    for (int i = scc.size()-1; i >= 1; i--)
    {
        ll tempMax = 0;
        scc_max[i] = 0;

        for (int v : scc[i])
        {
            scc_max[i] += coins[v];
            for (int u : adj[v])
            {
                if (scc_of[v] != scc_of[u])
                {
                    condens[scc_of[v]].pb(scc_of[u]);
                    tempMax = max(tempMax, scc_max[scc_of[u]]);
                }
            }
        }

        scc_max[i] += tempMax;
        ans = max(ans, scc_max[i]);
    }

    cout << ans << endl;


    return 0;
}