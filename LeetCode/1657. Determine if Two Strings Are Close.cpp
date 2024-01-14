/*
Two strings are considered close if you can attain one from the other using the following operations:

    Operation 1: Swap any two existing characters.
        For example, abcde -> aecdb
    Operation 2: Transform every occurrence of one existing character into another existing character, and do the
    same with the other character.
        For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)

You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.
*/


class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size())
            return false;

        vector<int> count1('z'+1, 0);
        vector<int> count2('z'+1, 0);
        int w1_chars = 0, w2_chars = 0;

        for (int i = 0; i < word1.size(); i++)
        {
            count1[word1[i]]++;
            w1_chars |= 1<<(word1[i]-'a');
        }

        for (int i = 0; i < word2.size(); i++)
        {
            count2[word2[i]]++;
            w2_chars |= 1<<(word2[i]-'a');
        }

        if (w1_chars != w2_chars)
            return false;


        priority_queue<int> pq1, pq2;
        for (char c = 'a'; c <= 'z'; c++)
        {
            pq1.push(count1[c]);
            pq2.push(count2[c]);
        }

        while(!pq1.empty() && !pq2.empty())
        {
            if (pq1.top() != pq2.top())
                return false;

            pq1.pop();
            pq2.pop();
        }

        return pq1.empty() && pq2.empty();
    }
};