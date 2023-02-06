/*
You are given a positive integer n, it is guaranteed that n is even (i.e. divisible by 2).

You want to construct the array a of length n such that:

The first n2 elements of a are even (divisible by 2);
the second n2 elements of a are odd (not divisible by 2);
all elements of a are distinct and positive;
the sum of the first half equals to the sum of the second half (∑i=1n2ai=∑i=n2+1nai).
If there are multiple answers, you can print any. It is not guaranteed that the answer exists.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤104) — the number of test cases.
Then t test cases follow.

The only line of the test case contains one integer n (2≤n≤2⋅105) — the length of the array.
It is guaranteed that that n is even (i.e. divisible by 2).

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105 (∑n≤2⋅105).

Output
For each test case, print the answer — "NO" (without quotes), if there is no suitable answer
for the given test case or "YES" in the first line and any suitable array a1,a2,…,an (1≤ai≤109)
satisfying conditions from the problem statement on the second line.
*/


#include <iostream>

using namespace std;


int main(){
    int tests;
    int arr_size;


    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        cin >> arr_size;

        //To exist a suitable array, both half array sides must have an even quantity of numbers
        if (arr_size % 4 == 0){
            int j;
            cout << "YES" << endl;

            for (j = 1; j <= arr_size/2; j++)
            {
                cout << j * 2 << " ";
            }
            for (j = 1; j <= arr_size - 3; j += 2)
            {
                cout << j << " ";
            }
            cout << j + arr_size/2 << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }



    return 0;
}