/*
You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.

Return the minimum size of the set so that at least half of the integers of the array are removed.
*/


class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<int> appears(1, 1);

        sort(arr.begin(), arr.end());
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] != arr[i-1])
                appears.push_back(1);
            else
                appears.back()++;
        }

        int sum = 0;
        int ans = 0;
        sort(appears.begin(), appears.end());
        for (int i = appears.size()-1; i >= 0; i--)
        {
            sum += appears[i];
            ans++;

            if (sum >= arr.size()/2)
                break;
        }

        return ans;
    }
};