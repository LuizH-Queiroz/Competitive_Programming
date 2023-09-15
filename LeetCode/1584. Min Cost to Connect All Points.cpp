/*
You are given an array points representing integer coordinates of some points on a 2D-plane,
where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them:
|xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly
one simple path between any two points.
*/


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> adjacencyMatrix(points.size(), vector<int>(points.size(), 0));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minCostEdge;
        vector<bool> visited(points.size(), false);
        int includedPoints = 0;
        int minCost = 0;


        // Assigning values to the Adjacency Matrix
        for (int i = 0; i < points.size(); i++)
        {
            for (int j = i+1; j < points.size(); j++)
            {
                adjacencyMatrix[i][j] = Distance(points[i], points[j]);
                adjacencyMatrix[j][i] = Distance(points[i], points[j]);
            }
        }


        int currentPoint = 0;
        visited[0] = true;
        includedPoints = 1;
        while(includedPoints < points.size())
        {
            for (int i = 0; i < adjacencyMatrix[currentPoint].size(); i++)
            {
                if (!visited[i])
                    minCostEdge.push(pair<int, int>(adjacencyMatrix[currentPoint][i], i));
            }

            while(visited[minCostEdge.top().second])
                minCostEdge.pop();
            
            minCost += minCostEdge.top().first;
            visited[minCostEdge.top().second] = true;
            currentPoint = minCostEdge.top().second;

            minCostEdge.pop();
            includedPoints++;
        }

        return minCost;
    }


    int Distance(vector<int>& a, vector<int>& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
};