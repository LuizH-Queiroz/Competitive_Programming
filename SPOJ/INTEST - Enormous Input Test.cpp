/*
The purpose of this problem is to verify whether the method you are using to read input data is
sufficiently fast to handle problems branded with the enormous Input/Output warning.
You are expected to be able to process at least 2.5MB of input data per second at runtime.

Input
The input begins with two positive integers n k (n, k<=107). The next n lines of input contain one
positive integer ti, not greater than 109, each.

Output
Write a single integer to output, denoting how many integers ti are divisible by k.
*/
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    int n, k;
    int val;
    int counter = 0;


    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        if (val % k == 0)
            counter++;
    }

    cout << counter << endl;


    return 0;
}