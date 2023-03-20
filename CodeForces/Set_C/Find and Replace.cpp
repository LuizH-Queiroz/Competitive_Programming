/*
You are given a string s consisting of lowercase Latin characters. In an operation, you can take a character and replace
all occurrences of this character with 0 or replace all occurrences of this character with 1

.

Is it possible to perform some number of moves so that the resulting string is an alternating binary string†

?

For example, consider the string abacaba

. You can perform the following moves:

    Replace a

with 0. Now the string is 0b0c0b0
.
Replace b
with 1. Now the string is 010c010
.
Replace c
with 1. Now the string is 0101010

    . This is an alternating binary string. 

†
An alternating binary string is a string of 0s and 1s such that no two adjacent bits are equal.
For example, 01010101, 101, 1 are alternating binary strings, but 0110, 0a0a0, 10100

are not.
Input

The input consists of multiple test cases. The first line contains an integer t
(1≤t≤100

) — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer n
(1≤n≤2000) — the length of the string s

.

The second line of each test case contains a string consisting of n
lowercase Latin characters — the string s

.
Output

For each test case, output "YES" (without quotes) if you can make the string into an alternating binary string, and "NO" (without quotes) otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive answer).
*/
#include <iostream>

#define ALPHABET_SIZE 26

using namespace std;


int main() {
    int tests;
    int str_length;
    char character, prevCharIndex, charIndex;
    bool canMake;


    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        int charVal[ALPHABET_SIZE];
        for (int j = 0; j < ALPHABET_SIZE; j++)
            charVal[j] = -1; // No assigned value
        canMake = true;

        cin >> str_length;
        for (int j = 0; j < str_length; j++)
        {
            cin >> character;
            charIndex = (int) character - 'a';

            if (charVal[charIndex] == -1)
            {
                if (j == 0 || charVal[prevCharIndex] == 1)
                    charVal[charIndex] = 0;
                else
                    charVal[charIndex] = 1;
            }
            else if (charVal[charIndex] == charVal[prevCharIndex])
            {
                canMake = false;
            }

            prevCharIndex = character - 'a';
        }


        if (canMake)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }



    return 0;
}