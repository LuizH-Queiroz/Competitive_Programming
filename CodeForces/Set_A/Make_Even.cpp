/*
Polycarp has an integer n that doesn't contain the digit 0. He can do the following operation
with his number several (possibly zero) times:

Reverse the prefix of length l (in other words, l leftmost digits) of n. So, the leftmost digit
is swapped with the l-th digit from the left, the second digit from the left
swapped with (l−1)-th left, etc. For example, if n=123456789 and l=5, then the new value
of n will be 543216789.
Note that for different operations, the values of l can be different. The number l can be equal to
the length of the number n — in this case, the whole number n is reversed.

Polycarp loves even numbers. Therefore, he wants to make his number even. At the same time,
Polycarp is very impatient. He wants to do as few operations as possible.

Help Polycarp. Determine the minimum number of operations he needs to perform with the number n to
make it even or determine that this is impossible.

You need to answer t independent test cases.

Input
The first line contains the number t (1≤t≤104) — the number of test cases.

Each of the following t lines contains one integer n (1≤n<109). It is guaranteed that the
given number doesn't contain the digit 0.

Output
Print t lines. On each line print one integer — the answer to the corresponding test case.
If it is impossible to make an even number, print -1.
*/


#include <iostream>
#include <vector>

using namespace std;


bool IsEvenDigit(char digit);


int main(){
    int tests;
    vector<char> number;


    cin >> tests;
    cin.ignore();
    for (int i = 0; i < tests; i++)
    {
        int operations = -1;
        char c;
        while ((c = cin.get()) != '\n')
            number.push_back(c);


        if (IsEvenDigit(number.back())) operations = 0;
        else if (IsEvenDigit(number[0])) operations = 1;
        else
            for (int j = 1; j < number.size() - 1; j++)
            {
                if (IsEvenDigit(number[j])){
                    operations = 2;
                    break;
                }
            }


        cout << operations << endl;

        number.clear();
    }



    return 0;
}


bool IsEvenDigit(char digit){
    char even[] = "2468";

    for (int i = 0; i < 4; i++)
        if (digit == even[i]) return true;

    return false;
}