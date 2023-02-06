/*
Let's call a permutation p of length n anti-Fibonacci if the condition pi−2+pi−1≠pi holds for
all i (3≤i≤n). Recall that the permutation is the array of length n which contains each integer
from 1 to n exactly once.

Your task is for a given number n print n distinct anti-Fibonacci permutations of length n.

Input
The first line contains a single integer t (1≤t≤48) — the number of test cases.

The single line of each test case contains a single integer n (3≤n≤50).

Output
For each test case, print n lines. Each line should contain an anti-Fibonacci permutation of
length n. In each test case, you cannot print any permutation more than once.

If there are multiple answers, print any of them. It can be shown that it is always possible
to find n different anti-Fibonacci permutations of size n under the constraints of the problem.
*/


#include <iostream>

using namespace std;


void PrintSequence(int arr[], int length);


int main(){
    int tests;

    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        int permutations;

        cin >> permutations;
        int anti_fib[permutations];
        for (int j = 1; j <= permutations; j++)
        {
            anti_fib[j-1] = permutations - (j - 1);
        }

        for (int j = 1; j < permutations; j++)
        {
            PrintSequence(anti_fib, permutations);

            int tmp = anti_fib[permutations - j];
            anti_fib[permutations - j] = anti_fib[permutations - (j+1)];
            anti_fib[permutations - (j+1)] = tmp;
        }
        PrintSequence(anti_fib, permutations);
    }



    return 0;
}


void PrintSequence(int arr[], int length){

    for (int i = 0; i < length; i++)
    {
        cout << arr[i];

        if (i != length-1) cout << " ";
        else cout << endl;
    }
}