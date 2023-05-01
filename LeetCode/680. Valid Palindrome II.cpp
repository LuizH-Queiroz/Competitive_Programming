/*
Given a string s, return true if the s can be palindrome after deleting at most one character from it.
*/


class Solution {
public:
    bool validPalindrome(string s) {
        
        for (int i = 0, j = s.size()-1; i < j; i++, j--)
        {
            if (s[i] != s[j])
                return (palindrome(s, i, j-1) || palindrome(s, i+1, j));
        }

        return true;
    }

    bool palindrome(string str, int start, int end) {

        for (int i = start, j = end; i < j; i++, j--)
        {
            if (str[i] != str[j])
                return false;
        }

        return true;
    }
};