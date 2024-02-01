/*
A game has n planets, connected by m teleporters. Two planets a and b belong to the same kingdom exactly when there is
a route both from a to b and from b to a. Your task is to determine for each planet its kingdom.

Input
The first input line has two integers n and m: the number of planets and teleporters. The planets are numbered
1,2,\dots,n.
After this, there are m lines describing the teleporters. Each line has two integers a and b: you can travel from
planet a to planet b through a teleporter.

Output
First print an integer k: the number of kingdoms. After this, print for each planet a kingdom label between 1 and k.
You can print any valid solution.
*/
#include <bits/stdc++.h>

#define endl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;


vector<vector<int>> adj, rev;
vector<bool> used;
stack<int> out;

vector<int> component;
int currComp = 1;


void dfs(int v) {
    used[v] = true;

    for (int it : adj[v])
    {
        if (!used[it])
        {
            dfs(it);
        }
    }

    out.push(v);
}


void rev_dfs(int v) {
    used[v] = true;
    component[v] = currComp;

    for (int it : rev[v])
    {
        if (!used[it])
        {
            rev_dfs(it);
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
    used.resize(n+1, false);
    component.resize(n+1);

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;

        adj[a].pb(b);
        rev[b].pb(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
        {
            dfs(i);
        }
    }

    fill(all(used), false);
    while(!out.empty())
    {
        while(!out.empty() && used[out.top()])
        {
            out.pop();
        }

        if (!out.empty())
        {
            rev_dfs(out.top());
            out.pop();
            currComp++;
        }
    }

    cout << currComp-1 << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << component[i] << " ";
    }
    cout << endl;


    return 0;
}