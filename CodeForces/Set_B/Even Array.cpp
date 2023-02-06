/*
You are given an array a[0…n−1] of length n which consists of non-negative integers. Note that
array indices start from zero.

An array is called good if the parity of each index matches the parity of the element at that index.
More formally, an array is good if for all i (0≤i≤n−1) the equality imod2=a[i]mod2 holds, where xmod2
is the remainder of dividing x by 2.

For example, the arrays [0,5,2,1] and [0,17,0,3] are good, and the array [2,4,6,7] is bad, because
for i=1, the parities of i and a[i] are different: imod2=1mod2=1, but a[i]mod2=4mod2=0.

In one move, you can take any two elements of the array and swap them (these elements are not
necessarily adjacent).

Find the minimum number of moves in which you can make the array a good, or say that this is not
possible.

Input
The first line contains a single integer t (1≤t≤1000) — the number of test cases in the test.
Then t test cases follow.

Each test case starts with a line containing an integer n (1≤n≤40) — the length of the array a.

The next line contains n integers a0,a1,…,an−1 (0≤ai≤1000) — the initial array.

Output
For each test case, output a single integer — the minimum number of moves to make the given array
a good, or -1 if this is not possible.
*/


#include <iostream>

using namespace std;


int main(){
    int tests;
    int length; // Array's length
    int even_num; // Number of even numbers in the array
    int not_in_place; // Number of even numbers that are not on the right place in the array


    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        cin >> length;
        int arr[length];

        not_in_place = even_num = 0;
        for (int j = 0; j < length; j++)
        {
            cin >> arr[j];

            if (arr[j] % 2 == 0)
            {
                even_num++;

                if (j % 2 == 1)
                {
                    not_in_place++;
                }
            }
        }

        // If the number of even numbers in the array isn't equal to the number of even numbers
        // in the sequence a[0, ..., length−1], the array can't be make good
        if (((length-1)/2 + 1) != even_num)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << not_in_place << endl;
        }
    }



    return 0;
}