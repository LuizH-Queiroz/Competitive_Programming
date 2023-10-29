/*
Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
Each vowel 'a' may only be followed by an 'e'.
Each vowel 'e' may only be followed by an 'a' or an 'i'.
Each vowel 'i' may not be followed by another 'i'.
Each vowel 'o' may only be followed by an 'i' or a 'u'.
Each vowel 'u' may only be followed by an 'a'.
Since the answer may be too large, return it modulo 10^9 + 7.
*/


class Solution {
public:

    long long mod = 1'000'000'007;

    int countVowelPermutation(int n) {
        long long a = 1, e = 1, i = 1, o = 1, u = 1;
        long long prevA = 1, prevE = 1, prevI = 1, prevO = 1, prevU = 1;


        for (int it = 1; it < n; it++)
        {
            a = (prevE) % mod;
            e = (prevA + prevI) % mod;
            i = (prevA + prevE + prevO + prevU) % mod;
            o = (prevI + prevU) % mod;
            u = (prevA) % mod;

            prevA = a;
            prevE = e;
            prevI = i;
            prevO = o;
            prevU = u;
        }

        return (a + e + i + o + u) % mod;
    }
};