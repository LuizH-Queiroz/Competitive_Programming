/*
During Zhongkao examination, Reycloer met an interesting problem, but he cannot come up with a solution immediately. Time is running out! Please help him.

Initially, you are given an array a
 consisting of n≥2
 integers, and you want to change all elements in it to 0
.

In one operation, you select two indices l
 and r
 (1≤l≤r≤n
) and do the following:

Let s=al⊕al+1⊕…⊕ar
, where ⊕
 denotes the bitwise XOR operation;
Then, for all l≤i≤r
, replace ai
 with s
.
You can use the operation above in any order at most 8
 times in total.

Find a sequence of operations, such that after performing the operations in order, all elements in a
 are equal to 0
. It can be proven that the solution always exists.

Input
The first line of input contains a single integer t
 (1≤t≤500
) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer n
 (2≤n≤100
) — the length of the array a
.

The second line of each test case contains n
 integers a1,a2,…,an
 (0≤ai≤100
) — the elements of the array a
.

Output
For each test case, in the first line output a single integer k
 (0≤k≤8
) — the number of operations you use.

Then print k
 lines, in the i
-th line output two integers li
 and ri
 (1≤li≤ri≤n
) representing that you select li
 and ri
 in the i
-th operation.

Note that you do not have to minimize k
. If there are multiple solutions, you may output any of them.
*/
#include <iostream>

#define endl "\n"

using namespace std;


int main() {
    int tests;
    int n;
    int value;


    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> value;
        }

        if (n%2 == 0)
        {
            cout << "2" << endl;
            cout << "1 " << n << endl;
            cout << "1 " << n << endl;
        }
        else
        {
            cout << "4" << endl;
            cout << "1 " << n << endl;
            cout << "1 2" << endl;
            cout << "2 3" << endl;
            cout << "2 " << n << endl;
        }
    }


    return 0;
}