/*
You are given three non-negative integers n, k, and x.
Find the maximum possible sum of elements in an array consisting of non-negative integers, which has
n elements, its MEX is equal to k, and all its elements do not exceed x. If such an array does
not exist, output −1.

The MEX (minimum excluded) of an array is the smallest non-negative integer that does not belong
to the array. For instance:

The MEX of [2,2,1] is 0, because 0 does not belong to the array.
The MEX of [3,1,0,1] is 2, because 0 and 1 belong to the array, but 2 does not.
The MEX of [0,3,1,2] is 4, because 0, 1, 2 and 3 belong to the array, but 4 does not.

Input
The first line contains a single integer t (1≤t≤1000) — the number of test cases.
Then follows the description of the test cases.

The only line of each test case contains three integers n, k, and x (1≤n,k,x≤200).

Output
For each test case, output a single number — the maximum sum of elements in a valid array, or −1,
if such an array does not exist.
*/
#include <iostream>

#define endl "\n"

using namespace std;


int main() {
    int length, mex, maxVal;
    int tests;
    int maxSum;


    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        cin >> length >> mex >> maxVal;

        if ((length < mex) || (maxVal < mex-1))
        {
            cout << -1 << endl;
            continue;
        }

        maxSum = (mex-1) * mex / 2;
        maxSum += (length - mex) * maxVal;
        if (maxVal == mex)
        {
            maxSum -= length - mex;
        }

        cout << maxSum << endl;
    }


    return 0;
}