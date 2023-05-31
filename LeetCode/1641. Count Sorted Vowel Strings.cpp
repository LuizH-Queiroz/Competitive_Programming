/*
Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.

A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.
*/


class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> count(5, 1);
        int sum = 0;

        for (int i = 2; i <= n; i++)
            for (int index = 3; index >= 0; index--)
                count[index] += count[index+1];
        
        for (int i = 0; i <= 4; i++)
            sum += count[i];
        
        return sum;
    }
};