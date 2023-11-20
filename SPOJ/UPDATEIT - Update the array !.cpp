/*
You have an array containing n elements initially all 0. You need to do a number of update operations on it.
In each update you specify l, r and val which are the starting index, ending index and value to be added.
After each update, you add the 'val' to all elements from index l to r. After 'u' updates are over,
there will be q queries each containing an index for which you have to print the element at that index.

Input
First line consists of t, the number of test cases. (1 <= t <= 10)

Each test case consists of "n u",number of elements in the array and the number of update operations,
in the first line (1 <= n <= 10000 and 1 <= u <= 100000)

Then follow u lines each of the format "l r val" (0 <= l,r < n, 0 <= val <=10000)

Next line contains q, the number of queries. (1 <= q <= 10000)

Next q lines contain an index (0 <= index < n)

Output
For each test case, output the answers to the corresponding queries in separate lines.
*/
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    int tests;
    int length, numUpdates, numQueries;
    int l, r, val, index;


    cin >> tests;
    while(tests--)
    {
        cin >> length >> numUpdates;

        vector<int> arr(length, 0);
        for (int i = 0; i < numUpdates; i++)
        {
            cin >> l >> r >> val;
            
            arr[l] += val;
            if (r+1 < length)
                arr[r+1] -= val;
        }

        for (int i = 1; i < length; i++)
        {
            arr[i] += arr[i-1];
        }


        cin >> numQueries;
        for (int i = 0; i < numQueries; i++)
        {
            cin >> index;
            cout << arr[index] << endl;
        }
    }



    return 0;
}