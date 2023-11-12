/*
You will be given T (T<=10^6) pair of numbers.
All you have to tell is the number of common divisors between two numbers in each pair.

Input
First line of input: T (Number of test cases)
In next T lines, each have one pair A B (0 < A, B <= 10^6)

Output
One integer describing number of common divisors between two numbers.
*/
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    int tests;
    int v1, v2;


    cin >> tests;
    while(tests--)
    {
        cin >> v1 >> v2;

        int gcd = __gcd(v1, v2);
        int maxDiv = sqrt(gcd);
        int counter = 0;

        for (int i = 1; i <= maxDiv; i++)
        {
            if (gcd % i == 0)
            {
                if (i*i == gcd)
                    counter += 1;
                else
                    counter += 2;
            }
        }

        cout << counter << endl;
    }



    return 0;
}