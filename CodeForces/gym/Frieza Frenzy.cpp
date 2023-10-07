/*
"I doubt I need an introduction, but just in case, I am the mighty Frieza, and yes, all the horrible
stories you've heard are true."

Frieza arrived on Earth and is seeking for Goku.

He's not so patient, so he decided to destroy roads, one by one, until Goku appears.

As Frieza destroy roads, some regions get disconnected and people on some places can't get to some
other places. A set of places is said to be connected if, from any place on this set, it's
possible to reach every other place on it and no place outside it.

The Central City has n
 places and m
 bidirectional roads that connect two distinct places. Initially the city is connected.

Goku doesn't care about Frieza at all and will let Frieza destroy all roads. Meanwhile,
he decided to count the number of connected sets of places in Central City every time Frieza
destroy a road. You don't care about Frieza also, so you will help Goku.

Input
The first line of input contains two integers, n and m (2≤n≤105, n−1≤m≤min(n×(n−1)/2,105) — the number
of places and roads at Central City.

The next m lines contains, each, two integers, ui and vi (1≤ui,vi≤n, ui≠vi) — the places the i-th road
connects.

The next line contains m numbers, a permutation of all numbers between 1 and m — the sequence of roads
destroyed by Frieza.

It's guaranteed that there's no more than one road that connects u and v, for every u and v.

Output
For each road destroyed, print the number of connected sets of places in Central City.
*/
#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;


vector<int> parent;


int Find(int n) {
    if (parent[n] == n)
        return n;

    return parent[n] = Find(parent[n]);
}


void Union(int a, int b) {
    parent[Find(a)] = Find(b);
}


int main() {
    ios::sync_with_stdio(0);
    /////////////////////////
    int numVertices, numEdges;
    vector<vector<int>> edges;
    vector<int> destructionSequence;


    cin >> numVertices >> numEdges;

    edges.resize(numEdges+1, vector<int>(2));
    destructionSequence.resize(numEdges);
    parent.resize(numVertices+1);
    for (int i = 1; i <= numVertices; i++)
        parent[i] = i;

    
    for (int i = 1; i <= numEdges; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    for (int i = 0; i < numEdges; i++)
    {
        cin >> destructionSequence[i];
    }


    int components = numVertices;
    vector<int> ans(numEdges);

    for (int i = ans.size()-1; i >= 0; i--)
    {
        ans[i] = components;
        if (Find(edges[destructionSequence[i]][0]) != Find(edges[destructionSequence[i]][1]))
        {
            components--;
            Union(edges[destructionSequence[i]][0], edges[destructionSequence[i]][1]);
        }
    }


    cout << ans[0];
    for (int i = 1; i < numEdges; i++)
        cout << " " << ans[i];
    cout << endl;

    return 0;
}