/*
There are two mice and n different types of cheese, each type of cheese should be eaten by exactly one mouse.

A point of the cheese with index i (0-indexed) is:

    reward1[i] if the first mouse eats it.
    reward2[i] if the second mouse eats it.

You are given a positive integer array reward1, a positive integer array reward2, and a non-negative integer k.

Return the maximum points the mice can achieve if the first mouse eats exactly k types of cheese.
*/


class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        priority_queue<int> diff;
        int points = 0;

        for (int i = 0; i < reward1.size(); i++)
        {
            points += reward2[i];
            diff.push(reward1[i] - reward2[i]);
        }

        for (int i = 0; i < k; i++)
        {
            points += diff.top();
            diff.pop();
        }

        return points;
    }
};