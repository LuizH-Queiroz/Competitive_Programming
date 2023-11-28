/*
Subham and Dewang both are playing with numbers.
Subham gives Dewang an array of numbers and asks him to tell the minimum possible last number of a
increasing sequence of length L.

Note: Check the sample I/O for more clarity.

Input
Input consists of number of test cases T. Each test case contains size of array i.e N. Next line contains
N space separated elements of array. Next line contains length of the increasing sequence i.e. L.

Constraignts
1 ≤ T ≤ 100
0 ≤ N ≤ 106
0 ≤ a[i] ≤ 106

Output
You have to print the minimum possible last number of a sequence and if their is no increasing sequence
of length L, then print "-1" without the quotes.
*/
#include <bits/stdc++.h>

#define endl '\n'
#define MAX 1'000'001

using namespace std;


int BIT[MAX + 1];


void update(int x, int delta) //add "delta" at index "x"
{
    for(; x <= MAX; x += x&-x)
          BIT[x] = max(BIT[x], delta);
}


int query(int x)//returns the sum of first x elements in given array a[]
{
    int sum = 0;
    for(; x > 0; x -= x&-x)
        sum = max(sum, BIT[x]);
    return sum;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    int tests;
    int length;
    int val;
    int sequenceSize;
    vector<int> arr;


    cin >> tests;
    while(tests--)
    {
        cin >> length;

        arr.resize(length);
        memset(BIT, 0, sizeof(BIT));

        for (int i = 0; i < length; i++)
        {
            cin >> arr[i];
        }

        cin >> sequenceSize;

        int ans = -1;
        int q;
        for (int i = 0; i < length; i++)
        {
            q = query(arr[i]);
            update(arr[i]+1, q+1);

            if (q+1 >= sequenceSize)
            {
                if (ans == -1)
                    ans = arr[i];
                else
                    ans = min(ans, arr[i]);
            }
        }

        cout << ans << endl;
    }



    return 0;
}