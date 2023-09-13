/*
There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network
where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach
any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two
directly connected computers, and place them between any pair of disconnected computers to make them
directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected.
If it is not possible, return -1.
*/


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n-1)
            return -1;

        vector<int> parent(n);
        int connectedComponents = n;


        function<int(int)> findParent;
        findParent = [&](int n) {
            if (parent[n] == n)
                return n;
            
            return parent[n] = findParent(parent[n]);
        };

        function<void(int, int)> Union;
        Union = [&](int a, int b) {
            parent[findParent(a)] = findParent(b);
        };


        for (int i = 0; i < n; i++)
            parent[i] = i;
        
        for (vector<int> connection : connections)
        {
            if (findParent(connection[0]) != findParent(connection[1]))
            {
                Union(connection[0], connection[1]);
                connectedComponents--;
            }
        }

        return connectedComponents - 1;
    }
};