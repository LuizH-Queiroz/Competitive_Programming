/*
Your task is to count the number of ways to construct sum n by throwing a dice one or more times.
Each throw produces an outcome between 1 and  6.
For example, if n=3, there are 4 ways:

1+1+1
1+2
2+1
3

Input
The only input line has an integer n.

Output
Print the number of ways modulo 10^9+7.

Constraints

1 <= n <= 10^6
*/
#include <bits/stdc++.h>

#define endl '\n'

typedef long long ll;

ll mod = 1'000'000'007;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    int n;
    vector<ll> dp;


    cin >> n;

    dp.resize(n+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6 && i-j >= 0; j++)
        {
            dp[i] = (dp[i] + dp[i-j]) % mod;
        }
    }
    cout << dp[n] << endl;


    return 0;
}