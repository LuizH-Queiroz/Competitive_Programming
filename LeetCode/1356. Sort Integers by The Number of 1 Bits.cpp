/*
You are given an integer array arr. Sort the integers in the array in ascending order by the number
of 1's in their binary representation and in case of two or more integers have the same number of 1's
you have to sort them in ascending order.

Return the array after sorting it.
*/


class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int size = 8*sizeof(int);

        for (int i = 0; i < arr.size(); i++)
        {
            int count = 0;
            for (int bit = 0; bit < size; bit++)
                count += (arr[i]&(1<<bit)) != 0;
            
            pq.push({count, arr[i]});
        }

        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = pq.top().second;
            pq.pop();
        }

        return arr;
    }
};