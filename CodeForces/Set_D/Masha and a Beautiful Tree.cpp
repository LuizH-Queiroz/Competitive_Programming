#include <bits/stdc++.h>

#define endl '\n'

using namespace std;


vector<int> arr;
int solve(int l, int r) {
    if (l == r)
        return 0;

    
    int middle = (r + l) / 2;
    int moves = 0;
    int temp;


    temp = solve(l, middle);
    if (temp == -1)
        return -1;
    moves += temp;

    temp = solve(middle+1, r);
    if (temp == -1)
        return -1;
    moves += temp;

    if (arr[l] == arr[r]+1)
    {
        moves++;

        int left = arr[middle+1];
        int right = arr[middle];
        arr[l] = left;
        arr[r] = right;
    }
    else if (arr[r] != arr[l] + (r-l))
    {
        return -1;
    }

    return moves;
}


int main() {
    ios::sync_with_stdio(0);
    ////////////////////////
    int tests;
    int size;


    cin >> tests;
    while(tests--)
    {
        cin >> size;

        arr.resize(size);
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }

        cout << solve(0, size-1) << endl;
    }



    return 0;
}