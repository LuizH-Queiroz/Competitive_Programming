/*
You are given two strings s1 and s2 of equal length consisting of letters "x" and "y" only. Your task is to make these two strings equal to each other.
You can swap any two characters that belong to different strings, which means: swap s1[i] and s2[j].

Return the minimum number of swaps required to make s1 and s2 equal, or return -1 if it is impossible to do so.
*/


class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int x_diff = 0;
        int y_diff = 0;
        int swaps = 0;

        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
            {
                if (s1[i] == 'x')
                {
                    x_diff++;
                    if (x_diff == 2)
                    {
                        swaps++;
                        x_diff = 0;
                    }
                }
                else // s1[i] == 'y
                {
                    y_diff++;
                    if (y_diff == 2)
                    {
                        swaps++;
                        y_diff = 0;
                    }
                }
            }
        }

        if (x_diff == 1 && y_diff == 1)
        {
            swaps += 2;
            x_diff = y_diff = 0;
        }

        if (x_diff == 0 && y_diff == 0)
            return swaps;
        else
            return -1;
    }
};