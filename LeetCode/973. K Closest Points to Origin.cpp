/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k,
return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
*/


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        vector<vector<int>> pontos;

        for (int i = 0; i < points.size(); i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            pq.push({x*x + y*y, i});
        }

        for (int i = 0; i < k; i++)
        {
            vector<int> ponto = points[pq.top().second];
            pontos.push_back(ponto);
            
            pq.pop();
        }

        return pontos;
    }
};