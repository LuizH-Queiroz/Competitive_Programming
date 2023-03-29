/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters,
it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
*/


class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;

        while(left < right)
        {
            while(left < right && !isalnum(s[left]))
                left++;
            
            while(left < right && !isalnum(s[right]))
                right--;
            
            if (tolower(s[left++]) != tolower(s[right--]))
                return false;
        }

        return true;
    }
};