/*
You are given a weighted undirected graph. The vertices are enumerated from 1 to n.
Your task is to find the shortest path between the vertex 1 and the vertex n.

Input
The first line contains two integers n and m (2 ≤ n ≤ 105, 0 ≤ m ≤ 105), where n is the number of
vertices and m is the number of edges. Following m lines contain one edge each in
form ai, bi and wi (1 ≤ ai, bi ≤ n, 1 ≤ wi ≤ 106), where ai, bi are edge endpoints and wi is the length of
the edge.

It is possible that the graph has loops and multiple edges between pair of vertices.

Output
Write the only integer -1 in case of no path. Write the shortest path in opposite case.
If there are many solutions, print any of them.
*/
#include <bits/stdc++.h>

#define endl "\n"

using namespace std;


vector<vector<pair<int, int>>> adjacencyList;
vector<bool> visited;
vector<long long> dist;
vector<int> parent;


string dijkstra(int start, int destination) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    int vertice;

    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty())
    {
        vertice = pq.top().second;
        if (visited[vertice])
        {
            pq.pop();
            continue;
        }

        if (vertice == destination)
            break;

        visited[vertice] = true;
        pq.pop();

        for (pair<int, int> adjacent : adjacencyList[vertice])
        {
            if ((dist[vertice] + adjacent.first) < dist[adjacent.second])
            {
                pq.push({dist[vertice] + adjacent.first, adjacent.second});

                dist[adjacent.second] = dist[vertice] + adjacent.first;
                parent[adjacent.second] = vertice;
            }
        }
    }


    vector<int> path;
    if (parent[destination] == -1)
    {
        path.push_back(-1);
    }
    else
    {
        path.push_back(destination);
        vertice = destination;
        while(parent[vertice] != -1)
        {
            path.push_back(parent[vertice]);
            vertice = parent[vertice];
        }
    }


    string ans;
    ans = to_string(path.back());
    for (int i = path.size()-2; i >= 0; i--)
    {
        ans += " " + to_string(path[i]);
    }


    return ans;
}


int main() {
    ios::sync_with_stdio(0);
    //////////////////////////
    int numVertices, numEdges;
    int v1, v2, weight;


    cin >> numVertices >> numEdges;

    adjacencyList = vector<vector<pair<int, int>>>(numVertices+1);
    visited = vector<bool>(numVertices+1, false);
    dist = vector<long long>(numVertices+1, LLONG_MAX);
    parent = vector<int>(numVertices+1, -1);
    
    for (int i = 0; i < numEdges; i++)
    {
        cin >> v1 >> v2 >> weight;

        adjacencyList[v1].push_back({weight, v2});
        adjacencyList[v2].push_back({weight, v1});
    }

    cout << dijkstra(1, numVertices) << endl;


    return 0;
}