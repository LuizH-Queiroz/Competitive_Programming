#include <bits/stdc++.h>

#define endl '\n'

using namespace std;


int cuts(int length, int target) {
    if (length == target)
    {
        return 0;
    }
    else if (length < target)
    {
        return -1;
    }

    int temp = cuts(length - target, target);
    if (temp == -1)
        return -1;
    else
        return temp + 1;
}


int main() {
    ios::sync_with_stdio(0);
    ///////////////////////
    int tests;
    int a, b, c;
    int target;

    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        cin >> a >> b >> c;
        target = min(a, min(b, c));

        int c1, c2, c3;
        c1 = cuts(a, target);
        c2 = cuts(b, target);
        c3 = cuts(c, target);

        if ((c1 + c2 + c3) > 3 || (c1 == -1 || c2 == -1 || c3 == -1))
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }


    return 0;
}