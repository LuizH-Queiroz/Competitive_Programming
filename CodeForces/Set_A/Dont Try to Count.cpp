/*
Given a string x of length n and a string s of length m (n⋅m≤10025), consisting of lowercase Latin letters,
you can apply any number of operations to the string x.
In one operation, you append the current value of x to the end of the string x. Note that the value of x will
change after this.
For example, if x=-"aba", then after applying operations, x will change as follows:
"aba" → "abaaba" → "abaabaabaaba".
After what minimum number of operations s will appear in x as a substring? A substring of a string is
defined as a contiguous segment of it.

Input
The first line of the input contains a single integer t (1≤t≤104) — the number of test cases.
The first line of each test case contains two numbers n and m (1≤n⋅m≤25) — the lengths of strings x and s,
respectively.
The second line of each test case contains the string x of length n.
The third line of each test case contains the string s of length m.

Output
For each test case, output a single number — the minimum number of operations after which s will appear
in x as a substring. If this is not possible, output −1.
*/
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;


bool isSubstr(string a, string sub) {
    if (sub.size() > a.size())
    {
        return false;
    }

    for (int i = 0; i < (a.size() - (sub.size()-1)); i++)
    {
        bool isSub = true;
        for (int j = 0; j < sub.size(); j++)
        {
            if (a[i+j] != sub[j])
            {
                isSub = false;
                break;
            }
        }

        if (isSub)
            return true;
    }

    return false;
}


int main() {
    int tests;
    int lx, ls;
    string x, s;



    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        cin >> lx >> ls;
        cin >> x >> s;

        int counter = 0;
        bool isSub = false;
        while(true)
        {
            if (isSubstr(x, s))
            {
                isSub = true;
                break;
            }
            else if (x.size() > 30*s.size())
            {
                break;
            }

            x += x;
            counter++;
        }

        if (isSub)
            cout << counter << endl;
        else
            cout << -1 << endl;
    }


    return 0;
}