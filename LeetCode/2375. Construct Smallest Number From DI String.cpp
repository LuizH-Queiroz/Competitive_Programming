/*
You are given a 0-indexed string pattern of length n consisting of the characters 'I' meaning increasing and 'D' meaning decreasing.

A 0-indexed string num of length n + 1 is created using the following conditions:

    num consists of the digits '1' to '9', where each digit is used at most once.
    If pattern[i] == 'I', then num[i] < num[i + 1].
    If pattern[i] == 'D', then num[i] > num[i + 1].

Return the lexicographically smallest possible string num that meets the conditions.
*/


class Solution {
public:
    string smallestNumber(string pattern) {
        string num(pattern + 'D');
        queue<char> q;
        char digit = '1';

        for (int i = 0; i < num.size(); i++)
        {
            q.push(digit);
            digit++;

            if (num[i] == 'I' || i == (num.size() - 1))
            {
                int aux = i;
                while(!q.empty())
                {
                    num[aux] = q.front();
                    q.pop();

                    aux--;
                }
            }
        }

        return num;
    }
};