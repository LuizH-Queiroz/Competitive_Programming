/*
There is a directed weighted graph that consists of n nodes numbered from 0 to n - 1.
The edges of the graph are initially represented by the given array edges where
edges[i] = [fromi, toi, edgeCosti] meaning that there is an edge from fromi to toi with the cost edgeCosti.

Implement the Graph class:

Graph(int n, int[][] edges) initializes the object with n nodes and the given edges.
addEdge(int[] edge) adds an edge to the list of edges where edge = [from, to, edgeCost].
It is guaranteed that there is no edge between the two nodes before adding this one.
int shortestPath(int node1, int node2) returns the minimum cost of a path from node1 to node2.
If no path exists, return -1. The cost of a path is the sum of the costs of the edges in the path.
*/


class Graph {
public:
    vector<vector<pair<int, long long>>> outList;

    Graph(int n, vector<vector<int>>& edges) {
        outList.resize(n);
    
        for (vector<int>& edge : edges)
        {
            outList[edge[0]].push_back({edge[1], edge[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        outList[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<bool> visited(outList.size(), false);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;


        pq.push({0, node1});
        while(!pq.empty())
        {
            int node = pq.top().second;
            long long cost = pq.top().first;
            pq.pop();

            if (visited[node])
                continue;
            if (node == node2)
                return cost;
            visited[node] = true;

            for (pair<int, long long>& adjacency : outList[node])
            {
                if (!visited[adjacency.first])
                {
                    pq.push({cost + adjacency.second, adjacency.first});
                }
            }
        }

        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */