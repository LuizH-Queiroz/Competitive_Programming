/*
You have a positive integer m and a non-negative integer s.
Your task is to find the smallest and the largest of the numbers that have length m and sum of digits s.
The required numbers should be non-negative integers written in the decimal base without leading zeroes.
Input

The single line of the input contains a pair of integers m, s (1 ≤ m ≤ 100, 0 ≤ s ≤ 900) — the length and the sum of the digits of the required numbers.
Output

In the output print the pair of the required non-negative integer numbers — first the minimum possible number, then — the maximum possible number.
If no numbers satisfying conditions required exist, print the pair of numbers "-1 -1" (without the quotes).
*/
#include <iostream>
#include <string>

using namespace std;



int main() {
    int length, sum;
    string largest, smallest;
    int smallest_sum, largest_sum;
    int aux;


    cin >> length >> sum;
    if (length == 1 && sum == 0)
    {
        cout << "0 0" << endl;
        return 0;
    }
    
    largest.resize(length, '0');
    largest[0] = '1';

    smallest.resize(length, '0');
    smallest[0] = '1';

    smallest_sum = largest_sum = sum-1;


    for (int i = 0; i < length && largest_sum > 0; i++)
    {
        aux = min((int) ('9' - largest[i]), largest_sum);
        largest[i] += aux;
        largest_sum -= aux;
    }

    for (int i = length-1; i >= 0 && smallest_sum > 0; i--)
    {
        aux = min((int) ('9' - smallest[i]), smallest_sum);
        smallest[i] += aux;
        smallest_sum -= aux;
    }

    if (smallest_sum == 0 && largest_sum == 0)
        cout << smallest << " " << largest << endl;
    else
        cout << -1 << " " << -1 << endl;


    return 0;
}