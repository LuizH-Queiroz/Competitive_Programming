/*
Serval has a string s that only consists of 0 and 1 of length n. The i-th character of s is denoted as si,
where 1≤i≤n.

Serval can perform the following operation called Inversion Magic on the string s
:

Choose an segment [l,r]
 (1≤l≤r≤n
). For l≤i≤r
, change si
 into 1 if si
 is 0, and change si
 into 0 if si
 is 1.
For example, let s
 be 010100 and the segment [2,5]
 is chosen. The string s
 will be 001010 after performing the Inversion Magic.

Serval wants to make s
 a palindrome after performing Inversion Magic exactly once. Help him to determine whether it is possible.

A string is a palindrome iff it reads the same backwards as forwards. For example, 010010 is a palindrome but 10111 is not.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains a single integer n
 (2≤n≤105
) — the length of string s
.

The second line of each test case contains a binary string s
 of length n
. Only characters 0 and 1 can appear in s
.

It's guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print Yes if s
 can be a palindrome after performing Inversion Magic exactly once, and print No if not.

You can output Yes and No in any case (for example, strings yEs, yes, Yes and YES will be recognized as a positive response).
*/
#include <iostream>
#include <string>

using namespace std;


int main() {
    int tests;
    int length;
    string str;


    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        cin >> length >> str;

        int left = 0, right = length-1;
        int diffIndex = -1;
        bool canTransform = true;
        while(left < right)
        {
            if (str[left] != str[right])
            {
                if (diffIndex == -1)
                {
                    diffIndex = left;
                }
                else if (left != diffIndex+1)
                {
                    canTransform = false;
                    break;
                }
                else
                {
                    diffIndex = left;
                }
            }
            left++;
            right--;
        }

        if (canTransform) cout << "YES" << endl;
        else cout << "NO" << endl;
    }


    return 0;
}