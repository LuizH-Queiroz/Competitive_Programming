/*
You are given a binary string binary consisting of only 0's or 1's. You can apply each of the following operations any number of times:

    Operation 1: If the number contains the substring "00", you can replace it with "10".
        For example, "00010" -> "10010"
    Operation 2: If the number contains the substring "10", you can replace it with "01".
        For example, "00010" -> "00001"

Return the maximum binary string you can obtain after any number of operations.
Binary string x is greater than binary string y if x's decimal representation is greater than y's decimal representation.
*/


class Solution {
public:
    string maximumBinaryString(string binary) {
        queue<int> zerosIndex;

        for (int i = 0; i < binary.size(); i++)
        {
            if (binary[i] == '0')
            {
                zerosIndex.push(i);
            }
        }

        for (int i = 0; i < binary.size()-1; i++)
        {
            if (binary[i] == '0')
            {
                if (binary[i+1] == '0')
                {
                    binary[i] = '1';
                }
                else
                {
                    int index = -1;
                    while(!zerosIndex.empty() && index <= i)
                    {
                        index = zerosIndex.front();
                        zerosIndex.pop();
                    }

                    if (index > i+1)
                    {
                        binary[index] = '1';
                        binary[i+1] = '0';
                        binary[i] = '1';
                    }
                }
            }
        }

        return binary;
    }
};