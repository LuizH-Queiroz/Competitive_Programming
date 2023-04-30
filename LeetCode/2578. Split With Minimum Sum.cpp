/*
Given a positive integer num, split it into two non-negative integers num1 and num2 such that:

    The concatenation of num1 and num2 is a permutation of num.
        In other words, the sum of the number of occurrences of each digit in num1 and num2 is equal to the number of occurrences of that digit in num.
    num1 and num2 can contain leading zeros.

Return the minimum possible sum of num1 and num2.

Notes:

    It is guaranteed that num does not contain any leading zeros.
    The order of occurrence of the digits in num1 and num2 may differ from the order of occurrence of num.

*/


class Solution {
public:
    int splitNum(int num) {
        vector<int> digits;

        while(num > 0)
        {
            digits.push_back(num % 10);
            num = num / 10;
        }
        sort(digits.begin(), digits.end());

        int sum = 0;
        int power = 1;
        for (int i = digits.size()-1; i >= 0; i -= 2)
        {
            if ((i-1) >= 0)
                sum += (digits[i] + digits[i-1]) * power;
            else
                sum += digits[i] * power;
            
            power *= 10;
        }

        return sum;
    }
};