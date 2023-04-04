/*
A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"

To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above
(there may be multiple ways). For example, "11106" can be mapped into:

    "AAJF" with the grouping (1 1 10 6)
    "KJF" with the grouping (11 10 6)

Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.
*/


class Solution {
public:
    int numDecodings(string s) {
        vector<int> decodeWays(s.size()+1);
        decodeWays[decodeWays.size() - 1] = 1;
        if (s.back() == '0')
            decodeWays[decodeWays.size() - 2] = 0;
        else
            decodeWays[decodeWays.size() - 2] = 1;
        

        for (int i = s.size()-2; i >= 0; i--)
        {
            if (s[i] == '0')
            {
                decodeWays[i] = 0;
                continue;
            }

            decodeWays[i] = decodeWays[i+1];

            if ((s[i] == '1') || (s[i] == '2' && (s[i+1] >= '0' && s[i+1] <= '6')))
                decodeWays[i] += decodeWays[i+2];
        }


        return decodeWays[0];
    }
};