/*
A string s is called good if there are no two different characters in s that have the same frequency.

Given a string s, return the minimum number of characters you need to delete to make s good.

The frequency of a character in a string is the number of times it appears in the string.
For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.
*/


class Solution {
public:
    int minDeletions(string s) {
        vector<int> charFrequency(26, 0);
        vector<int> nWithFrequency(s.size()+1, 0);
        stack<int> lastFreeFrequency;
        int deletions = 0;


        int index;
        for (int i = 0; i < s.size(); i++)
        {
            index = s[i] - 'a';

            nWithFrequency[charFrequency[index]]--;
            charFrequency[index]++;
            nWithFrequency[charFrequency[index]]++;
        }

        for (int i = 0; i < nWithFrequency.size(); i++)
        {
            if (nWithFrequency[i] == 0)
            {
                lastFreeFrequency.push(i);
                continue;
            }

            while(nWithFrequency[i] > 1)
            {
                if (!lastFreeFrequency.empty())
                {
                    deletions += i - lastFreeFrequency.top();
                    lastFreeFrequency.pop();
                }
                else
                {
                    deletions += i;
                }

                nWithFrequency[i]--;
            }
        }

        return deletions;
    }
};