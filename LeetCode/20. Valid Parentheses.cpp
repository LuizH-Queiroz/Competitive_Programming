/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.
*/


class Solution {
public:
    bool isValid(string s) {
        stack<char> open;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                open.push(s[i]);
            else if (!open.empty() && s[i] == ')' && open.top() == '(')
                open.pop();
            else if (!open.empty() && s[i] == ']' && open.top() == '[')
                open.pop();
            else if (!open.empty() && s[i] == '}' && open.top() == '{')
                open.pop();
            else
                return false;
        }

        return (open.size() == 0);
    }
};