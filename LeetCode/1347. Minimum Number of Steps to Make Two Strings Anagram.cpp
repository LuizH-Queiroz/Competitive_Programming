/*
You are given two strings of the same length s and t. In one step you can choose any character of t and replace it
with another character.

Return the minimum number of steps to make t an anagram of s.

An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.
*/


class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> counterS('z'+1, 0);
        vector<int> counterT('z'+1, 0);
        int size = s.size();
        int diff = 0;

        for (int i = 0; i < size; i++)
        {
            counterS[s[i]]++;
            counterT[t[i]]++;
        }

        for (int i = 'a'; i <= 'z'; i++)
            diff += abs(counterS[i] - counterT[i]);

        return diff/2;
    }
};