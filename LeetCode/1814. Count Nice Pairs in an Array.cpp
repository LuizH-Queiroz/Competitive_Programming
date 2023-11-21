/*
You are given an array nums that consists of non-negative integers. Let us define rev(x) as the reverse
of the non-negative integer x. For example, rev(123) = 321, and rev(120) = 21. A pair of indices (i, j)
is nice if it satisfies all of the following conditions:

0 <= i < j < nums.length
nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])

Return the number of nice pairs of indices. Since that number can be too large, return it modulo 10e9 + 7.
*/


class Solution {
public:

    long long mod = 1'000'000'007;

    int countNicePairs(vector<int>& nums) {
        map<int, long long> freq;
        long long ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            freq[(nums[i] - rev(nums[i]))]++;
        }
        
        for (auto it = freq.begin(); it != freq.end(); it++)
            ans = (ans + it->second * (it->second - 1)/2) % mod;
        
        return ans;
    }

    int rev(int n) {
        int ans = 0;
        stack<int> st;

        while(n > 0)
        {
            if (n%10 != 0 || !st.empty())
                st.push(n%10);
            n /= 10;
        }

        int power = 1;
        while(!st.empty())
        {
            ans += st.top() * power;
            st.pop();
            power *= 10;
        }

        return ans;
    }
};