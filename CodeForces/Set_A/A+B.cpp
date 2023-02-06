/*
You are given an expression of the form a+b, where a and b are integers from 0 to 9. You have to evaluate it and print the result.

Input
The first line contains one integer t (1≤t≤100) — the number of test cases.

Each test case consists of one line containing an expression of the form a+b (0≤a,b≤9, both a and b are integers).
The integers are not separated from the + sign.

Output
For each test case, print one integer — the result of the expression.
*/

#include <iostream>
#include <cstdio>

using namespace std;


int main()
{
    int tests;
    
    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        int num1, num2;
        
        getchar();
        num1 = getchar() - '0';
        getchar();
        num2 = getchar() - '0';
        
        cout << num1 + num2 << endl;
    }
    

    return 0;
}