/*
Byteland has n cities and m roads between them. Your task is to design a round trip that begins in a city, goes
through two or more other cities, and finally returns to the starting city. Every intermediate city on the route
has to be distinct.

Input
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,\dots,n.
Then, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
Every road is between two different cities, and there is at most one road between any two cities.

Output
First print an integer k: the number of cities on the route. Then print k cities in the order they will be visited.
You can print any valid solution.
If there are no solutions, print "IMPOSSIBLE".
*/
#include <bits/stdc++.h>
 
#define endl '\n'
 
using namespace std;
 
 
vector<vector<int>> adjacencyList;
vector<int> depth;
vector<bool> visited;
stack<int> stk;
 
 
bool dfs(int vertex, int parent) {
    visited[vertex] = true;
    stk.push(vertex);
 
    for (int adjacent : adjacencyList[vertex])
    {
        if (!visited[adjacent])
        {
            depth[adjacent] = depth[vertex]+1;
            if (dfs(adjacent, vertex))
            {
                return true;
            }
        }
        else if (adjacent != parent) // visited[adjacent]
        {
            cout << (depth[vertex] - depth[adjacent] + 2) << endl;
            while(stk.top() != adjacent)
            {
                cout << stk.top() << " ";
                stk.pop();
            }
            cout << stk.top() << " " << vertex << endl;
 
            return true;
        }
    }
 
    stk.pop();
    return false;
}
 
 
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    int numVertices;
    int numEdges;
    int v1, v2;
 
 
    cin >> numVertices >> numEdges;
 
    adjacencyList.resize(numVertices+1);
    depth.resize(numVertices+1);
    visited.resize(numVertices+1);
 
    for (int i = 0; i < numEdges; i++)
    {
        cin >> v1 >> v2;
        adjacencyList[v1].push_back(v2);
        adjacencyList[v2].push_back(v1);
    }
 
 
    bool finished = false;
    for (int i = 1; i <= numVertices; i++)
    {
        if (!visited[i])
        {
            depth[i] = 0;
            if (dfs(i, -1))
            {
                finished = true;
                break;
            }
        }
    }
 
    if (!finished)
    {
        cout << "IMPOSSIBLE" << endl;
    }
 
 
    return 0;
}