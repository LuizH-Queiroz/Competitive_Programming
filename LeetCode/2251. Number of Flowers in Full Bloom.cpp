/*
You are given a 0-indexed 2D integer array flowers, where flowers[i] = [starti, endi] means the ith flower
will be in full bloom from starti to endi (inclusive). You are also given a 0-indexed integer array people
of size n, where people[i] is the time that the ith person will arrive to see the flowers.

Return an integer array answer of size n, where answer[i] is the number of flowers that are in full bloom
when the ith person arrives.
*/


class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> bloom;
        vector<int> ans(people.size(), 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (vector<int> flower : flowers)
        {
            bloom[flower[0]]++;
            bloom[flower[1]+1]--;
        }

        for (int i = 0; i < people.size(); i++)
        {
            pq.push({people[i], i});
        }

        int onFullBloom = 0;
        int index = 0;
        for (map<int, int>::iterator it = bloom.begin(); it != bloom.end(); it++)
        {
            while(!pq.empty() && pq.top().first < (*it).first)
            {
                ans[pq.top().second] = onFullBloom;
                pq.pop();
            }

            onFullBloom += (*it).second;

            while(!pq.empty() && pq.top().first == (*it).first)
            {
                ans[pq.top().second] = onFullBloom;
                pq.pop();
            }
        }

        return ans;
    }
};