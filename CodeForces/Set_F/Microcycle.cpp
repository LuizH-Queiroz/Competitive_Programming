#include <bits/stdc++.h>

#define endl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()

#define pii pair<int, int>
#define pll pair<ll, ll>

typedef long long ll;

const ll MOD = 10e9 + 7;

using namespace std;


vector<vector<pii>> adj;
vector<int> inTime;
vector<int> low;
vector<bool> used;
int timer = 0;

set<pii> bridges;
stack<int> stk;
int minCost;

typedef pair<int, pii> pqType;
priority_queue<pqType, vector<pqType>, greater<pqType>> pq;


void dfs(int v, int parent) {
    used[v] = true;
    inTime[v] = ++timer;

    low[v] = inTime[v];
    for (pii& it : adj[v])
    {
        int u = it.first;
        int cost = it.second;

        if (!used[u])
        {
            dfs(u, v);
            low[v] = min(low[v], low[u]);
        }
        else if (u != parent)
        {
            low[v] = min(low[v], inTime[u]);
        }
    }

    if (low[v] == inTime[v] && parent != -1)
    {
        bridges.insert({v, parent});
        bridges.insert({parent, v});
    }
}


bool dfs2(int v, int parent, int target) {
    used[v] = true;
    stk.push(v);
    
    for (pii& it : adj[v])
    {
        int u = it.first;
        int cost = it.second;
        if (bridges.find({v, u}) != bridges.end())
        {
            continue;
        }

        if (u == target && u != parent)
        {
            cout << minCost << " " << stk.size() << endl;

            while(!stk.empty())
            {
                cout << stk.top() << " ";
                stk.pop();
            }
            cout << endl;
            return true;
        }
        else if (!used[u])
        {
            if (dfs2(u, v, target))
            {
                return true;
            }
        }
    }

    stk.pop();
    return false;
}


void solve() {
    fill(all(used), false);

    while(!pq.empty())
    {
        minCost = pq.top().first;
        int a = pq.top().second.first;
        int b = pq.top().second.second;
        pq.pop();

        if (!used[a] && bridges.find({a, b}) == bridges.end())
        {
            used[a] = true;
            stk.push(a);
            if (dfs2(b, a, a))
            {
                return;
            }
            stk.pop();
        }
    }
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    int t;
    int n, m;
    int a, b, w;


    cin >> t;
    while(t--)
    {
        cin >> n >> m;

        adj.resize(n+1);
        used.resize(n+1, false);
        inTime.resize(n+1);
        low.resize(n+1);

        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> w;

            adj[a].pb({b, w});
            adj[b].pb({a, w});

            pq.push({w, {a, b}});
        }

        // Find bridges
        for (int i = 1; i <= n; i++)
        {
            if (!used[i])
            {
                dfs(i, -1);
            }
        }

        // for (const pii& it : bridges)
        // {
        //     cout << it.first << " " << it.second << endl;
        // }

        // cout << "BEFORE" << endl;
        solve();
        // cout << "AFTER" << endl;

        ////////////////////
        adj.clear();
        used.clear();
        inTime.clear();
        low.clear();
        bridges.clear();
        while(!stk.empty())
        {
            stk.pop();
        }
        while(!pq.empty())
        {
            pq.pop();
        }
    }


    return 0;
}