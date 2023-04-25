/*
A permutation perm of n + 1 integers of all the integers in the range [0, n] can be represented as a string s of length n where:

    s[i] == 'I' if perm[i] < perm[i + 1], and
    s[i] == 'D' if perm[i] > perm[i + 1].

Given a string s, reconstruct the permutation perm and return it. If there are multiple valid permutations perm, return any of them.
*/


class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> perm(s.size() + 1);
        int lower = 0, higher = s.size();

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'I')
                perm[i] = lower++;
            else
                perm[i] = higher--;
        }
        perm.back() = lower;

        return perm;
    }
};