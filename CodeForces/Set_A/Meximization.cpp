/*
You are given an integer n and an array a1,a2,…,an. You should reorder the elements of the array a in such way that
the sum of MEX on prefixes (i-th prefix is a1,a2,…,ai) is maximized.

Formally, you should find an array b1,b2,…,bn, such that the sets of elements of arrays a and b are equal
(it is equivalent to array b can be found as an array a with some reordering of its elements) and ∑i=1nMEX(b1,b2,…,bi) is maximized.

MEX of a set of nonnegative integers is the minimal nonnegative integer such that it is not in the set.

For example, MEX({1,2,3})=0, MEX({0,1,2,4,5})=3.

Input
The first line contains a single integer t (1≤t≤100)  — the number of test cases.

The first line of each test case contains a single integer n (1≤n≤100).

The second line of each test case contains n integers a1,a2,…,an (0≤ai≤100).

Output
For each test case print an array b1,b2,…,bn  — the optimal reordering of a1,a2,…,an, so the sum of MEX on its prefixes is maximized.

If there exist multiple optimal answers you can find any.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


int main() {
    vector<int> nums;
    queue<int> repeated;
    int tests;


    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        int length;

        cin >> length;

        nums.resize(length);
        for (int j = 0; j < length; j++)
        {
            cin >> nums[j];
        }
        sort(nums.begin(), nums.end());

        // Print the optimal reordering
        cout << nums[0];
        for (int j = 1; j < length; j++)
        {
            if (nums[j] == nums[j-1])
            {
                repeated.push(nums[j]);
            }
            else
            {
                cout << " " << nums[j];
            }
        }
        while (!repeated.empty())
        {
            cout << " " << repeated.front();
            repeated.pop();
        }
        cout << endl;
    }



    return 0;
}