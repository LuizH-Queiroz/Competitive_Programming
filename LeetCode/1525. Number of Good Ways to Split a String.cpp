/*
You are given a string s.

A split is called good if you can split s into two non-empty strings sleft and sright where their concatenation is equal
to s (i.e., sleft + sright = s) and the number of distinct letters in sleft and sright is the same.

Return the number of good splits you can make in s.
*/


class Solution {
public:
    int numSplits(string s) {
        int leftCounter = 0;
        int rightCounter = 0;
        vector<int> lastAppear(26, -1);
        int splitsCounter = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (lastAppear[s[i] - 'a'] == -1)
                rightCounter++;
            lastAppear[s[i] - 'a'] = i;
        }

        vector<bool> appear(26, false);
        for (int i = 0; i < s.size(); i++)
        {
            if (!appear[s[i] - 'a'])
            {
                leftCounter++;
                appear[s[i] - 'a'] = true;
            }
            if (lastAppear[s[i] - 'a'] == i)
            {
                rightCounter--;
            }

            if (leftCounter == rightCounter)
                splitsCounter++;
        }

        return splitsCounter;
    }
};