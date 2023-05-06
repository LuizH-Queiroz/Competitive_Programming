/*
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.
*/


class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastPosition(26 /* Letters in the alphabet */, -1);
        vector<int> sizes;

        for (int i = 0; i < s.size(); i++)
            lastPosition[ (int) (s[i] - 'a') ] = i;
        

        int partInitialIndex = 0;
        int partLastIndex = -1;
        for (int i = 0; i < s.size(); i++)
        {
            partLastIndex = max(partLastIndex, lastPosition[ (int) (s[i] - 'a') ]);

            if (i == partLastIndex)
            {
                sizes.push_back((partLastIndex - partInitialIndex) + 1);
                partInitialIndex = i+1;
            }
        }


        return sizes;
    }
};