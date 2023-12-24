#include <bits/stdc++.h>

#define endl '\n'

using namespace std;


vector<int> parent;


int find_parent(int n) {
    if (parent[n] == n)
        return n;
    
    return parent[n] = find_parent(parent[n]);
}


void join(int a, int b) {
    parent[find_parent(a)] = find_parent(b);
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    int numVertices;
    int v1, v2;
    queue<pair<int, int>> close;
    set<int> used;


    cin >> numVertices;

    parent.resize(numVertices+1);
    for (int i = 1; i <= numVertices; i++)
        parent[i] = i;

    for (int i = 0; i < (numVertices-1); i++)
    {
        cin >> v1 >> v2;

        if (find_parent(v1) != find_parent(v2))
        {
            join(v1, v2);
        }
        else
        {
            close.push({v1, v2});
        }
    }


    cout << close.size() << endl;

    int prev = -1;
    for (int i = 1; i <= numVertices && !close.empty(); i++)
    {
        if (used.find(find_parent(i)) == used.end())
        {
            used.insert(find_parent(i));

            if (prev != -1)
            {
                cout << close.front().first << " " << close.front().second << " " << prev << " " << i << endl;
                close.pop();
            }
            prev = i;
        }
    }


    return 0;
}