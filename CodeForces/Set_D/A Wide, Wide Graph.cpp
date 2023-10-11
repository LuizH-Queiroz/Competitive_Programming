/*
You are given a tree (a connected graph without cycles) with n vertices.

Consider a fixed integer k. Then, the graph Gk is an undirected graph with n vertices, where an edge
between vertices u and v exists if and only if the distance between vertices u and v in the given tree
is at least k.

For each k from 1 to n, print the number of connected components in the graph Gk.

Input
The first line contains the integer n (2≤n≤105) — the number of vertices in the graph.

Each of the next n−1 lines contains two integers u and v (1≤u,v≤n), denoting an edge between
vertices u and v in the tree. It is guaranteed that these edges form a valid tree.

Output
Output n integers: the number of connected components in the graph Gk for each k from 1 to n.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define endl '\n'

using namespace std;


vector<vector<int>> adjacencyList;
vector<bool> visited;


pair<int, int> findOutmost(int node, int level) {
    visited[node] = true;

    pair<int, int> outmost(node, level);
    pair<int, int> temp;
    for (int adjacent : adjacencyList[node])
    {
        if (!visited[adjacent])
        {
            temp = findOutmost(adjacent, level+1);
            if (temp.second > outmost.second)
            {
                outmost = temp;
            }
        }
    }

    return outmost;
}


void buildLevelList(vector<vector<int>>& list, int node, int level) {
    visited[node] = true;
    list[level].push_back(node);

    for (int adjacent : adjacencyList[node])
    {
        if (!visited[adjacent])
        {
            buildLevelList(list, adjacent, level+1);
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    //////////////////////////
    int numVertices;
    int v1, v2;

    vector<vector<int>> levelFrom_A;
    vector<vector<int>> levelFrom_B;


    cin >> numVertices;

    adjacencyList.resize(numVertices+1);
    visited.resize(numVertices+1);
    levelFrom_A.resize(numVertices+1);
    levelFrom_B.resize(numVertices+1);

    for (int i = 0; i < (numVertices-1); i++)
    {
        cin >> v1 >> v2;

        adjacencyList[v1].push_back(v2);
        adjacencyList[v2].push_back(v1);
    }


    // Outmosts vertices
    int outmostA, outmostB;

    // Finding A and creating its list
    fill(visited.begin(), visited.end(), false);
    outmostA = findOutmost(1, 0).first;
    fill(visited.begin(), visited.end(), false);
    buildLevelList(levelFrom_A, outmostA, 0);
    
    // Finding B and creating its list
    fill(visited.begin(), visited.end(), false);
    outmostB = findOutmost(outmostA, 0).first;
    fill(visited.begin(), visited.end(), false);
    buildLevelList(levelFrom_B, outmostB, 0);


    int components = numVertices;
    vector<int> ans(numVertices+1);

    fill(visited.begin(), visited.end(), false);
    visited[outmostA] = true;
    for (int k = numVertices; k >= 1; k--)
    {
        for (int vertice : levelFrom_A[k])
        {
            if (!visited[vertice])
            {
                components--;
                visited[vertice] = true;
            }
        }
        for (int vertice : levelFrom_B[k])
        {
            if (!visited[vertice])
            {
                components--;
                visited[vertice] = true;
            }
        }

        ans[k] = components;
    }


    cout << ans[1];
    for (int k = 2; k <= numVertices; k++)
    {
        cout << " " << ans[k];
    }
    cout << endl;


    return 0;
}