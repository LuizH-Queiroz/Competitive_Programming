/*
You are given a string s consisting of lowercase Latin letters and q queries for this string.

Recall that the substring s[l;r] of the string s is the string slsl+1…sr.
For example, the substrings of "codeforces" are "code", "force", "f", "for", but not "coder" and "top".

There are two types of queries:

1 pos c (1≤pos≤|s|, c is lowercase Latin letter): replace spos with c (set spos:=c);2 l r (1≤l≤r≤|s|):
calculate the number of distinct characters in the substring s[l;r].

Input
The first line of the input contains one string s consisting of no more than 105 lowercase Latin letters.

The second line of the input contains one integer q (1≤q≤105) — the number of queries.

The next q lines contain queries, one per line. Each query is given in the format described in the
problem statement. It is guaranteed that there is at least one query of the second type.

Output
For each query of the second type print the answer for it — the number of distinct characters in the
required substring in this query.
*/
#include <bits/stdc++.h>

#define endl '\n'

#define MAXN 100'000

using namespace std;


/*********************************************************/
int t[4*MAXN];


void build(vector<int>& a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] | t[v*2+1];
    }
}


int sum(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm)) | sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}


void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] | t[v*2+1];
    }
}
/*********************************************************/


int countBits(int n) {
    int counter = 0;

    for (int i = 0; i < 26; i++)
    {
        if ((n&(1<<i)) != 0)
            counter++;
    }

    return counter;
}


int main() {
    ios::sync_with_stdio(0);
    //////////////////////////
    int numQueries;
    string str;
    vector<int> sequence;



    cin >> str >> numQueries;

    sequence.resize(str.size()+1);
    for (int i = 0; i < str.size(); i++)
    {
        sequence[i+1] = 1<<(str[i]-'a');
        // cout << sequence[i] << " ";
    }
    // cout << endl;
    build(sequence, 1, 1, sequence.size()-1);


    int queryType;
    int l, r;
    char newVal;
    int valIndex;
    for (int i = 0; i < numQueries; i++)
    {
        cin >> queryType;
        if (queryType == 1) // Replace
        {
            cin >> valIndex >> newVal;
            update(1, 1, sequence.size()-1, valIndex, 1<<(newVal-'a'));
        }
        else // Calculate the number of distinct characters
        {
            cin >> l >> r;
            cout << countBits(sum(1, 1, sequence.size()-1, l, r)) << endl;
        }
    }



    return 0;
}