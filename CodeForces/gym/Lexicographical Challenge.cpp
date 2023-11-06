/*
In the picturesque village of Lexicoville there lived two friends, Lily and Ethan. One day, a mysterious letter
arrived at their house, sealed with a bunch of beatiful insignia full of sparkle and enchantment.
Inside the envelope, they found a riddle too complex, even for the wisest minds of their village.

In this riddle, they were given an integer K and a string S containing only lower-case letters, which
could be changed according to a curious rule. At each moment, the villagers have the freedom to choose
an index i; then, magically, the characters Si and Si+K will be swapped! The riddle will be solved when
the lexicographically minimum string, using only the allowed operation, is found.

The village was filled with curiosity and excitement with this riddle, but none more so than Lily and Ethan.
The friends, always craving adventure, decided to dive headfirst into this challenge.
However, as they observed the string, they noticed that the road to success was paved with countless
possible swaps.

With the riddle's words echoing in their minds, they wondered: How could they navigate this web of
possibilities to unveil the lexicographically minimum string? Every swap was like turning a page in a
magical book, revealing new secrets and mysteries.

A long time has passed, but neither Lily nor Ethan have been able to solve the riddle. Can you help them?

Input
The first line contains the string S (1≤|S|≤105). The seconds line contains the integer K (1≤K<|S|).

Output
Output a single line with the lexicographically earliest string that can be obtained.
*/
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    /////////////////////////
    string str;
    int k;


    cin >> str >> k;
    for (int i = 0; i < k; i++)
    {
        priority_queue<char, vector<char>, greater<char>> pq;

        for (int j = i; j < str.size(); j += k)
        {
            pq.push(str[j]);
        }

        for (int j = i; j < str.size(); j += k)
        {
            str[j] = pq.top();
            pq.pop();
        }
    }

    cout << str << endl;


    return 0;
}