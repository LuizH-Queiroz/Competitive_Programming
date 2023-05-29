/*
Given a string s, partition the string into one or more substrings such that the characters in each substring are unique.
That is, no letter appears in a single substring more than once.

Return the minimum number of substrings in such a partition.

Note that each character should belong to exactly one substring in a partition.
*/


class Solution {
public:
    int partitionString(string s) {
        int minSubstrings = 1;
        bool appear[26] = {false};

        for (int i = 0; i < s.size(); i++)
        {
            if (appear[s[i] - 'a'] == true)
            {
                minSubstrings++;
                for (int j = 0; j < 26; j++)
                    appear[j] = false;
            }

            appear[s[i] - 'a'] = true;
        }

        return minSubstrings;
    }
};