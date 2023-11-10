/*
You are given a rooted tree with the root at vertex 1, initially consisting of a single vertex.
Each vertex has a numerical value, initially set to 0. There are also q queries of two types:

The first type: add a child vertex with the number sz+1 to vertex v, where sz is the current size of
the tree. The numerical value of the new vertex will be 0.
The second type: add x to the numerical values of all vertices in the subtree of vertex v.
After all queries, output the numerical value of all of the vertices in the final tree.

Input
The first line contains a single integer T (1≤T≤104) — the number of test cases. The descriptions of
the test cases follow.

The first line of each test case contains a single integer q (1≤q≤5⋅105) — the number of queries.

The following q lines can fall into two cases:

The first type of query: The i-th line contains two integers ti (ti=1), vi. You need to add a child with
the number sz+1 to vertex vi, where sz is the current size of the tree. It is guaranteed that 1≤vi≤sz.
The second type of query: The i-th line contains three integers ti (ti=2), vi, xi (−109≤xi≤109).
You need to add xi to all numerical values of vertices in the subtree of vi. It is guaranteed that 1≤vi≤sz,
where sz is the current size of the tree.
It is guaranteed that the sum of q across all test cases does not exceed 5⋅105.

Output
For each test case, output the numerical value of each vertex of the final tree after all queries have
been performed.
*/
#include <bits/stdc++.h>

#define endl '\n'
#define MAX 500'000

using namespace std;


long long BIT[MAX + 1];
vector<vector<int>> adjacencyList;
vector<long long> vertexVal;
vector<int> vertexBirth;
vector<vector<pair<long long, int>>> vertexUpdates;


void update(int x, int delta) //add "delta" at index "x"
{
    for(; x <= MAX; x += x&-x)
          BIT[x] += delta;
}


long long query(int x)//returns the sum of first x elements in given array a[]
{
     long long sum = 0;
     for(; x > 0; x -= x&-x)
         sum += BIT[x];
     return sum;
}


void dfs(int vertex) {

    for (pair<long long, int>& vUpdate : vertexUpdates[vertex])
    {
        update(vUpdate.second, vUpdate.first);
    }


    vertexVal[vertex] = query(MAX) - query(vertexBirth[vertex]);
    for (int adjacent : adjacencyList[vertex])
    {
        dfs(adjacent);
    }


    for (pair<long long, int>& vUpdate : vertexUpdates[vertex])
    {
        update(vUpdate.second, -vUpdate.first);
    }
}


int main() {
    ios::sync_with_stdio(0);
    ////////////////////////
    int tests;
    int queries;
    int type;
    long long v1, v2;


    cin >> tests;
    while(tests--)
    {
        adjacencyList.clear();
        adjacencyList.resize(2);

        vertexVal = vector<long long>(2, 0);
        vertexBirth = vector<int>(2, 0);

        vertexUpdates = vector<vector<pair<long long, int>>>(2);
        ////////////////////////


        cin >> queries;
        for (int i = 0, currTime = 1; i < queries; i++, currTime++)
        {
            cin >> type >> v1;

            // Add a child vertex
            if (type == 1)
            {
                vertexVal.push_back(0);
                vertexBirth.push_back(currTime);
                vertexUpdates.resize(vertexUpdates.size()+1);

                adjacencyList[v1].push_back(vertexVal.size()-1);
                adjacencyList.resize(adjacencyList.size()+1);
            }
            // Add value to subtree
            else
            {
                cin >> v2;
                vertexUpdates[v1].push_back({v2, currTime});
            }
        }

        dfs(1);
        for (int i = 1; i < vertexVal.size(); i++)
        {
            cout << vertexVal[i] << " ";
        }
        cout << endl;
    }


    return 0;
}