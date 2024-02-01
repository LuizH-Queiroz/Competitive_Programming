/*
There are n cities and m flight connections. Your task is to check if you can travel from any city to any other city
using the available flights.

Input
The first input line has two integers n and m: the number of cities and flights. The cities are numbered 1,2,\dots,n.
After this, there are m lines describing the flights. Each line has two integers a and b: there is a flight from city a
to city b. All flights are one-way flights.

Output
Print "YES" if all routes are possible, and "NO" otherwise. In the latter case also print two cities a and b such that
you cannot travel from city a to city b. If there are several possible solutions, you can print any of them.
*/
#include <bits/stdc++.h>

#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;


vector<bool> visited;


int dfs(int v, vector<vector<int>>& adj) {
    visited[v] = true;

    int counter = 1;
    for (int it : adj[v])
    {
        if (!visited[it])
        {
            counter += dfs(it, adj);
        }
    }

    return counter;
}


int notVisited() {

    for (int i = 1; i < visited.size(); i++)
    {
        if (!visited[i])
        {
            return i;
        }
    }

    return -1;
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    int cities, flights;
    int v1, v2;
    vector<vector<int>> adj;
    vector<vector<int>> rev;


    cin >> cities >> flights;

    adj.resize(cities+1);
    rev.resize(cities+1);
    visited.resize(cities+1, false);

    for (int i = 0; i < flights; i++)
    {
        cin >> v1 >> v2;

        adj[v1].push_back(v2);
        rev[v2].push_back(v1);
    }


    int counterADJ = dfs(1, adj);
    fill(all(visited), false);
    int counterREV = dfs(1, rev);

    if (counterADJ == cities && counterREV == cities)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;

        int noReach = notVisited();
        if (noReach == -1)
        {
            fill(all(visited), false);
            dfs(1, adj);
            noReach = notVisited();

            cout << "1 " << noReach << endl;
        }
        else
        {
            cout << noReach << " 1" << endl;
        }
    }



    return 0;
}