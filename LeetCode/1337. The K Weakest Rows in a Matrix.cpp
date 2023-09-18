/*
You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians).
The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of
all the 0's in each row.

A row i is weaker than a row j if one of the following is true:

The number of soldiers in row i is less than the number of soldiers in row j.
Both rows have the same number of soldiers and i < j.
Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.
*/


class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pair<int, int> line;

        for (int i = 0; i < mat.size(); i++)
        {
            line.first = 0;
            line.second = i;
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == 0)
                    break;

                line.first++;
            }

            pq.push(line);
        }


        vector<int> ans(k);
        for (int i = 0; i < k; i++)
        {
            ans[i] = pq.top().second;
            pq.pop();
        }

        return ans;
    }
};